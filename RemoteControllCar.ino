#define IN1 11
#define IN2 10
#define IN3 6
#define IN4 5
#define ENA 9
#define ENB 13

int x;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0){
    x = Serial.read();

  switch (x){
    case 'F' :
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 255);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN3, LOW);
    analogWrite(ENB, 255);
    break;

    case 'B' :
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, 255);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, HIGH);
    analogWrite(ENB, 255);
    break;

    case 'L' :
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, 255);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, LOW);
    analogWrite(ENB, 0);
    break;

    case 'R' :
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, HIGH);
    analogWrite(ENB, 255);
    break;

    default :
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 0);

    break;
  }  
 }
}
