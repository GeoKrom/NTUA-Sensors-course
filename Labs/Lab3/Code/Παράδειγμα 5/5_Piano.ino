int speaker_pin = 11;
int Re_pin = 10;
int Fa_pin = 9;
int Sol_pin = 8;

int notes[] = {294, 349, 392};

void setup() {
  pinMode(Re_pin, INPUT);
  pinMode(Fa_pin, INPUT);
  pinMode(Sol_pin, INPUT);
  pinMode(speaker_pin, OUTPUT);
}

void loop() {
  while (digitalRead(Re_pin) == HIGH)
  {
    tone(speaker_pin, notes[0], 200);
  }
  while (digitalRead(Fa_pin) == HIGH)
  {
    tone(speaker_pin, notes[1], 200);
  }
  while (digitalRead(Sol_pin) == HIGH)
  {
    tone(speaker_pin, notes[2], 200);
  }
}


