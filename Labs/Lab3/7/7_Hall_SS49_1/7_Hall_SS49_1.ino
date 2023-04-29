int pin = A0;         //Pin εισόδου αισθητήρα Hall
int vcc = 5000;       //Τάση τροφοδοσίας αισθητήρα Hall σε mV

int value;            //Μεταβλητή τιμής στο εύρος 0-1023
int voltage;          //Μεταβλητή τάσης στο εύρος 0-Vcc
int field;            //Μεταβλητή τιμής πεδίου σε mT
int offset = 2534;
void setup() {
  Serial.begin(9600); //Έναρξη σειριακής επικοινωνίας
}

void loop() {
  value = analogRead(pin); //Ανάγνωση τιμής του αισθητήρα Hall
  voltage = value * (vcc / 1024.0); //Μετατροπή σε τιμή τάσης (mV)
  field = map(voltage - offset, 1000 - offset, 4000 - offset, -100, 100); //Υπολογισμός μαγνητικού πεδίου (mT)

  //Εμφάνιση αποτελεσμάτων
  Serial.print("Value: ");
  Serial.print(value);
  Serial.print("\t");
  Serial.print(voltage);
  Serial.println(" mV");
  Serial.print("Magnetic Field: ");
  Serial.print(field);
  Serial.println(" mT");
  Serial.println("==========================");
  delay(1000); //Λήψη νέας τιμής κάθε 1sec
}
