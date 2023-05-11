int pin = A0;         //Pin εισόδου αισθητήρα Hall
int vcc = 5000;       //Τάση τροφοδοσίας αισθητήρα Hall σε mV

int value;            //Μεταβλητή τιμής στο εύρος 0-1023
int voltage;          //Μεταβλητή τάσης στο εύρος 0-Vcc
int field;            //Μεταβλητή τιμής πεδίου σε mT
int offset = 250;    //Μεταβλητή τάσης offset mV
//int field_offset = -17; //Μεταβλητή τιμής πεδίου offset σε mT
int Led = 8;

void setup() {
  Serial.begin(9600); //Έναρξη σειριακής επικοινωνίας
  pinMode(Led,OUTPUT);
}

void loop() {
  value = analogRead(pin); //Ανάγνωση τιμής του αισθητήρα Hall
  voltage = value * (vcc / 1024.0); //Μετατροπή σε τιμή τάσης (mV)
  field = map(voltage+offset, 1000, 4000, -100, 100); //Υπολογισμός μαγνητικού πεδίου (mT)
  if(abs(field)>5){
    digitalWrite(Led,LOW);
  }else{
    digitalWrite(Led,High);
  }

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
  delay(100); //Λήψη νέας τιμής κάθε 100msec
}
