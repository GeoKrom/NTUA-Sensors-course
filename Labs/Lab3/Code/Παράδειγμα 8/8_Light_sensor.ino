int incomingByte;
int value;
int speaker_pin = 11;
void setup() {
  pinMode(speaker_pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Please enter A for Analog or D for Digital:");
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte == 'A') {
      while (Serial.available() == 0) {
        analog();
      }
    }
    else if (incomingByte == 'D') {
      while (Serial.available() == 0) {
        digital();
      }
    }
    else {
      Serial.println("Unknown command");
    }
  }
}

void analog() {
  value = analogRead(A0);
  Serial.print(value);
  Serial.print("\t");
  int analogValue = map(value, 512, 1023, 100, 1000);
  // analogWrite(speaker_pin, analogValue);
  tone(speaker_pin,analogValue, 200);  
  Serial.println(analogValue);
}

void digital() {
  value = analogRead(A0);
  Serial.print(value);
  Serial.print("\t");
  boolean digitalValue = map(value, 0, 600, HIGH, LOW);
  // digitalWrite(speaker_pin, digitalValue);
  tone(speaker_pin, digitalValue*500, 200);  
  Serial.println(digitalValue);
}
