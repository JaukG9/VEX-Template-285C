# VEX V5 Template

A starting-point VEX V5 robot code template built by Team 285C (Discobots Chaos), using [PROS](https://pros.cs.purdue.edu/) as the runtime/build system and [LemLib](https://lemlib.readthedocs.io/en/stable/) for odometry and PID-based motion control.

This is a **template repo**, not a finished robot program. Motor ports, drivetrain dimensions, sensor ports, and PID gains are intentionally left blank or zeroed out. The goal is to skip re-writing the same competition boilerplate (lifecycle callbacks, drivetrain/odometry setup, an autonomous selector) at the start of every season and instead start from a working skeleton.

## What's Included

- **PROS competition scaffolding in `main.cpp`:** `initialize()`, `disabled()`, `competition_initialize()`, `autonomous()`, `opcontrol()`
- **LemLib (v0.5.6) already included:** motor groups, `lemlib::Drivetrain`, `lemlib::Chassis`, odometry sensors, lateral/angular PID controllers, and a steering curve
- Tank drive implemented out of the box in `functions.cpp`, with a spot to add arcade or other control schemes
- A lightweight touchscreen autonomous selector (`autonSelector()` + a small `Button` class) that lets you pick Left / Right / Skills / Skip on the Brain screen, then one of up to 4 routines per side
- Code organized into small, single-responsibility modules under `robot/` instead of one large `main.cpp`

## Project Structure

```
.
├── include/
│   ├── robot/
│   │   ├── autos.h             # Button class + autonomous routine declarations
│   │   ├── drivetrain.h
│   │   ├── functions.h
│   │   ├── odometry.h
│   │   └── robot-config.h
│   ├── lemlib/                 # LemLib headers (vendored)
│   └── pros/                   # PROS kernel headers (vendored)
├── src/
│   ├── main.cpp                # competition lifecycle callbacks
│   └── robot/
│       ├── autos.cpp           # skills(), skip(), autonSelector()
│       ├── drivetrain.cpp      # motor groups + lemlib::Drivetrain
│       ├── functions.cpp       # tank() drive, plus any custom robot functions
│       ├── odometry.cpp        # IMU, tracking sensors, PID gains, chassis
│       └── robot-config.cpp    # controller + motor/sensor/pneumatic declarations
├── firmware/                   # PROS + LemLib compiled libraries (vendored)
├── project.pros                # PROS project/template metadata
├── Makefile / common.mk        # PROS build configuration
└── README.md
```

## Prerequisites

- [VS Code](https://code.visualstudio.com/) with the [PROS extension](https://pros.cs.purdue.edu/v5/getting-started/vscode-install.html) installed (the standalone PROS CLI also works)
- A VEX V5 Brain and Controller with VEXos updated to match the PROS kernel this project targets (kernel 4.2.2, per `project.pros`)
- Working C++ knowledge (this template assumes familiarity with PROS/LemLib basics, not a tutorial for either)

## Using this Template

1. Click **"Use this template"** on GitHub (or clone the repo) to start a new project from this base.
2. Open the folder in VS Code with the PROS extension (it will pick up `project.pros` automatically).
3. Rename the project if you'd like (`project.pros` currently registers it as `"V5 Template"`).
4. Go through the **Configuring for Your Robot** checklist below before you try to drive anything.
5. Build and upload:
   - VS Code: use the PROS extension's **Build** and **Upload** buttons
   - CLI: `pros make` then `pros upload`

## Configuring for Your Robot

Everything below is left as a placeholder on purpose. Fill these in before the code will actually move your robot:

- **`src/robot/robot-config.cpp`:** currently empty. Declare your motors, pneumatics, and any other devices here (a `pros::Controller` is already declared for you).
- **`src/robot/drivetrain.cpp`:** set the ports in `left_mg` / `right_mg`, the track width, wheel size/type, drivetrain RPM, and horizontal drift value.
- **`src/robot/odometry.cpp`:** set the real IMU port (placeholder is port `1`), wire up any tracking wheels/encoders in `sensors`, and tune `lateral_controller` / `angular_controller` (all gains start at `0`). LemLib's [PID tuning guide](https://lemlib.readthedocs.io/en/stable/tutorials/4_pid_tuning.html) is linked directly in the code comments.
- **`src/robot/autos.cpp`:** implement `skip()`, `skills()`, and any additional autonomous routines, then update the `autonType`, `leftAutons`, and `rightAutons` button arrays in `autonSelector()` to match your actual autos.
- **`src/robot/functions.cpp`:** `tank()` is implemented by default; add arcade drive or other control schemes here if you'd rather use those.
- **`src/main.cpp`:** wire each of your autonomous routines into the `switch` statement inside `autonomous()`.

## Autonomous Selector

`autonSelector()` (in `autos.cpp`) draws a two-stage menu on the Brain's touchscreen:

1. First screen: choose **Left**, **Right**, **Skills**, or **Skip**.
2. If Left/Right was chosen, a second screen offers up to 4 preset routines for that side.

The result is stored in the global `autonomousSelection`, which `autonomous()` in `main.cpp` reads to call the matching function. Button position, size, text, and color are all set directly in the `autonType` / `leftAutons` / `rightAutons` arrays. There's a commented-out example at the top of `autonSelector()` showing the constructor signature.

## Credits

Built by Ayaan Goswami for Team 285C, on top of [PROS](https://pros.cs.purdue.edu/) and [LemLib](https://lemlib.readthedocs.io/en/stable/).