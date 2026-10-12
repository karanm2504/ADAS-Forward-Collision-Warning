
# ADAS Forward Collision Warning Simulation

A C-based Forward Collision Warning (FCW) simulation developed to explore automotive embedded software concepts, vehicle dynamics, and Time-to-Collision (TTC) analysis.

## Overview

The system estimates potential forward collision risks by calculating the relative closing speed between an ego vehicle and a lead vehicle.

Based on the calculated TTC, the system classifies driving conditions as SAFE, WARNING, or CRITICAL.

## Implemented Features

- Relative closing-speed calculation
- Speed conversion from km/h to m/s
- Time-to-Collision (TTC) estimation
- Three-level collision warning classification
- Handling of zero and negative closing speeds
- Modular C functions for TTC calculation and warning output

## Technical Approach

The simulation uses the following equations:

    Closing Speed = Ego Speed - Lead Speed

    TTC = Distance / (Closing Speed / 3.6)

TTC is calculated when closing speed is positive. Otherwise, the function returns `-1.0f`.

The implementation uses two main functions:

- `calculateTTC()` — Computes the estimated collision time.
- `checkWarning()` — Classifies TTC into SAFE, WARNING, or CRITICAL.

Warning thresholds are illustrative and not calibrated for real-world vehicle safety.

## Build and Run

**Requirements:** GCC compiler with C11 support.

Compile:

    gcc -Wall -Wextra -std=c11 ttc_calculator.c -o ttc_calculator

Run:

    ./ttc_calculator

## Technologies

- Embedded C fundamentals (C11)
- GCC
- Linux / Ubuntu WSL
- Git and GitHub

## Project Status

**Initial implementation completed.**

Current development focuses on extending the simulation with:

- Input validation and boundary testing
- Python-based automated testing
- Simulated emergency braking decisions
- Structured test reporting


