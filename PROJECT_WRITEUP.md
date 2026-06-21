# Project Writeup

## Project Context

Project Lazarus was ORU's Formula SAE senior design project for updating a legacy ICE Formula SAE vehicle for the 2026 competition cycle. The vehicle used a Suzuki GSX-R600 motorcycle engine, so the electrical system involved adapting a motorcycle harness to a custom Formula SAE chassis.

The electrical work included the 12 V vehicle architecture, ECU/ECM wiring, relays, fuse protection, shutdown devices, sensors, dashboard, brake light, cooling fan, starter behavior, clutch interlock behavior, ignition behavior, and paddle shifting.

## Project Status

At the time of documentation, the electrical system was approximately 90% complete. The remaining work mainly involved mounting a few harness-related components and completing final vehicle-level installation and testing. Because the overall car build was extended into a two-year project due to limited team size, budget, and school resources, this repository documents the completed electrical work and the remaining integration context.

The legacy harness shown in the repository was inherited from a previous team. Our team used it as the baseline for understanding the existing electrical system and then modified the design for the current FSAE vehicle.

## My Individual Contribution: Paddle-Shifting System

My main individual contribution was the paddle-shifting system. I worked on the circuit concept, Arduino firmware, and integration plan for using steering-wheel paddle switches to control a linear actuator through an H-bridge motor driver.

The system used:

- D2: up-shift paddle input
- D3: down-shift paddle input
- D4: clutch switch input
- D9/D10: H-bridge PWM outputs
- A0: actuator position feedback
- Buck converter: 12 V to 5 V controller supply
- H-bridge: actuator motor direction and movement control

The control logic handled upshift, downshift, and neutral-shift routines. It also included debounce timing, lockout timing, movement timeout protection, actuator feedback reading, and return-to-neutral behavior.

## Major Team Contribution: Ignition System

I was heavily involved in the ignition-system debugging and implementation work. One key issue was that the ECU would not properly command the fuel pump to prime even when voltage was present on the ignition-related wires. The problem was traced to the ECU expecting the ignition input to behave like the original Suzuki ignition switch rather than just seeing voltage.

The team solution involved using a resistance value on the ignition signal path. A 150 Ω resistor was used to reproduce the expected ignition-switch condition and support proper ECU/fuel-pump behavior. This was one of the clearest examples of hardware-software integration in the project because the electrical behavior of a simple switch circuit directly affected ECU logic.

## Team Contribution: Harness Installation and Electrical Integration

I also contributed to the overall harness installation and vehicle electrical integration as part of the electrical team. Because the harness work was shared across the team, I describe this as a team-level contribution.

This work included helping adapt the GSX-R600 harness to the FSAE car, working around the physical wiring, supporting relay and switch connections, and helping prepare the vehicle electrical system for testing.

## Engineering Significance

The project taught me that embedded systems in vehicles are not just about code or individual circuits. A controller has to work around physical wiring, power distribution, grounding, relays, sensors, shutdown behavior, actuator timing, and the mechanical system it controls. The paddle-shifting and ignition-system work especially connected firmware, power electronics, ECU logic, actuator control, and drivetrain behavior.
