# Remote Control Car

An Arduino-based Bluetooth-controlled remote control car.

# Connections
L298N Motor driver
- ENA = 9
- IN1 = 11
- IN2 = 10
- ENB = 13
- IN3 = 6
- IN4 = 5
- GND = GND of arduino and batteries positive terminal
- 12V = Batteries Negative terminal
- 5V = 3.3v
- OUT1 & OUT2 = to the motor1
- OUT3 & OUT4 = to the motor2
  
HC 06
- VCC = 5V
- GND = GND
- TX = RX 0
- RX = TX 1

  
## Components
- Arduino Uno
- HC-05 Bluetooth Module
- L298N Motor Driver
- DC Motors

## How to Use
1. Upload the Arduino sketch.
2. Connect using the HC-05 Bluetooth module.
3. Turn the batteries to use it without pc/laptop.
4. Control the car using a Bluetooth app.

