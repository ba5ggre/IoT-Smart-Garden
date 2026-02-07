# IoT-Smart-Garden
This project is a modular automated gardening system built on the ESP32 platform. It monitors environmental conditions (Temperature, Humidity, Light, and Water Quality) and features a web-based dashboard to remotely control a sunlight shield via a Servo motor.
# Key Features
- Modular Architecture: Code is split into specific modules (Web, Sensors, Servo) for better maintainability.
- Real-time Monitoring: Asynchronous web server provides live updates on garden stats.
- Wireless Shield Control: Interactive web slider to adjust the sunshade angle remotely.
- Smart Data Processing: Uses ESP32's dual-core capabilities for smooth web handling and sensor reading.
# File Structure
- main.ino: Main logic, WiFi configuration, and Web Server routes.
- web_pages.h: Contains HTML, CSS, and JavaScript for the browser interface.
- sensor_modules.h: Handles initialization and data acquisition for all sensors.
- servo_control.h: Manages the PWM signals for the sunshade servo motor.
