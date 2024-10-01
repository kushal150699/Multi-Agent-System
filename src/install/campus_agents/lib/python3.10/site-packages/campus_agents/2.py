#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import random
from campus_agents.msg import NavigationPath, AccessDenied, OutOfService

class CIAgent(Node):
    def __init__(self, name):
        super().__init__(f'ci_agent_{name}')
        self.name = name
        self.navigation_pub = self.create_publisher(NavigationPath, '/ci_agent/navigation_request', 10)
        self.access_denied_sub = self.create_subscription(AccessDenied, '/bi_agent/access_denied', self.handle_access_denied, 10)
        self.oos_sub = self.create_subscription(OutOfService, '/bi_agent/out_of_service', self.handle_oos, 10)
        self.current_visitor = None
        self.current_path = []
        self.position = [0, 0]

    def escort_visitor(self, visitor_id, host_id):
        self.current_visitor = visitor_id
        nav_request = NavigationPath()
        nav_request.visitor_id = visitor_id
        nav_request.host_id = host_id
        self.navigation_pub.publish(nav_request)

    def handle_access_denied(self, msg):
        self.get_logger().info(f"CI Agent {self.name}: Access denied for visitor {msg.visitor_id}. Reason: {msg.reason}")

    def handle_oos(self, msg):
        self.get_logger().info(f"CI Agent {self.name}: BI agent is out of service for {msg.duration} seconds")

class BIAgent(Node):
    def __init__(self, name, building_map):
        super().__init__(f'bi_agent_{name}')
        self.name = name
        self.building_map = building_map
        self.navigation_sub = self.create_subscription(NavigationPath, '/ci_agent/navigation_request', self.handle_navigation_request, 10)
        self.access_denied_pub = self.create_publisher(AccessDenied, '/bi_agent/access_denied', 10)
        self.oos_pub = self.create_publisher(OutOfService, '/bi_agent/out_of_service', 10)
        self.is_hosting = False
        self.host_id = None
        self.position = [0, 0]
        self.visitor_authorization = {
            'Visitor_1': True,
            'Visitor_2': True,
            'Visitor_3': False,
        }
        self.host_availability = {
            'Host_1': True,
            'Host_2': False,
            'Host_3': True,
        }

    def handle_navigation_request(self, msg):
        visitor_id = msg.visitor_id
        host_id = msg.host_id

        if self.is_hosting and host_id == self.host_id:
            self.get_logger().info(f"BI Agent {self.name}: Denying navigation request for visitor {visitor_id} as I am currently hosting.")
            access_denied = AccessDenied()
            access_denied.visitor_id = visitor_id
            access_denied.reason = "BI agent is currently hosting"
            self.access_denied_pub.publish(access_denied)
            return

        if self.is_authorized(visitor_id) and self.is_host_available(host_id):
            navigation_path = self.get_navigation_path(host_id)
            nav_response = NavigationPath()
            nav_response.visitor_id = visitor_id
            nav_response.path = navigation_path
            self.navigation_pub.publish(nav_response)
        else:
            access_denied = AccessDenied()
            access_denied.visitor_id = visitor_id
            access_denied.reason = "Unauthorized or host unavailable"
            self.access_denied_pub.publish(access_denied)

    def is_authorized(self, visitor_id):
        return self.visitor_authorization.get(visitor_id, False)

    def is_host_available(self, host_id):
        return self.host_availability.get(host_id, False)

    def get_navigation_path(self, host_id):
        if host_id == 'Host_1':
            return [1, 2, 3]
        elif host_id == 'Host_2':
            return [1, 4, 5]
        elif host_id == 'Host_3':
            return [1, 2, 3, 4, 5]
        else:
            return [1, 2, 3, 4, 5]

    def go_out_of_service(self, duration):
        self.is_hosting = True
        oos_msg = OutOfService()
        oos_msg.duration = duration
        self.oos_pub.publish(oos_msg)
        self.create_timer(duration, self.end_out_of_service)

    def end_out_of_service(self):
        self.is_hosting = False
        self.get_logger().info(f"BI Agent {self.name}: Back in service")

class VisitorAgent:
    def __init__(self, name, host_id):
        self.name = name
        self.host_id = host_id
        self.ci_agent = None
        self.position = [0, 0]

    def meet_host(self):
        if self.ci_agent:
            self.ci_agent.escort_visitor(self.name, self.host_id)

def main():
    rclpy.init()

    num_ci_agents = random.randint(2, 5)
    num_bi_agents = random.randint(1, 3)
    num_visitors = random.randint(5, 15)

    ci_agents = [CIAgent(f'CI_Agent_{i}') for i in range(num_ci_agents)]
    bi_agents = [BIAgent(f'BI_Agent_{i}', building_map=[1, 2, 3, 4, 5]) for i in range(num_bi_agents)]
    visitors = [VisitorAgent(f'Visitor_{i}', host_id=f'Host_{i}') for i in range(num_visitors)]

    for visitor in visitors:
        visitor.ci_agent = random.choice(ci_agents)

    for visitor in visitors:
        visitor.meet_host()

    bi_agents[0].go_out_of_service(60)

    executor = rclpy.executors.MultiThreadedExecutor()
    for agent in ci_agents + bi_agents:
        executor.add_node(agent)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass

    for agent in ci_agents + bi_agents:
        agent.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()