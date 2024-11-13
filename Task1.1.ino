// Define pins for the built-in LED and button
const int builtInLedPin = LED_BUILTIN;
const int buttonPin = 2;

// Define time intervals for Morse code
const int dot = 200;          // Duration of a dot in Morse code (200 ms)
const int dash = 3 * dot;     // Duration of a dash in Morse code (3 times a dot)
const int DelayMorse = dot;   // Time between elements in a letter
const int Letter = 3 * dot;   // Time between letters in Morse code

// Define a variable to store the LED state
bool ledState = false;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  
  // Set LED pin as output and button pin as input with internal pull-up resistor
  pinMode(builtInLedPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  // Short delay before starting
  delay(1500);
}

void loop() {
  // Display current LED state to the serial monitor
  Serial.print("LED State: ");
  Serial.println(ledState);

  // Read the button state (LOW if pressed)
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    // Toggle the LED state if the button is pressed
    ledState = !ledState;
    delay(75);  // Debounce delay for the button press
  }

  // If LED state is true, blink "HARKARAN" in Morse code
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

// Function to handle LED state change from IoT Cloud (not used here)
void onLedChange() {
  Serial.println("LED state changed from IoT Cloud");
}

// Function to blink a dot in Morse code
void blinkDot() {
  digitalWrite(builtInLedPin, HIGH);  // Turn LED on
  delay(dot);                         // Wait for the duration of a dot
  digitalWrite(builtInLedPin, LOW);   // Turn LED off
  delay(DelayMorse);                  // Short delay between elements
}

// Function to blink a dash in Morse code
void blinkDash() {
  digitalWrite(builtInLedPin, HIGH);  // Turn LED on
  delay(dash);                        // Wait for the duration of a dash
  digitalWrite(builtInLedPin, LOW);   // Turn LED off
  delay(DelayMorse);                  // Short delay between elements
}

// Morse code functions for each letter in "HARKARAN"
void blinkH() {
  blinkDot();
  blinkDot();
  blinkDot();
  blinkDot();
  delay(Letter);  // Delay between letters
}

void blinkA() {
  blinkDot();
  blinkDash();
  delay(Letter);  // Delay between letters
}

void blinkR() {
  blinkDot();
  blinkDash();
  blinkDot();
  delay(Letter);  // Delay between letters
}

void blinkK() {
  blinkDash();
  blinkDot();
  blinkDash();
  delay(Letter);  // Delay between letters
}

// Duplicate blinkA function is intentional as 'A' repeats in "HARKARAN"
void blinkA() {
  blinkDot();
  blinkDash();
  delay(Letter);  // Delay between letters
}

// Duplicate blinkR function is intentional as 'R' repeats in "HARKARAN"
void blinkR() {
  blinkDot();
  blinkDash();
  blinkDot();
  delay(Letter);  // Delay between letters
}

// Function to blink "N" in Morse code
void blinkN() {
  blinkDash();
  blinkDot();
  delay(Letter);  // Delay between letters
}
