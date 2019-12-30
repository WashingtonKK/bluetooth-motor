int motorpin1 = 7;
int motorpin2 = 8;
int motorpin3 = 12;
int motorpin4 = 13;
int delayTime = 2;
int flag = 0;
int state = 0;


void setup() {
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(motorpin3, OUTPUT);
  pinMode(motorpin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    state = Serial.read();
    flag = 0;
  }
  if (state == '1') {
    for (int i; i < 1000; i++) {
      digitalWrite(motorpin1, HIGH);
      digitalWrite(motorpin2, LOW);
      digitalWrite(motorpin3, LOW);
      digitalWrite(motorpin4, LOW);
      delay(delayTime);
      digitalWrite(motorpin1, LOW);
      digitalWrite(motorpin2, HIGH);
      digitalWrite(motorpin3, LOW);
      digitalWrite(motorpin4, LOW);
      delay(delayTime);
      digitalWrite(motorpin1, LOW);
      digitalWrite(motorpin2, LOW);
      digitalWrite(motorpin3, HIGH);
      digitalWrite(motorpin4, LOW);
      delay(delayTime);
      digitalWrite(motorpin1, LOW);
      digitalWrite(motorpin2, LOW);
      digitalWrite(motorpin3, LOW);
      digitalWrite(motorpin4, HIGH);
      delay(delayTime);
    }

    if (flag == 0) {
      Serial.println("door open");
      flag = 1;
      state=7;
    }
  }
  if (state == '0') {
    for (int i; i <1000; i++) {

      digitalWrite(motorpin1, LOW);
      digitalWrite(motorpin2, LOW);
      digitalWrite(motorpin3, LOW);
      digitalWrite(motorpin4, HIGH);
      delay(delayTime);
      digitalWrite(motorpin1, LOW);
      digitalWrite(motorpin2, LOW);
      digitalWrite(motorpin3, HIGH);
      digitalWrite(motorpin4, LOW);
      delay(delayTime);
      digitalWrite(motorpin1, LOW);
      digitalWrite(motorpin2, HIGH);
      digitalWrite(motorpin3, LOW);
      digitalWrite(motorpin4, LOW);
      delay(delayTime);
      digitalWrite(motorpin1, HIGH);
      digitalWrite(motorpin2, LOW);
      digitalWrite(motorpin3, LOW);
      digitalWrite(motorpin4, LOW);
      delay(delayTime);

    }
    if (flag == 0) {
      Serial.println("door closed");
      flag = 1;
      state=7;
    }

  }
}
