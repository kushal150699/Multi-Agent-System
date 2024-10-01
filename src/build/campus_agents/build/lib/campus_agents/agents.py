import rclpy
from rclpy.node import Node
import random
from campus_tour_interfaces.msg import NavigationPath, AccessDenied, OutOfService, VisitorArrival, OutOfService
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import logging
import threading
import time
from rclpy.timer import Timer
from rclpy.duration import Duration
import queue

# Set up logging
logging.basicConfig(filename='campus_tour.log', level=logging.INFO, 
                    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')

class CampusGraph:
    def __init__(self):
        self.G = nx.Graph()
        self.G.add_nodes_from(['Entrance', 'B1', 'B2', 'B3', 'B4'])
        self.G.add_edges_from([
            ('Entrance', 'B1'), 
            ('Entrance', 'B4'),
            ('B1', 'B2'), 
            ('B2', 'B3'), 
            ('B3', 'B4'),
            ('B4', 'B1')
        ])
        self.pos = nx.spring_layout(self.G)
        self.building_incharge = {'B1': 'BI1', 'B2': 'BI2', 'B3': 'BI3', 'B4': 'BI4'}
        self.hosts = {'B1': 'H1', 'B2': 'H2', 'B3': 'H3', 'B4': 'H4'}
        
    def visualize(self, ax):
        ax.clear()
        nx.draw(self.G, self.pos, ax=ax, with_labels=True, node_color='lightblue', node_size=500, font_size=10, font_weight='bold')
        ax.set_title("Campus Map")
        for building, incharge in self.building_incharge.items():
            ax.annotate(f"Incharge: {incharge}", xy=self.pos[building], xytext=(0, 30), 
                        textcoords="offset points", ha='center', va='bottom')
        for building, host in self.hosts.items():
            ax.annotate(f"Host: {host}", xy=self.pos[building], xytext=(0, 15), 
                        textcoords="offset points", ha='center', va='bottom')

class BuildingGraph:
    def __init__(self):
        self.G = nx.Graph()
        self.G.add_nodes_from(['Entrance','Room1', 'Room2', 'Room3'])
        self.G.add_edges_from([
            ('Entrance', 'Room1'),
            ('Room1', 'Room2'),
            ('Room2', 'Room3'),
            ('Room3', 'Entrance')
        ])
        self.pos = nx.spring_layout(self.G)
        self.hosts = {"Entrance":"BI","Room3":"H1"}

    def visualize(self, ax):
        ax.clear()
        nx.draw(self.G, self.pos, ax=ax, with_labels=True, node_color='lightgreen', node_size=500, font_size=10, font_weight='bold')
        ax.set_title("Building Map")
        for room, host in self.hosts.items():
            ax.annotate(f"Host: {host}", xy=self.pos[room], xytext=(0, 15), 
                        textcoords="offset points", ha='center', va='bottom')
        
class CIAgent(Node):
    def __init__(self, ci_id, campus_graph, building_graph):
        super().__init__(f'ci_agent{ci_id}')
        self.ci_id = ci_id
        self.campus_graph = campus_graph
        self.building_graph = building_graph
        self.position = 'Entrance'
        self.building_position = 'Entrance'
        self.host_path = None
        self.bi_se_sub = self.create_subscription(NavigationPath, "/bi_agent/navigation_response", self.visitHost, 10)
        self.bi_ko_pub = self.create_publisher(VisitorArrival, "/ci_agent/navigation_request", 10)
        self.visitor_ko_sub = self.create_subscription(VisitorArrival, "/vi_agent/visitor_request", self.Next, 10)
        self.logger = logging.getLogger(f'CIAgent_{ci_id}')

        self.is_available = True
        self.current_visitor = None
        
        self.Tcb = 0  # Time from campus entrance to building/BI Agent
        self.Tbh = 0  # Time from building entrance to Host location
        self.Tvh = 0  # Time for visitor - host meet
        self.Tbih = 0  # Time for bi agent - host meet
        self.Tvw = 30  # Visitor wait time (example value, adjust as needed)
        self.start_time = None
        self.end_time = None
        self.is_available = True
        self.violation_count = 0
        self.is_violation = False
        self.total_time = 0

    def start_trip(self):
        self.start_time = time.time()
        self.is_available = False

    def end_trip(self):
        self.end_time = time.time()
        self.is_available = True
        self.calculate_total_time()
        self.is_available = True
        self.current_visitor = None

    def calculate_total_time(self):
        self.total_time = self.end_time - self.start_time
        if self.total_time > self.Tvw:
            self.violation_count += 1
            self.is_violation = True

    def visitHost(self, response: NavigationPath):
        self.host_path = response.path
        # We'll log this message later, after movement is complete

    def Next(self, msg: VisitorArrival):
        if self.is_available:
            self.current_visitor = msg.visitor_id
            self.is_available = False
            log_message = f"Campus Agent {self.ci_id} met Visitor {msg.visitor_id} to visit host {msg.host_id} present at building {msg.building_id}"
            self.get_logger().info(log_message)
            self.logger.info(log_message)
            self.bi_ko_pub.publish(msg)
        else:
            log_message = f"Campus Agent {self.ci_id} is currently unavailable. Visitor {msg.visitor_id} must wait."
            self.get_logger().info(log_message)
            self.logger.info(log_message)

    # def end_trip(self):
    #     self.end_trip()
    #     self.is_available = True
    #     self.current_visitor = None

    def move_to(self, new_position):
        path = nx.shortest_path(self.campus_graph.G, source=self.position, target=new_position)
        for step in path[1:]:
            log_message = f"CI Agent {self.ci_id} moved from {self.position} to {step}"
            self.get_logger().info(log_message)
            self.logger.info(log_message)
            self.position = step
            time.sleep(1)  # Simulate time delay for each step

    def move_in_building(self, new_position):
        path = nx.shortest_path(self.building_graph.G, source=self.building_position, target=new_position)
        for step in path[1:]:
            log_message = f"CI Agent {self.ci_id} moved from {self.building_position} to {step} in the building"
            self.get_logger().info(log_message)
            self.logger.info(log_message)
            self.building_position = step
            time.sleep(1)  # Simulate time delay for each step

class BIAgent(Node):
    def __init__(self, bi_id):
        super().__init__(f'bi_agent{bi_id}')
        self.bi_id = bi_id
        self.ci_se_sub = self.create_subscription(VisitorArrival, "/ci_agent/navigation_request", self.callback, 10)
        self.ci_ko_pub = self.create_publisher(NavigationPath, "/bi_agent/navigation_response", 10)
        self.ci_ko_denial_pub = self.create_publisher(AccessDenied, "/bi_agent/access_denied", 10)
        self.oos_pub = self.create_publisher(OutOfService, "/bi_agent/out_of_service", 10)
        self.logger = logging.getLogger(f'BIAgent_{bi_id}')
        self.host_status = {
            "H1": 'available',
            "H2": 'available',
            "H3": 'available',
            "H4": 'available'
        }
        self.unauthorized_visitors = {
            "H1":['V3'],
            "H2":['V1'],
            "H3":['V2']

        }
        self.host_path = {
            "H1":['Entrance', 'Room1', 'Room2', 'Room3'],
            "H2":['Entrance', 'Room1', 'Room2'],
            "H3":['Entrance', 'Room1']
        }
        self.reason = None
        self.timerrs = {}
        self.availability_times = {}
        self.is_oos = False
        self.oos_duration = random.randint(10,30)
        self.committed_duration = 20
        self.bi_violation_cnt = 0
        self.visit_duration = 20

    def callback(self, msg: VisitorArrival):
        host_id = msg.host_id
        visitor_id = msg.visitor_id
        visitor_position = msg.visitor_position

        if self.is_oos:
            denial_msg = AccessDenied()
            denial_msg.visitor_id = visitor_id
            denial_msg.reason = f"BI Agent {self.bi_id} is currently out of service"
            self.ci_ko_denial_pub.publish(denial_msg)
            return

        if host_id == self.bi_id:
            # Special case: Visitor wants to meet the BI agent
            self.handle_self_hosting(visitor_id)
        elif self.host_status[host_id] == 'unavailable':
            # If host is unavailable, deny access
            denial_msg = AccessDenied()
            denial_msg.visitor_id = visitor_id
            denial_msg.reason = f"Host {host_id} is currently unavailable"
            self.ci_ko_denial_pub.publish(denial_msg)
            self.reason = "Host unavailable"
        elif visitor_id in self.unauthorized_visitors.get(host_id, []):
            # If visitor is unauthorized, deny access
            denial_msg = AccessDenied()
            denial_msg.visitor_id = visitor_id
            denial_msg.reason = f"Visitor {visitor_id} is not authorized to visit {host_id}"
            self.ci_ko_denial_pub.publish(denial_msg)
            self.reason = "Not Authorized"
        else:
            # If visitor is authorized, proceed with navigation and mark host unavailable
            self.process_authorized_visit(host_id, visitor_id)

    def handle_self_hosting(self, visitor_id):
        self.is_oos = True
        oos_msg = OutOfService()
        oos_msg.bi_id = self.bi_id
        oos_msg.duration = self.oos_duration
        self.oos_pub.publish(oos_msg)

        # Set a timer to become available again
        self.timeer = self.create_timer(self.oos_duration, self.end_oos)

        # Provide navigation path to the BI agent's location
        response = NavigationPath()
        response.visitor_id = visitor_id
        response.host_id = self.bi_id
        response.path = ['Entrance']  # Adjust this path as needed
        self.ci_ko_pub.publish(response)

    def end_oos(self):
        self.is_oos = False
        self.get_logger().info(f"BI Agent {self.bi_id} is now back in service")
        self.timeer.cancel()
        del self.timeer

    def process_authorized_visit(self, host_id, visitor_id):
        response = NavigationPath()
        response.visitor_id = visitor_id
        response.host_id = host_id
        response.path = self.host_path[host_id]
        self.ci_ko_pub.publish(response)
        
        # Mark host as unavailable
        self.host_status[host_id] = 'unavailable'
        current_time = self.get_clock().now()
    
        # Start a timer to make the host available again after 30 seconds
        if host_id in self.timerrs:
            self.timerrs[host_id].cancel()
        self.availability_times[host_id] = current_time + Duration(seconds=self.visit_duration)
        self.timerrs[host_id] = self.create_timer(0.1, lambda: self.check_host_availability(host_id))

    def check_host_availability(self, host_id):
        current_time = self.get_clock().now()
        if current_time >= self.availability_times[host_id]:
            self.make_host_available(host_id)

    def make_host_available(self, host_id):
        self.host_status[host_id] = 'available'
        self.get_logger().info(f"Host {host_id} is now available again.")
        if host_id in self.timerrs:
            self.timerrs[host_id].cancel()
            del self.timerrs[host_id]
        if host_id in self.availability_times:
            del self.availability_times[host_id]

class VisitorAgent(Node):
    def __init__(self, host_id, visitor_id, building_id, campus_graph, building_graph):
        super().__init__(f'vi_agent{visitor_id}')
        self.host_id = host_id
        self.building_id = building_id
        self.visitor_id = visitor_id
        self.campus_graph = campus_graph
        self.building_graph = building_graph
        self.position = 'Entrance'
        self.building_position = 'Entrance'
        self.visitor_pub = self.create_publisher(VisitorArrival, "/vi_agent/visitor_request", 10)
        self.logger = logging.getLogger(f'VisitorAgent_{visitor_id}')
        self.ci_id = None  # Will be assigned when a CI agent is available

    def meet_host(self):
        msg = VisitorArrival()
        msg.host_id = self.host_id
        msg.visitor_id = self.visitor_id
        msg.building_id = self.building_id
        msg.visitor_position = self.position

        self.visitor_pub.publish(msg)
        log_message = f"Visitor {self.visitor_id} requested to visit host {self.host_id} present at building {self.building_id}"
        self.get_logger().info(log_message)
        self.logger.info(log_message)

    def move_to(self, new_position):
        path = nx.shortest_path(self.campus_graph.G, source=self.position, target=new_position)
        for step in path[1:]:
            log_message = f"Visitor {self.visitor_id} moved from {self.position} to {step}"
            self.get_logger().info(log_message)
            self.logger.info(log_message)
            self.position = step
            time.sleep(1)  # Simulate time delay for each step

    def move_in_building(self, new_position):
        path = nx.shortest_path(self.building_graph.G, source=self.building_position, target=new_position)
        for step in path[1:]:
            log_message = f"Visitor {self.visitor_id} moved from {self.building_position} to {step} in the building"
            self.get_logger().info(log_message)
            self.logger.info(log_message)
            self.building_position = step
            time.sleep(1)  # Simulate time delay for each step

def animate_campus(frame, visitors, ci_agent, campus_graph, ax, movement_queue):
    if not movement_queue.empty():
        location, positions = movement_queue.get()
        
        # Ensure the 'visitors' key exists and contains a dictionary
        if 'visitors' in positions:
            visitors_positions = positions['visitors']
            for visitor, pos in visitors_positions.items():
                # This will correctly update the visitor's position
                visitor.position = pos

        # Ensure the 'ci' key exists and update CI agent position
        if 'ci' in positions:
            ci_agent.position = positions['ci']

    # Clear the axis for fresh plotting
    ax.clear()
    campus_graph.visualize(ax)

    # Plot visitor agents
    for visitor in visitors:
        ax.plot(*campus_graph.pos[visitor.position], 'ro')  # 'ro' for red circles representing visitors
        ax.annotate(f"V: {visitor.visitor_id}", 
                    xy=campus_graph.pos[visitor.position], 
                    xytext=(0, -30),  
                    textcoords="offset points", ha='center', va='top')
    
    # Plot CI agent
    ax.plot(*campus_graph.pos[ci_agent.position], 'go')  # 'go' for green circle representing CI agent
    ax.annotate(f"CI: {ci_agent.ci_id}", 
                xy=campus_graph.pos[ci_agent.position], 
                xytext=(0, -50),  
                textcoords="offset points", ha='center', va='top')


def animate_building(frame, visitors, ci_agent, building_id, building_graph, ax, movement_queue):
    if not movement_queue.empty():
        location, positions = movement_queue.get()
        if location == 'building':
            for visitor, pos in positions['visitors'].items():
                visitor.building_position = pos
            ci_agent.building_position = positions['ci']

    ax.clear()
    building_graph.visualize(ax)

    for visitor in visitors:
        if visitor.building_position and ci_agent.building_position and (visitor.position == building_id):
            # Plot visitor agent
            ax.plot(*building_graph.pos[visitor.building_position], 'ro')
            ax.annotate(f"V: {visitor.visitor_id}", 
                        xy=building_graph.pos[visitor.building_position], 
                        xytext=(0, -30),  
                        textcoords="offset points", ha='center', va='top')
    
    # Plot CI agent
    if ci_agent.building_position:
        ax.plot(*building_graph.pos[ci_agent.building_position], 'go')
        ax.annotate(f"CI: {ci_agent.ci_id}", 
                    xy=building_graph.pos[ci_agent.building_position], 
                    xytext=(0, -50),  
                    textcoords="offset points", ha='center', va='top')

def ros2_spin(executor):
    executor.spin()

def backtrack(vi, ci, path, movement_queue, is_building):
    for step in reversed(path[:]):  # Skip the last position as they're already there
        if is_building:
            ci.move_in_building(step)
            vi.move_in_building(step)
            movement_queue.put(('building', (vi.building_position, ci.building_position)))
        else:
            ci.move_to(step)
            vi.move_to(step)
            movement_queue.put(('campus', (vi.position, ci.position)))
        time.sleep(1)

    if is_building:
        # Signal that they've left the building
        movement_queue.put(('building', ('', '')))
        log_message = f"Visitor {vi.visitor_id} and CI Agent {ci.ci_id} have left the building"
        vi.get_logger().info(log_message)
        vi.logger.info(log_message)

def simulate_movement(visitors, ci, bi, movement_queue):
    for vi in visitors:
        if not ci.is_available:
            log_message = f"CI Agent {ci.ci_id} is not available. Visitor {vi.visitor_id} must wait."
            vi.get_logger().info(log_message)
            vi.logger.info(log_message)
            continue

        ci.start_trip()
        vi.ci_id = ci.ci_id  # Assign CI agent to visitor
        time.sleep(2)

        # Move to the correct building
        path = nx.shortest_path(vi.campus_graph.G, source=vi.position, target=vi.building_id)
        for step in path[1:]:
            ci.move_to(step)
            vi.move_to(step)
            movement_queue.put(('campus', {'visitors': {vi: vi.position}, 'ci': ci.position}))
            time.sleep(1)
        
        ci.Tcb = time.time() - ci.start_time

        # Check authorization and host availability
        if vi.visitor_id in bi.unauthorized_visitors.get(vi.host_id, []):
            log_message = f"Access Denied: Visitor {vi.visitor_id} is not authorized to visit {vi.host_id}"
            ci.get_logger().info(log_message)
            ci.logger.info(log_message)
        elif bi.host_status[vi.host_id] == 'unavailable':
            log_message = f"Access Denied: Host {vi.host_id} is currently unavailable"
            ci.get_logger().info(log_message)
            ci.logger.info(log_message)
        else:
            # Proceed with the visit
            bi.process_authorized_visit(vi.host_id, vi.visitor_id)
            
            # Move through the building
            building_path = bi.host_path[vi.host_id]
            building_start_time = time.time()
            for step in building_path[1:]:
                ci.move_in_building(step)
                vi.move_in_building(step)
                movement_queue.put(('building', {'visitors': {vi: vi.building_position}, 'ci': ci.building_position}))
                time.sleep(1)
            
            ci.Tbh = time.time() - building_start_time

            log_message = f"Visitor {vi.visitor_id} meeting host {vi.host_id}. Host Unavailable for {bi.visit_duration} seconds"
            ci.get_logger().info(log_message)
            ci.logger.info(log_message)

            ci.Tvh = bi.visit_duration
            time.sleep(bi.visit_duration)

            # Move back through the building
            for step in reversed(building_path[1:]):
                ci.move_in_building(step)
                vi.move_in_building(step)
                movement_queue.put(('building', {'visitors': {vi: vi.building_position}, 'ci': ci.building_position}))
                time.sleep(1)

        # Move back to the campus entrance
        path = nx.shortest_path(vi.campus_graph.G, source=vi.building_id, target='Entrance')
        for step in path[1:]:
            ci.move_to(step)
            vi.move_to(step)
            movement_queue.put(('campus', {'visitors': {vi: vi.position}, 'ci': ci.position}))
            time.sleep(1)

        ci.end_trip()

        log_message = f"Visitor {vi.visitor_id} and CI Agent {ci.ci_id} have returned to the campus entrance"
        vi.get_logger().info(log_message)
        vi.logger.info(log_message)

        if ci.is_violation:
            log_message = f"CI Agent {ci.ci_id} generated a violation. Total time: {ci.total_time:.2f}s, Tvw: {ci.Tvw}s"
            ci.get_logger().info(log_message)
            ci.logger.info(log_message)
        else:
            log_message = f"CI Agent {ci.ci_id} completed the trip within the allowed time. Total time: {ci.total_time:.2f}s, Tvw: {ci.Tvw}s"
            ci.get_logger().info(log_message)
            ci.logger.info(log_message)

def main():
    rclpy.init()
    
    campus_graph = CampusGraph()
    building_graph = BuildingGraph()
    
    # Create multiple visitors with random assignments
    visitors = []
    for i in range(3):
        host_id = f"H{random.randint(1, 4)}"
        visitor_id = f"V{i+1}"
        building_id = f"B{random.randint(1, 4)}"
        visitors.append(VisitorAgent(host_id, visitor_id, building_id, campus_graph, building_graph))
    
    ci_id = "C1"
    bi_id = "BI1"
    
    ci = CIAgent(ci_id, campus_graph, building_graph)
    bi = BIAgent(bi_id)
    
    executor = rclpy.executors.MultiThreadedExecutor()
    for visitor in visitors:
        executor.add_node(visitor)
    executor.add_node(ci)
    executor.add_node(bi)

    # Start ROS 2 spinning in a separate thread
    ros2_thread = threading.Thread(target=ros2_spin, args=(executor,))
    ros2_thread.start()

    # Create a queue for movement
    movement_queue = queue.Queue()

    # Start movement simulation in a separate thread
    movement_thread = threading.Thread(target=simulate_movement, args=(visitors, ci, bi, movement_queue))
    movement_thread.start()

    # Visualization setup for campus
    fig_campus, ax_campus = plt.subplots(figsize=(10, 8))
    anim_campus = FuncAnimation(fig_campus, animate_campus, frames=100, 
                                fargs=(visitors, ci, campus_graph, ax_campus, movement_queue), 
                                interval=500, repeat=True)

    # Visualization setup for building
    fig_building, ax_building = plt.subplots(figsize=(10, 8))
    anim_building = FuncAnimation(fig_building, animate_building, frames=100, 
                                  fargs=(visitors, ci, building_graph, ax_building, movement_queue), 
                                  interval=500, repeat=True)

    plt.show()

    # Wait for threads to finish
    movement_thread.join()
    ros2_thread.join()

    for visitor in visitors:
        visitor.destroy_node()
    ci.destroy_node()
    bi.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()