const int builtInLedPin = LED_BUILTIN;
const int buttonPin=2;

const int dot = 200;
const int dash = 3 * dot;
const int DelayMorse = dot;
const int Letter = 3 * dot;

bool ledState=false;
void setup() {
  Serial.begin(9600);
  pinMode(builtInLedPin, OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);

  delay(1500);
}

void loop() {


  Serial.print("LED State: ");
  Serial.println(ledState);
  int buttonState=digitalRead(buttonPin);
  if(buttonState==LOW){
    ledState=!ledState;
    delay(75);
  }

  if (ledState) {
    blinkH();
    blinkA();
    blinkR();
    blinkK();
    blinkA();
    blinkR();
    blinkA();
    blinkN();
  }
}

void onLedChange() {
  Serial.println("LED state changed from IoT Cloud");
}

void blinkDot() {
  digitalWrite(builtInLedPin, HIGH);
  delay(dot);
  digitalWrite(builtInLedPin, LOW);
  delay(DelayMorse);
}

void blinkDash() {
  digitalWrite(builtInLedPin, HIGH);
  delay(dash);
  digitalWrite(builtInLedPin, LOW);
  delay(DelayMorse);
}

void blinkH() {
  blinkDot();
  blinkDot();
  blinkDot();
  blinkDot();
  delay(Letter);
}

void blinkA() {
  blinkDot();
  blinkDash();
  delay(Letter);
}

void blinkR() {
  blinkDot();
  blinkDash();
  blinkDot();
  delay(Letter);
}

void blinkK() {
  blinkDash();
  blinkDot();
  blinkDash();
  delay(Letter);
}

void blinkA() {
  blinkDot();
  blinkDash();
  delay(Letter);
}

void blinkR() {
  blinkDot();
  blinkDash();
  blinkDot();
  delay(Letter);
}

void blinkA() {
  blinkDot();
  blinkDash();
  delay(Letter);
}
void blinkN() {
  blinkDash();
  blinkDot();
  delay(Letter);
}
