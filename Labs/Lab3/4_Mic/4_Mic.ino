const byte micPin = A0;
int led_index;
int mic_offset = 750;
int mic = 0;

int led[6] = {2, 3, 4, 5, 6, 7};
int led_number = sizeof(led) / sizeof(led[0]);

void setup() {
  for (int i = 0; i < led_number; i++) {
    pinMode(led[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  mic = analogRead(micPin);
  Serial.println(mic);
  if (mic > mic_offset) {
    led_index = map(mic, mic_offset, 1023, 0, led_number - 1);

    for (int i = 0; i <= led_index; i++) {
      digitalWrite(led[i], HIGH);
    }
    for (int i = led_index + 1; i < led_number; i++) {
      digitalWrite(led[i], LOW);
    }
  }
  else {
    for (int i = 0; i < led_number; i++) {
      digitalWrite(led[i], LOW);
    }
  }
}
