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

OLED
- VCC = 5V
- GND = GND
- SDA = A4
- SCK = A5

LED
- CATHODE (-) - 220K RESISTOR - GND
- ANODE (+) - PIN 3
  
## Components
- Arduino Uno
- HC-05 Bluetooth Module
- L298N Motor Driver
- DC Motors
- OLED
- LED


## How to Use
1. Upload the Arduino sketch.
2. Connect using the HC-05 Bluetooth module.
3. Turn the batteries to use it without pc/laptop.
4. Control the car using a Bluetooth app.

## WORKING

1. Open the Arduino Bluetooth app.
2. Choose the remote control car option.
3. Connect the HC - 06 through bluetooth.
4. Control the car with the controller.
 ‘^’    For going forward.
 ‘▼’  For going backwards.
 ‘<’    For turning Left.
 ‘>’    For turning Right.
5. For turning the light.
6. The OLED Display will show animation as the control move
   Like for e.g  ‘O O’ while going forward
   ‘ - - ‘ while going backwards, etc.


