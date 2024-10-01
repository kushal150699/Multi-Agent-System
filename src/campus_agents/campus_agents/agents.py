import rclpy
from rclpy.node import Node
import random
from campus_tour_interfaces.msg import NavigationPath, AccessDenied, OutOfService, VisitorArrival
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import logging
import threading
import time
from rclpy.timer import Timer
from rclpy.duration import Duration
import queue
import numpy as np
import seaborn as sns
from matplotlib.colors import LinearSegmentedColormap
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup

logging.basicConfig(filename='campus_tour.log', level=logging.INFO, 
                    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')

class TransportMode:
    VEHICLE = 'vehicle'
    CYCLE = 'cycle'
    WALK = 'walk'

class CampusGraph:
    def __init__(self, building_hosts_mapping, building_bi_mapping):
        self.G = nx.Graph()
        self.G.add_nodes_from(['Entrance', 'B1', 'B2', 'B3', 'B4'])
        self.G.add_edges_from([
            ('Entrance', 'B1', {'weight': 2}), 
            ('Entrance', 'B4', {'weight': 2}),
            ('B1', 'B2', {'weight': 2}), 
            ('B2', 'B3', {'weight': 2}), 
            ('B3', 'B4', {'weight': 2}),
            ('B4', 'B1', {'weight': 2})
        ])
        self.pos = nx.spring_layout(self.G)
        self.building_incharge = building_bi_mapping
        self.hosts = building_hosts_mapping
 
class BuildingGraph:
    def __init__(self, building_id, hosts_location):
        self.building_id = building_id
        self.G = nx.Graph()
        self.G.add_nodes_from(['Entrance', 'Room1', 'Room2', 'Room3'])
        self.G.add_edges_from([
            ('Entrance', 'Room1'),
            ('Room1', 'Room2'),
            ('Room2', 'Room3'),
            ('Room3', 'Entrance')
        ])
        self.pos = nx.spring_layout(self.G)
        self.hosts = hosts_location

class CampusManager:
    def __init__(self, building_hosts_mapping, building_bi_mapping):
        self.campus_graph = CampusGraph(building_hosts_mapping, building_bi_mapping)
        self.building_graphs = {}
        self.create_building_graphs()

    def create_building_graphs(self):
        building_host_mappings = {
            'B1': {"Entrance": "BI1", "Room1": "H1", "Room2": "H2", "Room3": "H3"},
            'B2': {"Entrance": "BI2", "Room1": "H4", "Room2": "H5", "Room3": "H6"},
            'B3': {"Entrance": "BI3", "Room1": "H7", "Room2": "H8", "Room3": "H9"},
            'B4': {"Entrance": "BI4", "Room1": "H10", "Room2": "H11", "Room3": "H12"}
        }
        
        for building_id, hosts_location in building_host_mappings.items():
            self.building_graphs[building_id] = BuildingGraph(building_id, hosts_location)

    def get_building_graph(self, building_id):
        return self.building_graphs.get(building_id)

class CIAgent(Node):
    def __init__(self, ci_id, campus_graph, campus_manager):
        super().__init__(f'ci_agent{ci_id}')
        self.ci_id = ci_id
        self.campus_manager = campus_manager
        self.position = 'Entrance'
        self.building_position = 'Entrance'
        self.current_building = None
        self.host_path = None
        self.transport_mode = TransportMode.WALK
        self.bi_se_sub = self.create_subscription(NavigationPath, "/bi_agent/navigation_response", self.visitHost, 10)
        self.bi_ko_pub = self.create_publisher(VisitorArrival, "/ci_agent/navigation_request", 10)
        self.visitor_ko_sub = self.create_subscription(VisitorArrival, "/vi_agent/visitor_request", self.Next, 10)
        self.logger = logging.getLogger(f'CIAgent_{ci_id}')
        self.campus_graph = campus_graph
        self.visitor_host_meet_time = 0
        self.visitor_wait_time = 100
        self.start_time = None
        self.end_time = None
        self.is_available = True
        self.violation_count = 0
        self.is_violation = False
        self.total_time = 0
        self.step_in_building = 2
        self.visitors_entertained = 0
        self.total_violation_time = 0
        self.performance_score = 0

    def set_transport_mode(self, mode):
        self.transport_mode = mode

    def get_travel_time(self, distance):
        if self.transport_mode == TransportMode.VEHICLE:
            return distance
        elif self.transport_mode == TransportMode.CYCLE:
            return distance * 5
        else:  
            return distance * 10

    def move_on_campus(self, new_position):
        path = nx.shortest_path(self.campus_graph.G, source=self.position, target=new_position, weight='weight')
        for step in path[1:]:
            distance = self.campus_graph.G[self.position][step]['weight']
            travel_time = self.get_travel_time(distance)
            log_message = f"CI Agent {self.ci_id} moved from {self.position} to {step} using {self.transport_mode} in {travel_time} time units"
            self.get_logger().info(log_message)
            self.logger.info(log_message)
            self.position = step
            time.sleep(travel_time)

    def move_in_building(self, new_position):
        if self.current_building:
            path = nx.shortest_path(self.current_building.G, source=self.building_position, target=new_position)
            for step in path[1:]:
                log_message = f"CI Agent {self.ci_id} moved from {self.building_position} to {step} in building {self.current_building.building_id}"
                self.get_logger().info(log_message)
                self.logger.info(log_message)
                self.building_position = step
                time.sleep(self.step_in_building)

    def visitHost(self, response: NavigationPath):
        self.host_path = response.path

    def Next(self, msg: VisitorArrival):
        log_message = f"Campus Agent {msg.ci_id} met Visitor {msg.visitor_id} to visit host {msg.host_id} present at building {msg.building_id}"
        self.get_logger().info(log_message)
        self.logger.info(log_message)
        self.bi_ko_pub.publish(msg)

    def start_trip(self):
        self.start_time = time.time()
        self.is_available = False

    def end_trip(self):
        self.end_time = time.time()
        self.is_available = True
        self.calculate_total_time()
        self.visitors_entertained += 1
        self.update_performance_score()

    def calculate_total_time(self):
        self.total_time = self.end_time - self.start_time
        if self.total_time > self.visitor_wait_time:
            self.violation_count += 1
            self.is_violation = True
            self.total_violation_time += (self.total_time - self.visitor_wait_time)

    def update_performance_score(self):
        self.performance_score = self.visitors_entertained * 10 - self.violation_count * 5 

class BIAgent(Node):
    def __init__(self, bi_id, hosts_status, unauthorized_visitors, hosts_path):
        super().__init__(f'bi_agent{bi_id}')
        self.bi_id = bi_id
        self.ci_se_sub = self.create_subscription(VisitorArrival, "/ci_agent/navigation_request", self.callback, 10)
        self.ci_ko_pub = self.create_publisher(NavigationPath, "/bi_agent/navigation_response", 10)
        self.ci_ko_denial_pub = self.create_publisher(AccessDenied, "/bi_agent/access_denied", 10)
        self.oos_pub = self.create_publisher(OutOfService, "/bi_agent/out_of_service", 10)
        self.logger = logging.getLogger(f'BIAgent_{bi_id}')
        self.host_status = hosts_status
        self.unauthorized_visitors = unauthorized_visitors
        self.hosts_path = hosts_path
        self.reason = None
        self.timerrs = {}
        self.availability_times = {}
        self.is_oos = False
        self.oos_duration = random.randint(10,30)
        self.committed_duration = 20
        self.bi_violation_cnt = 0
        self.visit_duration = random.randint(5,30)
        self.pending_visitors = {}
        self.access_granted = {} 
        self.building_to_host_duration = 0
        self.step_in_building = 2
        self.ci_agents_guided = 0
        self.oos_violations = 0
        self.performance_score = 0
    
    def end_oos(self):
        self.is_oos = False
        self.get_logger().info(f"BI Agent {self.bi_id} is now back in service")
        self.timeer.cancel()
        del self.timeer
  
        actual_oos_duration = time.time() - self.oos_start_time
        if (actual_oos_duration - self.committed_duration) > 0:  
            self.oos_violations += 1
            self.get_logger().warn(f"BI Agent {self.bi_id} violated OOS duration. Expected: {self.committed_duration}, Actual: {actual_oos_duration:.2f}")

    def handle_self_hosting(self, visitor_id):
        self.is_oos = True
        self.oos_start_time = time.time()
        oos_msg = OutOfService()
        oos_msg.bi_id = self.bi_id
        oos_msg.duration = self.oos_duration
        self.oos_pub.publish(oos_msg)
        self.timeer = self.create_timer(self.oos_duration, self.end_oos)
        response = NavigationPath()
        response.visitor_id = visitor_id
        response.host_id = self.bi_id
        response.path = ['Entrance']  
        self.ci_ko_pub.publish(response)
        self.ci_agents_guided += 1

    def callback(self, msg: VisitorArrival):
        self.pending_visitors[msg.visitor_id] = msg
    
    def check_visitor_access(self, visitor_id):
        if visitor_id not in self.pending_visitors:
            self.get_logger().warn(f"No pending visit request for visitor {visitor_id}")
            return False, "No pending visit request"
        
        msg = self.pending_visitors[visitor_id]
        host_id = msg.host_id

        if self.is_oos:
            reason = f"BI Agent {self.bi_id} is currently out of service"
            self.deny_access(visitor_id, reason)
            return False, reason

        if host_id == self.bi_id:
            self.handle_self_hosting(visitor_id)
            self.access_granted[visitor_id] = True
            return True, "Access granted for self-hosting"
        elif self.host_status[host_id] == 'unavailable':
            reason = f"Host {host_id} is currently unavailable"
            self.deny_access(visitor_id, reason)
            return False, reason
        elif visitor_id in self.unauthorized_visitors.get(host_id, []):
            reason = f"Visitor {visitor_id} is not authorized to visit {host_id}"
            self.deny_access(visitor_id, reason)
            return False, reason
        else:
            self.process_authorized_visit(host_id, visitor_id)
            self.access_granted[visitor_id] = True
            return True, "Access granted"

    def deny_access(self, visitor_id, reason):
        denial_msg = AccessDenied()
        denial_msg.visitor_id = visitor_id
        denial_msg.reason = reason
        self.ci_ko_denial_pub.publish(denial_msg)
        self.get_logger().info(f"Access denied for visitor {visitor_id}: {reason}")

    def process_authorized_visit(self, host_id, visitor_id):
        response = NavigationPath()
        response.visitor_id = visitor_id
        response.host_id = host_id
        response.path = self.hosts_path[host_id]
        self.ci_ko_pub.publish(response)
        self.host_status[host_id] = 'unavailable'
        current_time = self.get_clock().now()

        if response.path[-1] == "Room1":
            self.building_to_host_duration = self.step_in_building * 2
        elif response.path[-1] == "Room2":
            self.building_to_host_duration = self.step_in_building * 4
        else:
            self.building_to_host_duration = self.step_in_building * 6
    
        if host_id in self.timerrs:
            self.timerrs[host_id].cancel()

        self.availability_times[host_id] = current_time + Duration(seconds=self.visit_duration) + Duration(seconds=self.building_to_host_duration)
        self.timerrs[host_id] = self.create_timer(0.1, lambda: self.check_host_availability(host_id))
        self.ci_agents_guided += 1

    def update_performance_score(self):
        self.performance_score = self.ci_agents_guided * 10 - self.oos_violations * 5

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
    def __init__(self, host_id, visitor_id, ci_id, building_id, campus_graph, campus_manager):
        super().__init__(f'vi_agent{visitor_id}')
        self.host_id = host_id
        self.ci_id = ci_id
        self.building_id = building_id
        self.visitor_id = visitor_id
        self.campus_graph = campus_graph
        self.campus_manager = campus_manager
        self.position = 'Entrance'
        self.building_position = 'Entrance'
        self.current_building = None
        self.transport_mode = TransportMode.WALK
        self.visitor_pub = self.create_publisher(VisitorArrival, "/vi_agent/visitor_request", 10)
        self.logger = logging.getLogger(f'VisitorAgent_{visitor_id}')
        self.step_in_building = 2

    def set_transport_mode(self, mode):
        self.transport_mode = mode

    def get_travel_time(self, distance):
        if self.transport_mode == TransportMode.VEHICLE:
            return distance
        elif self.transport_mode == TransportMode.CYCLE:
            return distance * 5
        else: 
            return distance * 10

    def move_on_campus(self, new_position):
        path = nx.shortest_path(self.campus_graph.G, source=self.position, target=new_position, weight='weight')
        for step in path[1:]:
            distance = self.campus_graph.G[self.position][step]['weight']
            travel_time = self.get_travel_time(distance)
            log_message = f"Visitor {self.visitor_id} moved from {self.position} to {step} using {self.transport_mode} in {travel_time} time units"
            self.get_logger().info(log_message)
            self.logger.info(log_message)
            self.position = step
            time.sleep(travel_time)

    def move_in_building(self, new_position):
        if self.current_building:
            path = nx.shortest_path(self.current_building.G, source=self.building_position, target=new_position)
            for step in path[1:]:
                log_message = f"Visitor {self.visitor_id} moved from {self.building_position} to {step} in building {self.current_building.building_id}"
                self.get_logger().info(log_message)
                self.logger.info(log_message)
                self.building_position = step
                time.sleep(self.step_in_building)

    def meet_host(self):
        msg = VisitorArrival()
        msg.host_id = self.host_id
        msg.visitor_id = self.visitor_id
        msg.building_id = self.building_id
        msg.ci_id = self.ci_id
        msg.visitor_position = self.position

        if self.ci_id:
            self.visitor_pub.publish(msg)
            log_message = f"Visitor {self.visitor_id} requested to visit host {self.host_id} present at building {self.building_id}"
            self.get_logger().info(log_message)
            self.logger.info(log_message)

def ros2_spin(executor):
    executor.spin()

def backtrack(vi, ci, path, movement_queue, is_building):
    for step in reversed(path[:-1]):  
        if is_building:
            ci.move_in_building(step)
            vi.move_in_building(step)
            movement_queue.put(('building', (vi.building_position, ci.building_position)))
        else:
            ci.move_on_campus(step)
            vi.move_on_campus(step)
            movement_queue.put(('campus', (vi.position, ci.position)))
        time.sleep(1)

    if is_building:
        movement_queue.put(('building', ('', '')))
        log_message = f"Visitor {vi.visitor_id} and CI Agent {ci.ci_id} have left the building"
        vi.get_logger().info(log_message)
        vi.logger.info(log_message)

class Simulation(Node):
    def __init__(self, campus_manager, visitor_host_mapping, hosts_building_mapping, building_bi_mapping, num_ci_agents):
        super().__init__('simulation_node')
        self.campus_manager = campus_manager
        self.visitor_host_mapping = visitor_host_mapping
        self.hosts_building_mapping = hosts_building_mapping
        self.building_bi_mapping = building_bi_mapping
        self.ci_agents = []
        self.bi_agents = {}
        self.visitor_agents = {}
        self.waiting_list = []
        self.current_visitors = {}  
        self.movement_queue = queue.Queue()
        self.callback_group = ReentrantCallbackGroup()
        self.simulation_duration = 360 
        self.end_simulation_timer = self.create_timer(self.simulation_duration, self.end_simulation, callback_group=self.callback_group)
        self.process_timer = self.create_timer(1.0, self.process_next_visitor, callback_group=self.callback_group)
        self.transport = random.choice([TransportMode.CYCLE, TransportMode.WALK, TransportMode.VEHICLE])
        # self.transport = TransportMode.CYCLE
        self.create_ci_agents(num_ci_agents)
        self.visualization = EnhancedVisualization(self.campus_manager, self.ci_agents, self.bi_agents, self.current_visitors)
    
    def create_ci_agents(self, num_agents):
        for i in range(num_agents):
            ci_agent = CIAgent(f"C{i+1}", self.campus_manager.campus_graph, self.campus_manager)
            ci_agent.set_transport_mode(self.transport)
            self.ci_agents.append(ci_agent)

    def create_bi_agents(self, hosts_status, unauthorized_visitors, hosts_path):
        for building_id, bi_id in self.building_bi_mapping.items():
            self.bi_agents[building_id] = BIAgent(bi_id, hosts_status, unauthorized_visitors, hosts_path)

    def create_visitor_agent(self, visitor_id, ci_id):
        host_id = self.visitor_host_mapping[visitor_id]
        building_id = self.hosts_building_mapping[host_id]
        bi_id = self.building_bi_mapping[building_id]
        vi = VisitorAgent(host_id, visitor_id, ci_id, building_id, self.campus_manager.campus_graph, self.campus_manager)
        vi.set_transport_mode(self.transport )
        return vi

    def add_visitor_to_waiting_list(self, visitor_id):
        self.waiting_list.append(visitor_id)
        self.visualization.update_waiting_list(self.waiting_list)

    def process_next_visitor(self):
        if self.waiting_list:
            available_agents = [agent for agent in self.ci_agents if agent.is_available]
            if available_agents:
                visitor_id = self.waiting_list.pop(0)
                ci_agent = random.choice(available_agents)
                current_visitor = self.create_visitor_agent(visitor_id, ci_agent.ci_id)
                self.visitor_agents[visitor_id] = current_visitor
                self.current_visitors[ci_agent.ci_id] = current_visitor  
                ci_agent.start_trip()
                self.simulate_visitor_journey(current_visitor, ci_agent)

    def simulate_visitor_journey(self, visitor, ci_agent):

        visitor.meet_host()
        building_id = visitor.building_id
        bi_agent = self.bi_agents[building_id]
        self.visualization.update_agent_positions(ci_agent, visitor)
        ci_agent.move_on_campus(building_id)
        visitor.move_on_campus(building_id)
        self.movement_queue.put(('campus', (visitor.position, ci_agent.position, ci_agent.ci_id)))
        self.visualization.update_agent_positions(ci_agent, visitor, building_id)
        access_granted, _ = bi_agent.check_visitor_access(visitor.visitor_id)

        if access_granted:
            ci_agent.current_building = self.campus_manager.get_building_graph(building_id)
            visitor.current_building = self.campus_manager.get_building_graph(building_id)
            host_path = bi_agent.hosts_path[visitor.host_id]
            for step in host_path:
                ci_agent.move_in_building(step)
                visitor.move_in_building(step)
                self.movement_queue.put(('building', (visitor.building_position, ci_agent.building_position, ci_agent.ci_id)))
            log_message = f"Visitor {visitor.visitor_id} meeting host {visitor.host_id} in building {building_id}. Host Unavailable for {bi_agent.visit_duration} seconds"
            ci_agent.get_logger().info(log_message)
            ci_agent.logger.info(log_message)
            ci_agent.visitor_host_meet_time = bi_agent.visit_duration
            time.sleep(bi_agent.visit_duration)  

            backtrack(visitor, ci_agent, host_path, self.movement_queue, True)

        ci_agent.move_on_campus('Entrance')
        visitor.move_on_campus('Entrance')
        self.movement_queue.put(('campus', (visitor.position, ci_agent.position, ci_agent.ci_id)))
        self.visualization.update_agent_positions(ci_agent, visitor, building_id)
        ci_agent.end_trip()
        self.visualization.update_agent_positions(ci_agent, visitor)
        self.visualization.remove_visitor(ci_agent.ci_id)
        
    def end_simulation(self):
        self.get_logger().info(" ")
        self.get_logger().info("Simulation ended. Generating performance reports...")
        self.generate_performance_report()
        rclpy.shutdown()

    def generate_performance_report(self):
        for ci_agent in self.ci_agents:
            report = f"Performance Report for CI Agent {ci_agent.ci_id}:\n"
            report += f"Total Visitors Entertained: {ci_agent.visitors_entertained}\n"
            report += f"Total Violations: {ci_agent.violation_count}\n"
            report += f"Total Violation Time: {ci_agent.total_violation_time:.2f} seconds\n"
            report += f"Performance Score: {ci_agent.performance_score:.2f}\n"
            self.get_logger().info(report)

            with open(f'ci_agent_{ci_agent.ci_id}_performance_report.txt', 'w') as f:
                f.write(report)

        for building_id, bi_agent in self.bi_agents.items():
            bi_agent.update_performance_score()
            report = f"Performance Report for BI Agent {bi_agent.bi_id} (Building {building_id}):\n"
            report += f"Total CI Agents Guided: {bi_agent.ci_agents_guided}\n"
            report += f"Total OOS Violations: {bi_agent.oos_violations}\n"
            report += f"Performance Score: {bi_agent.performance_score:.2f}\n"
            self.get_logger().info(report)

            with open(f'bi_agent_{bi_agent.bi_id}_performance_report.txt', 'w') as f:
                f.write(report)

class EnhancedVisualization:
    def __init__(self, campus_manager, ci_agents, bi_agents, current_visitors):
        self.campus_manager = campus_manager
        self.ci_agents = ci_agents
        self.bi_agents = bi_agents
        self.current_visitors = current_visitors
        self.waiting_list = []

        plt.style.use('seaborn-whitegrid')
        sns.set_palette("husl")
        self.custom_cmap = LinearSegmentedColormap.from_list("custom", 
                                                             ["#ff9999", "#66b3ff", "#99ff99", "#ffcc99"])

        self.fig = plt.figure(figsize=(18, 9))
        self.gs = self.fig.add_gridspec(1, 2, width_ratios=[1, 1.5])

        self.campus_ax = self.fig.add_subplot(self.gs[0, 0])
        self.buildings_ax = self.fig.add_subplot(self.gs[0, 1])

        num_buildings = len(self.campus_manager.building_graphs)
        self.grid_size = max(2, int(num_buildings ** 0.5))
        self.building_axes = {}

        for i, (building_id, building_graph) in enumerate(self.campus_manager.building_graphs.items()):
            ax = self.buildings_ax.inset_axes([
                (i % self.grid_size) / self.grid_size,
                1 - (i // self.grid_size + 1) / self.grid_size,
                0.9 / self.grid_size,
                0.9 / self.grid_size
            ])
            self.building_axes[building_id] = ax

    def update_campus(self):
        self.campus_ax.clear()
        pos = self.campus_manager.campus_graph.pos

        node_colors = [self.custom_cmap(i/len(pos)) for i in range(len(pos))]
        
        nx.draw(self.campus_manager.campus_graph.G, pos, ax=self.campus_ax, 
                with_labels=True, node_color=node_colors, node_size=1200, 
                font_size=9, font_weight='bold', edge_color='#CCCCCC', width=2, 
                alpha=0.8, style='dashed')

        for building, incharge in self.campus_manager.campus_graph.building_incharge.items():
            self.campus_ax.annotate(f"Incharge: {incharge}", 
                xy=pos[building], xytext=(0, 30), 
                textcoords="offset points", ha='center', va='bottom',
                bbox=dict(boxstyle="round,pad=0.3", fc="white", ec="gray", alpha=0.8),
                fontsize=8, fontweight='bold')

        for building, hosts in self.campus_manager.campus_graph.hosts.items():
            self.campus_ax.annotate(f"Hosts: {', '.join(hosts)}", 
                xy=pos[building], xytext=(0, 15), 
                textcoords="offset points", ha='center', va='bottom',
                bbox=dict(boxstyle="round,pad=0.3", fc="white", ec="gray", alpha=0.8),
                fontsize=8)

        for ci_agent in self.ci_agents:
            self.campus_ax.plot(*pos[ci_agent.position], marker='o', markersize=12, 
                                color='green', markeredgecolor='darkgreen', markeredgewidth=2)
            self.campus_ax.annotate(f"CI: {ci_agent.ci_id}", 
                xy=pos[ci_agent.position], xytext=(0, -25), 
                textcoords="offset points", ha='center', va='top',
                bbox=dict(boxstyle="round,pad=0.3", fc="lightgreen", ec="darkgreen", alpha=0.8),
                fontsize=8, fontweight='bold')

        for ci_id, visitor in self.current_visitors.items():
            self.campus_ax.plot(*pos[visitor.position], marker='o', markersize=12, 
                                color='red', markeredgecolor='darkred', markeredgewidth=2)
            self.campus_ax.annotate(f"V: {visitor.visitor_id}", 
                xy=pos[visitor.position], xytext=(0, -50), 
                textcoords="offset points", ha='center', va='bottom',
                bbox=dict(boxstyle="round,pad=0.3", fc="lightsalmon", ec="darkred", alpha=0.8),
                fontsize=8, fontweight='bold')

        waiting_text = f"Waiting: {', '.join(self.waiting_list)}" if self.waiting_list else "No visitors waiting"
        self.campus_ax.text(0.5, 1.05, waiting_text, transform=self.campus_ax.transAxes, ha='center', va='center',
                            bbox=dict(boxstyle="round,pad=0.3", fc="#FFD700", ec="orange", alpha=0.8),
                            fontsize=10, fontweight='bold')

        self.campus_ax.set_title("Campus Map", fontsize=16, fontweight='bold')

    def update_buildings(self):
        for building_id, ax in self.building_axes.items():
            ax.clear()
            building_graph = self.campus_manager.building_graphs[building_id]
            pos = building_graph.pos
 
            node_colors = plt.cm.get_cmap('Set3')(np.linspace(0, 1, len(pos)))
            
            nx.draw(building_graph.G, pos, ax=ax, with_labels=True, 
                    node_color=node_colors, node_size=1200, font_size=8, font_weight='bold',
                    edge_color='#AAAAAA', width=1.5, alpha=0.9, style='dotted')

            bi_agent = self.bi_agents[building_id]
            ax.plot(*pos['Entrance'], marker='s', markersize=14, 
                    color='blue', markeredgecolor='darkblue', markeredgewidth=2)
            ax.annotate(f"BI: {bi_agent.bi_id}", 
                xy=pos['Entrance'], xytext=(0, -15), 
                textcoords="offset points", ha='center', va='top',
                bbox=dict(boxstyle="round,pad=0.3", fc="lightblue", ec="darkblue", alpha=0.8),
                fontsize=8, fontweight='bold')

            for room, host in building_graph.hosts.items():
                ax.annotate(f"Host: {host}", 
                    xy=pos[room], xytext=(0, 15), 
                    textcoords="offset points", ha='center', va='bottom',
                    bbox=dict(boxstyle="round,pad=0.3", fc="lightyellow", ec="orange", alpha=0.8),
                    fontsize=7)

            for ci_agent in self.ci_agents:
                if ci_agent.current_building and ci_agent.current_building.building_id == building_id:
                    ax.plot(*pos[ci_agent.building_position], marker='o', markersize=12, 
                            color='green', markeredgecolor='darkgreen', markeredgewidth=2)
                    ax.annotate(f"CI: {ci_agent.ci_id}", 
                        xy=pos[ci_agent.building_position], xytext=(0, -30), 
                        textcoords="offset points", ha='center', va='top',
                        bbox=dict(boxstyle="round,pad=0.3", fc="lightgreen", ec="darkgreen", alpha=0.8),
                        fontsize=8, fontweight='bold')

                    if ci_agent.ci_id in self.current_visitors:
                        visitor = self.current_visitors[ci_agent.ci_id]
                        ax.plot(*pos[visitor.building_position], marker='o', markersize=12, 
                                color='red', markeredgecolor='darkred', markeredgewidth=2)
                        ax.annotate(f"V: {visitor.visitor_id}", 
                            xy=pos[visitor.building_position], xytext=(0, -55), 
                            textcoords="offset points", ha='center', va='bottom',
                            bbox=dict(boxstyle="round,pad=0.3", fc="lightsalmon", ec="darkred", alpha=0.8),
                            fontsize=8, fontweight='bold')

            ax.set_title(f"Building {building_id}", fontsize=12, fontweight='bold')

    def animate(self, frame):
        self.update_campus()
        self.update_buildings()
        self.buildings_ax.set_title("Building Maps", fontsize=16, fontweight='bold')
        self.fig.tight_layout()

    def start_animation(self):
        anim = FuncAnimation(self.fig, self.animate, frames=200, interval=500, repeat=True)
        plt.show()

    def update_agent_positions(self, ci_agent, visitor, building_id=None):
        if building_id:
            ci_agent.current_building = self.campus_manager.get_building_graph(building_id)
            visitor.current_building = self.campus_manager.get_building_graph(building_id)
        else:
            ci_agent.current_building = None
            visitor.current_building = None

        self.current_visitors[ci_agent.ci_id] = visitor

    def remove_visitor(self, ci_id):
        if ci_id in self.current_visitors:
            del self.current_visitors[ci_id]

    def update_waiting_list(self, waiting_list):
        self.waiting_list = waiting_list

def main(args=None):
    rclpy.init(args=args)

    building_hosts_mapping = {'B1': ('H1','H2','H3'), 'B2': ('H4','H5','H6'), 'B3': ('H7','H8','H9'), 'B4': ('H10','H11','H12')}
    hosts_building_mapping = {'BI1': 'B1', 'BI2': 'B2', 'BI3': 'B3', 'BI4': 'B4',
        "H1": 'B1', "H2": 'B1', "H3": 'B1', "H4": 'B2', "H5": 'B2', "H6": 'B2',
        "H7": 'B3', "H8": 'B3', "H9": 'B4', "H10": 'B4', "H11": 'B4', "H12": 'B4',
    }
    building_bi_mapping = {'B1': 'BI1', 'B2': 'BI2', 'B3': 'BI3', 'B4': 'BI4'}
    hosts_status = {f"H{i}": 'available' for i in range(1, 13)}
    unauthorized_visitors = {
        "H1":['V1','V4','V12'], "H2": ['V2'], "H3": ['V3','V5','V9'], "H4": ['V4'],
        "H5": ['V5','V6'], "H6": ['V6','V2','V7','V10'], "H7": ['V7','V11'],
        "H8": ['V8','V3','V11'], "H9": ['V9','V1'], "H10": ['V10','V2','V7','V8'],
        "H11": ['V11','V9'], "H12": ['V12'],
    }
    hosts_path = {'BI1':['Entrance'],
                  'BI2':['Entrance'],
                  'BI3':['Entrance'],
                  'BI4':['Entrance'],
            "H1":['Entrance', 'Room1'],
            "H2":['Entrance', 'Room1', 'Room2'],
            "H3":['Entrance', 'Room1', 'Room2', 'Room3'],
            "H4":['Entrance', 'Room1'],
            "H5":['Entrance', 'Room1', 'Room2'],
            "H6":['Entrance', 'Room1', 'Room2', 'Room3'],
            "H7":['Entrance', 'Room1'],
            "H8":['Entrance', 'Room1', 'Room2'],
            "H9":['Entrance', 'Room1', 'Room2', 'Room3'],
            "H10":['Entrance', 'Room1'],
            "H11":['Entrance', 'Room1', 'Room2'],
            "H12":['Entrance', 'Room1', 'Room2', 'Room3'],
        }

    campus_manager = CampusManager(building_hosts_mapping, building_bi_mapping)
    num_visitors = random.randint(4,6)
    num_ci_agents = random.randint(2,3) 
    visitors = [f'V{i}' for i in range(1, num_visitors + 1)]
    hosts = [f'H{i}' for i in range(1, 13)]
    Building_agents = ['BI1','BI2','BI3','BI4']
    total_hosts = hosts+Building_agents
    visitor_host_mapping = {visitor: random.choice(total_hosts) for visitor in visitors}

    simulation = Simulation(campus_manager, visitor_host_mapping, hosts_building_mapping, building_bi_mapping, num_ci_agents)
    visualization = simulation.visualization
    
    simulation.create_bi_agents(hosts_status, unauthorized_visitors, hosts_path)

    executor = MultiThreadedExecutor()
    executor.add_node(simulation)
    for ci_agent in simulation.ci_agents:
        executor.add_node(ci_agent)

    ros2_thread = threading.Thread(target=ros2_spin, args=(executor,))
    ros2_thread.start()
    
    for bi_agent in simulation.bi_agents.values():
        executor.add_node(bi_agent)

    def visitor_arrival_simulation():
        for visitor_id in visitors:
            arrival_time = random.uniform(0, 30) 
            time.sleep(arrival_time)
            simulation.add_visitor_to_waiting_list(visitor_id)

    arrival_thread = threading.Thread(target=visitor_arrival_simulation)
    arrival_thread.start()

    visualization.start_animation()

    arrival_thread.join()
    ros2_thread.join()

    simulation.destroy_node()
    for bi_agent in simulation.bi_agents.values():
        bi_agent.destroy_node()
    for ci_agent in simulation.ci_agents:
        ci_agent.destroy_node()

if __name__ == '__main__':
    main()