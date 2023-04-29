int ledPin1 = 9;   //Pin 1ου LED
int ledPin2 = 10;  //Pin 2ου LED
int ledPin3 = 11;  //Pin 3ου LED
int ledPin4 = 3;   //Pin 4ου LED
int ledPin5 = 5;   //Pin 5ου LED
int ledPin6 = 6;   //Pin 6ου LED

const int pinArray[6] = { ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6 };
void setup() {

  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(pinArray[i], OUTPUT);
  }
  // pinMode(ledPin1, OUTPUT);     //Ορισμός ως Pin εξόδου
  // pinMode(ledPin2, OUTPUT);     //Ορισμός ως Pin εξόδου
  // pinMode(ledPin3, OUTPUT);     //Ορισμός ως Pin εξόδου
  randomSeed(analogRead(A0));  //Λήψη τυχαίων αριθμών βάσει της εισόδου Α0
}

void loop() {

  for (int i = 0; i < 6; i++) {
    analogWrite(pinArray[i], random(0, 120) + 75);
  }

  // analogWrite(ledPin1, random(0, 130)); //Τυχαίο duty cycle μεταξύ των τιμών 125 & 255
  // analogWrite(ledPin2, random(0, 130));
  // analogWrite(ledPin3, random(0, 130));
  delay(random(0, 120));  //Τυχαία καθυστέρηση μεταξύ 0 & 120 ms
}