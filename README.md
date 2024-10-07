# Multiagent System for Campus Virtual Tour

This project implements a sophisticated campus tour simulation using ROS2 (Robot Operating System 2) and Python. The system models a campus environment with multiple buildings, hosts, and visitors, managed by different types of intelligent agents capable of dynamic interaction, ensuring efficient and smooth navigation.

## Features
- **Campus Graph & Building Graphs**: Models the campus and buildings as graphs for efficient pathfinding and navigation.
- **Agents**: Includes Campus Incharge (CI) Agents, Building Incharge (BI) Agents, and Visitor Agents.
- **Pathfinding Algorithm**: Optimizes routes across campus, considering multiple transport modes like walking, cycling, and driving.
- **Simulation Node**: Manages agent interactions, visualization, and performance reporting.
- **ROS2 Integration**: Asynchronous communication between agents using ROS2 publishers, subscribers, and callbacks.

## System Architecture
The system is built upon ROS2 communication and consists of several key components:
- **Campus Manager**: Manages campus and building graphs for agent navigation.
- **Simulation Node**: Coordinates agent movements and manages agent-to-environment interactions.
- **Transport Modes**: Different modes of transport for agents (vehicle, cycle, walk).
- **Pathfinding Algorithm**: Determines optimal routes for agent movement.
- **CI and BI Agents**: Campus Incharge (CI) and Building Incharge (BI) agents oversee campus and building management, respectively.

## Setup Instructions
1. Install the necessary dependencies:
   ```bash
   sudo apt install ros-foxy-desktop
   pip install rclpy
   ```
2. Clone the repository:
   ```bash
   git clone <repository-url>
   cd [repository_name]
   ```
3. Build and run the ROS2 simulation:
```bash
  colcon build
  source ~/.bashrc
  ros2 run campus_agents test_node
```

## Simulation Scenarios
The simulation offers multiple visitor scenarios:
- **Visitor Arrival**: Visitors are assigned to CI agents for navigation.
- **Navigation Request**: Pathfinding for visitors is requested and managed.
- **Access Denied/Granted**: Visitor permissions to enter buildings are checked and enforced.
- **Violations and Monitoring**: Monitors agent adherence to schedules, reporting out-of-service and time violations.

## Performance Analysis
The system tracks agent efficiency based on transport modes:
- **Vehicle Mode**: Faster navigation, fewer violations.
- **Cycle Mode**: Slower movements, more violations.
- **Walk Mode**: Even slower, leading to increased violation counts.

## Future Improvements
- Expand agent roles to include more complex campus scenarios.
- Integrate with real-world campus maps for enhanced simulation.
- Implement more robust error handling for agent failures.

## Contributors
- [Kushal Agrawal](https://www.linkedin.com/in/kushal-agrawal-36a387168/)
- [Ritu Singh](https://www.linkedin.com/in/ritusingh46/)

![graphical visualization](https://github.com/user-attachments/assets/d92ad051-0ff8-44f5-9c64-65a69ea12a5f)
