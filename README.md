# Head Light Intensity System

This project implements a head light intensity system for a car. The system adjusts the light intensity based on the surrounding lights. It also includes a smoke detection mechanism that turns on an LED when smoke is detected and an obstacle detection mechanism that triggers a buzzer.

## Features

- **Light Intensity Adjustment**: Adjusts the car's headlight intensity based on the surrounding light levels.
- **Smoke Detection**: Turns on an LED when smoke is detected.
- **Obstacle Detection**: Fires a buzzer when an obstacle is detected.

## Setup

1. **Clone the Repository**: Clone this repository to your local machine.
2. **Add FreeRTOS**: Create a folder named `lib` in your workspace and download FreeRTOS from the following link: [FreeRTOS-Kernel](https://github.com/FreeRTOS/FreeRTOS-Kernel). Place the downloaded FreeRTOS in the `lib` folder.

## Configuration

The project uses the Raspberry Pi Pico SDK and FreeRTOS. Ensure that the necessary environment variables and paths are set correctly in the `.vscode/settings.json` file.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.