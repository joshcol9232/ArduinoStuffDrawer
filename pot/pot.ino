constexpr uint8_t LED_PIN = 3;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

float potentiometer_percent(const int val, const int max_val = 1023) {
  return (float)val / (float)max_val;
}

void set_led(const float brightness) {
  analogWrite(LED_PIN, (int)(brightness * 255.0));
}

void loop() {
  constexpr uint8_t read_pin = A0;

  const int reading = analogRead(read_pin);
  const float level = potentiometer_percent(reading);
  Serial.println(level);
  set_led(level);

  delay(10);
}
