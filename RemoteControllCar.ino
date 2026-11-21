#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 7
#define ENB 12
#define LED 3
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

int x;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Eye positions
int leftEyeX = 20;
int rightEyeX = 76;
int eyeY = 18;

int eyeWidth = 32;
int eyeHeight = 28;

void drawEyes(int pupilOffset, bool closed) {

  display.clearDisplay();

  if (closed) {
    display.drawLine(leftEyeX, eyeY + 14,
                     leftEyeX + eyeWidth, eyeY + 14,
                     SSD1306_WHITE);

    display.drawLine(rightEyeX, eyeY + 14,
                     rightEyeX + eyeWidth, eyeY + 14,
                     SSD1306_WHITE);
  }
  else {
    display.fillRoundRect(
      leftEyeX, eyeY,
      eyeWidth, eyeHeight,
      8, SSD1306_WHITE
    );


    display.fillRoundRect(
      rightEyeX, eyeY,
      eyeWidth, eyeHeight,
      8, SSD1306_WHITE
    );

    // Pupils
    display.fillCircle(
      leftEyeX + 16 + pupilOffset,
      eyeY + 14,
      7,
      SSD1306_BLACK
    );

    display.fillCircle(
      rightEyeX + 16 + pupilOffset,
      eyeY + 14,
      7,
      SSD1306_BLACK
    );
  }

  display.display();
}

void setup() {
  display.begin(
    SSD1306_SWITCHCAPVCC,
    0x3C
  );

  display.clearDisplay();
  display.display();

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0){
    x = Serial.read();

  switch (x){
    case 'F' :
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(ENA, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(ENB, HIGH);
    drawEyes(0, false);
    break;

    case 'B' :
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(ENA, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(ENB, HIGH);
    drawEyes(0, true);
    break;

    case 'L' :
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(ENA, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(ENB, HIGH);
    drawEyes(-8, false);
    break;

    case 'R' :
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(ENA, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(ENB, LOW);
    drawEyes(8, false);
    
    break;

    case 'X' :
    digitalWrite(LED, HIGH);
    break;
    
    case 'Y' :
    digitalWrite(LED, LOW);
    break;

    default :
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(ENA, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(ENB, LOW);
    drawEyes(0, false);
    break;
  }  
 }
}
