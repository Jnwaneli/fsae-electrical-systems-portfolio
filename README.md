# Formula SAE Electrical Systems Portfolio

## Paddle-Shifting Controller, Ignition-System Support, Harness Installation, and Vehicle Electrical Integration

**Author:** Joshua Chukwuebuka Nwaneli  
**Project:** Project Lazarus — Oral Roberts University Formula SAE 2026  
**Public team site:** [oruracing.com](https://oruracing.com)  
**Focus Areas:** Embedded control, actuator control, ignition-system support/debugging, vehicle wiring, relay logic, shutdown safety, harness installation, and electrical documentation.

---

## Overview

This repository documents selected electrical and embedded-systems work from ORU's Formula SAE Project Lazarus. The vehicle used a Suzuki GSX-R600 motorcycle engine, which required adapting a motorcycle wiring harness into a custom Formula SAE race car platform.

The electrical work included ECU/ECM connections, ignition and starter behavior, sensors, relays, shutdown devices, brake light control, cooling fan control, driver inputs, physical harness installation, and an Arduino-based paddle-shifting subsystem.

My primary individual work was the **paddle-shifting system**. I was also **heavily involved in ignition-system debugging/implementation**, and I contributed to the broader **harness installation and vehicle electrical integration** work with the electrical team.

![ORU Formula SAE Project Lazarus car](assets/selected_report_excerpts/team_or_car_photo.png)

*Figure 1. ORU Formula SAE Project Lazarus vehicle during the 2026 senior design cycle.*

### Primary Contribution — Paddle-Shifting System

<img src="assets/selected_report_excerpts/paddle_shift_full_system.png" alt="Full paddle-shift system" width="100%" />

*Figure 2. Full paddle-shifting control system used during integration and bench testing, showing the controller enclosure, Arduino-based electronics, power-conversion and motor-driver hardware, wiring, and linear actuator.*

<img src="assets/selected_report_excerpts/paddle_shift_control_box.jpg" alt="Close-up of paddle-shift control electronics enclosure" width="100%" />

*Figure 3. Close-up of the paddle-shift control enclosure showing the Arduino Uno, H-bridge motor driver, 12 V-to-5 V power conversion, wiring, and controller connections used to drive the linear actuator.*

#### Electrical Design and Documentation

The paddle-shifting subsystem is documented within the vehicle electrical design and in a dedicated subsystem schematic. These files show how the controller, driver inputs, power conversion, H-bridge outputs, actuator feedback, and vehicle wiring fit into the broader electrical architecture.

- **[Full vehicle electrical schematic and harness mapout](docs/Full_Electrical_Schematic_2_0.pdf)**
- **[Paddle-shift controller firmware](firmware/paddle_shift_controller.ino)**

![Paddle-shift schematic](assets/selected_report_excerpts/paddle_shift_schematic.png)

*Figure 4. Paddle-shifting subsystem schematic showing Arduino inputs, clutch logic, H-bridge motor control, actuator feedback, and power conversion.*

The paddle-shifting system was one of my largest individual contributions to Project Lazarus. I designed and developed the Arduino-based control system that converts steering-wheel up-shift and down-shift commands into bidirectional movement of a linear actuator through an H-bridge motor driver. The hardware stack combines an Arduino Uno, 12 V-to-5 V buck converter, H-bridge, clutch input, actuator position feedback, fuse protection, and vehicle wiring.

The firmware handles upshift, downshift, and neutral routines; paddle-input debounce; clutch gating; post-shift lockout timing; actuator position targets; movement timeout protection; and return-to-neutral behavior after each shift. This subsystem brought together embedded control, power conversion, actuator control, driver inputs, feedback, and vehicle-level electrical integration in one complete system.

---

## What to Look At

- `firmware/paddle_shift_controller.ino` - Arduino paddle-shift control logic, including shift routines, debounce handling, clutch gating, timing lockouts, and actuator feedback.
- `assets/selected_report_excerpts/paddle_shift_full_system.png` - Full integrated paddle-shift controller, wiring, power electronics, and linear actuator hardware.
- `assets/selected_report_excerpts/paddle_shift_control_box.jpg` - Close-up of the paddle-shift electronics enclosure and controller hardware.
- `docs/Full_Electrical_Schematic_2_0.pdf` - Full vehicle electrical schematic and harness mapout.
- `docs/FSAE_2026_Final_Report_04_29_2026.pdf` - Senior design report with vehicle-level project context.
- `assets/selected_report_excerpts/final_harness_mapout.png` - Final harness documentation figure.
- `assets/selected_report_excerpts/paddle_shift_schematic.png` - Paddle-shifting subsystem schematic.
- `assets/selected_report_excerpts/paddle_shift_steering_wheel.jpg` - Steering-wheel assembly with integrated shift paddles.
- `assets/selected_report_excerpts/ignition_system_circuit.png` - Ignition-system circuit implementation.
- `assets/selected_report_excerpts/emergency_shutdown_circuit.png` - Shutdown and safety circuit documentation.

---

## Project Status

This repository documents the work completed during the 2026 Formula SAE senior design cycle. At the time of documentation, the electrical system was approximately **90% complete**. Remaining work mainly involved mounting a few harness-related components and completing final vehicle-level installation and testing.

Because ORU is a smaller school and the team consisted of only nine students working with limited budget and resources, the overall car build was extended into a two-year project. The legacy harness shown in this repository was inherited from a previous team, and our work focused on understanding, modifying, documenting, and installing an updated system for the current FSAE vehicle.

---

## Contribution Summary

### Individual Contribution — Paddle-Shifting System

I designed and developed the Arduino-based paddle-shifting control system. The system allowed steering-wheel paddle inputs to command a linear actuator through an H-bridge motor driver for shifting the sequential Suzuki GSX-R600 transmission.

The subsystem used:

- Arduino Uno microcontroller
- Up-shift and down-shift paddle switches
- Clutch switch input
- H-bridge motor driver
- Linear actuator
- Buck converter for 12 V to 5 V conversion
- Actuator position feedback through analog input
- Fuse protection and vehicle harness integration

The firmware implements:

- Upshift, downshift, and neutral-shift routines
- Debounce handling for paddle inputs
- Clutch-gated shift behavior
- Lockout timing after shift commands
- Actuator position feedback using analog input
- Move timeout protection
- Return-to-neutral behavior after each shift

### Major Team Contribution — Ignition-System Debugging and Implementation

I was heavily involved in the ignition-system debugging and implementation work. A major issue was that the ECU would not command the fuel pump to prime even though voltage was present at the ignition-related wires. The system showed an ignition-switch-related fault, which meant the problem was not simply missing voltage; the ECU expected the ignition input to behave like the original Suzuki ignition switch.

As part of the ignition-system work, the ignition path was tested using resistance values on the ignition signal. A **150 Ω resistor** was used to reproduce the ignition-switch condition needed by the ECU. This work helped restore proper ignition recognition and fuel pump priming behavior.

### Team Contribution — Harness Installation and Electrical Integration

I also contributed to the broader electrical team effort, including harness installation and vehicle electrical integration. Since the harness work was shared by the electrical team, I describe this part as team-level work that I participated in. This included working with the GSX-R600 harness, routing and connecting wiring, integrating switches and relays, preparing circuits for testing, and helping the system move from schematic-level design to physical vehicle wiring.

---

## Repository Structure

```text
fsae-electrical-systems-portfolio/
├── README.md
├── PROJECT_WRITEUP.md
├── UPLOAD_CHECKLIST.md
├── docs/
│   ├── FSAE_2026_Final_Report_04_29_2026.pdf
│   └── Full_Electrical_Schematic_2_0.pdf
├── firmware/
│   └── paddle_shift_controller.ino
└── assets/
    └── selected_report_excerpts/
```

---

## Key Artifacts

### Harness Documentation

The vehicle-level electrical documentation captures the integrated ECU/ECM wiring, ignition/fuel circuits, relays, sensors, shutdown devices, brake light, cooling fan, and paddle-shifting subsystem.

- [`docs/FSAE_2026_Final_Report_04_29_2026.pdf`](docs/FSAE_2026_Final_Report_04_29_2026.pdf)

![Final harness mapout](assets/selected_report_excerpts/final_harness_mapout.png)

*Figure 5. Final electrical harness mapout used to document major vehicle wiring paths and system connections.*

### Legacy Harness Context

The legacy harness was inherited from a previous team. It served as the starting point for understanding the original motorcycle wiring and deciding how the system needed to be modified for the current Formula SAE vehicle.

![Legacy harness](assets/selected_report_excerpts/legacy_harness.png)

*Figure 6. Legacy GSX-R600 harness inherited from the previous team and used as the starting point for electrical-system analysis.*

### Physical Harness Installation

The physical harness screenshots show the vehicle-level wiring installation and routing work. This was part of the shared electrical-team effort to move the system from schematic documentation to a real car harness.

![Physical harness side view](assets/selected_report_excerpts/phy_harness_sideview.png)

*Figure 7. Physical harness installation side view during vehicle-level wiring integration.*

![Physical harness back view](assets/selected_report_excerpts/phy_harness_backview.png)

*Figure 8. Physical harness installation rear/back view showing routing and integration progress.*

---

## Paddle-Shifting Subsystem

The paddle-shifting subsystem used an Arduino, H-bridge, buck converter, clutch switch, paddle switches, actuator feedback, and actuator motor lines. The Arduino used D2/D3 for paddle inputs, D4 for clutch logic, D9/D10 for H-bridge motor control, and A0 for actuator feedback.

### Steering-Wheel Paddle Inputs

![Steering wheel with paddle shifters](assets/selected_report_excerpts/paddle_shift_steering_wheel.jpg)

*Figure 9. Steering-wheel assembly with integrated paddle switches used to provide driver up-shift and down-shift inputs to the paddle-shifting controller.*

### Paddle-Shift Hardware Components

![Arduino board](assets/selected_report_excerpts/arduino_board.png)

*Figure 10. Arduino Uno used as the paddle-shift controller during the Formula SAE build.*

![H-bridge motor driver](assets/selected_report_excerpts/hbridge.png)

*Figure 11. H-bridge motor driver used to control actuator extension and retraction.*

![Buck converter](assets/selected_report_excerpts/buck_converter.png)

*Figure 12. Buck converter used to step vehicle 12 V power down for the paddle-shift control electronics.*

![Linear actuator](assets/selected_report_excerpts/actuator.png)

*Figure 13. Linear actuator used to mechanically command shifts through the paddle-shifting system.*

### Firmware

- [`firmware/paddle_shift_controller.ino`](firmware/paddle_shift_controller.ino)

---

## Ignition System

The ignition-system work focused on adapting the original Suzuki ignition behavior so the ECU would recognize the circuit correctly. This included studying the OEM ignition switch behavior, testing the ignition circuit, and implementing the resistor condition needed for proper ECU/fuel-pump behavior.

![OEM ignition](assets/selected_report_excerpts/oem_ignition.png)

*Figure 14. OEM Suzuki ignition-switch reference used to understand the expected ECU ignition input behavior.*

![Ignition system circuit](assets/selected_report_excerpts/ignition_system_circuit.png)

*Figure 15. Ignition-system circuit implementation used to adapt the motorcycle engine electronics to the FSAE vehicle.*

![Resistance used to bypass ignition](assets/selected_report_excerpts/resistance_used_to_bypass_ignition.png)

*Figure 16. Resistance value selected to reproduce the ignition-switch condition expected by the ECU.*

![Ignition system relay](assets/selected_report_excerpts/ignition_system_relay.png)

*Figure 17. Ignition-system relay arrangement used as part of the engine-start and ECU-recognition circuit.*

### Starter and Ignition Support Circuits

![Starter and ignition switch](assets/selected_report_excerpts/starter_and_ignition_switch.png)

*Figure 18. Starter and ignition-switch support circuit used for engine-start control.*

![Starter relay](assets/selected_report_excerpts/starter_relay.png)

*Figure 19. Starter relay wiring used to control high-current starter operation from low-current driver inputs.*

---

## Shutdown and Safety Circuit

The shutdown circuit includes the master kill switch, driver emergency kill switch, Brake Over-Travel Switch, contactor, inline fuse protection, and flyback-diode protection.

![Emergency shutdown circuit](assets/selected_report_excerpts/emergency_shutdown_circuit.png)

*Figure 20. Emergency shutdown circuit showing safety devices, contactor path, fuse protection, and diode protection.*

![Emergency shutdown circuit physical implementation](assets/selected_report_excerpts/emergency_shutdown_circuit_physical.png)

*Figure 21. Physical emergency shutdown circuit implementation used during vehicle electrical integration.*

---

## Skills Demonstrated

- Embedded control using Arduino
- Motor driver control using H-bridge outputs
- Actuator position feedback and movement targets
- Vehicle wiring and harness integration
- 12 V automotive-style electrical systems
- Relay logic and fuse-protected circuits
- Ignition-system debugging with ECU behavior
- Shutdown circuit awareness and safety integration
- Technical documentation using schematics, report figures, and firmware

---

## Note on Scope

This repository is a portfolio summary, not the entire Formula SAE project. My individual focus was the paddle-shifting system. I was heavily involved in the ignition-system work, while the harness installation and broader electrical integration work were completed as part of the electrical team.
