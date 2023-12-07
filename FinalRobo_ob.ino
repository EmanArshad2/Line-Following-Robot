#define enA 8  // Enable1 L298 Pin enA
#define enB 9  // Enable2 L298
#define in1 5   // Motor1 L298 Pin in1
#define in2 4   // Motor1 L298 Pin in1
#define in3 2   // Motor2 L298 Pin in1
#define in4 3   // Motor2 L298 Pin in1
#define L_S A1  // ir sensor Left
#define R_S A0  // ir sensor Right


void setup() {
  Serial.begin(9600);
  pinMode(L_S, INPUT);
  pinMode(R_S, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(enA, 150);
  analogWrite(enB, 250);
}

/*
 for (int angle = 70; angle <= 140; angle += 5)  {
   servoPulse(servo, angle);  }
 for (int angle = 140; angle >= 0; angle -= 5)  {
   servoPulse(servo, angle);  }
 for (int angle = 0; angle <= 70; angle += 5)  {
   servoPulse(servo, angle);  }
distance_F = Ultrasonic_read();
delay(500);
}*/


void loop() {
  int leftSensor = digitalRead(L_S);
  int rightSensor = digitalRead(R_S);

  Serial.print("Left Sensor: "); Serial.print(leftSensor);
  Serial.print("  Right Sensor: "); Serial.println(rightSensor);

  if (leftSensor == LOW && rightSensor == LOW) {
    // Both sensors are on a white surface
    Stop();
    Serial.println(" - Forward");
  } else if (leftSensor == HIGH && rightSensor == LOW) {
    // Left sensor is on a black surface, turn right
    turnLeft();
    Serial.println(" - Turn Right");
  } else if (leftSensor == LOW && rightSensor == HIGH) {
    // Right sensor is on a black surface, turn left
    turnRight();
    Serial.println(" - Turn Left");
  } else {
    // Both sensors are on a black surface or other cases, stop
    forword();
    Serial.println(" - Stop");
  }

  delay(100);
}

void forword() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
