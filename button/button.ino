constexpr uint8_t BUTTON_PIN = 2;

class ButtonToggleState {
 public:
  ButtonToggleState(const uint8_t button_pin) :
    button_pin_(button_pin), state_(false), last_state_(false)
  {}

  void poll() {
    const bool curr_state = buttonDown();
    if (last_state_ == false && curr_state == true) { state_ = !state_; }
    last_state_ = curr_state;
  }

  bool active() const { return state_; }
 private:
  bool buttonDown() const { return digitalRead(button_pin_) == HIGH; }

  const uint8_t button_pin_;
  bool state_, last_state_;
};


ButtonToggleState buttonState(BUTTON_PIN);

// LED?
// constexpr uint8_t LED_OUT_PIN = 4;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT);
//   pinMode();
}

void loop() {
  buttonState.poll();
  Serial.println(buttonState.active());
  delay(10);
}
