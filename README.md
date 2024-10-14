# Firefighting-Robot
## Overview
This project implements a **firefighting robot** using an Arduino-based platform. The robot is designed to detect fire and gas in its environment and autonomously navigate towards the fire to extinguish it using a water pump and servo mechanism. The robot also features basic obstacle avoidance to ensure it reaches the fire without collisions.
## Features
- **Fire detection**: The robot detects fire using front, left, and right sensors. Upon detecting a fire, it stops and activates a water pump to extinguish the fire.
- **Gas detection**: The robot includes a gas sensor that detects harmful gases in the environment.
- **Autonomous navigation**: It moves forward and avoids obstacles, using left, right, and forward sensors.
- **Servo-controlled water pump**: The robot sprays water over a defined range to ensure the fire is extinguished.
## How It Works
1. The robot continuously scans its environment using the front, left, and right sensors.
2. When a fire is detected in front, the robot stops and activates the water pump, controlled by a servo motor, to extinguish the fire.
3. The servo sweeps from left to right, ensuring the fire is properly put out.
4. If the gas sensor detects gas, the robot prints a warning message to the Serial Monitor.
5. The robot resumes its navigation once the fire is extinguished.
