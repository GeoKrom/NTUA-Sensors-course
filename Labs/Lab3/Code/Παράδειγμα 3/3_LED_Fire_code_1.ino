int ledPin1 = 9;   //Pin 1ου LED
int ledPin2 = 10;  //Pin 2ου LED
int ledPin3 = 11;  //Pin 3ου LED

void setup() {

  Serial.begin(9600);
  for (int mode = 9; i < 11; i++) {
    pinMode(mode, OUTPUT);
  }
  // pinMode(ledPin1, OUTPUT);     //Ορισμός ως Pin εξόδου
  // pinMode(ledPin2, OUTPUT);     //Ορισμός ως Pin εξόδου
  // pinMode(ledPin3, OUTPUT);     //Ορισμός ως Pin εξόδου
  randomSeed(analogRead(A0));  //Λήψη τυχαίων αριθμών βάσει της εισόδου Α0
}

void loop() {

  for (int ledPin = 9; ledPin < 11; ledPin++) {
    analogWrite(ledPin, random(0, 130) + 125);
  }

  // analogWrite(ledPin1, random(0, 130)); //Τυχαίο duty cycle μεταξύ των τιμών 125 & 255
  // analogWrite(ledPin2, random(0, 130));
  // analogWrite(ledPin3, random(0, 130));
  delay(random(0, 120));  //Τυχαία καθυστέρηση μεταξύ 0 & 120 ms
}