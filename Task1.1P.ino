// Define pin numbers for the motion sensor and built-in LED
const int motionPin = 2; // Motion sensor output connected to digital pin 2
const int ledPin = LED_BUILTIN; // Built-in LED on Arduino board

void setup() {
  // Set the motion sensor pin as an input
  pinMode(motionPin, INPUT);
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Read the state of the motion sensor
  int motionState = digitalRead(motionPin);

  // Print the motion sensor state to the Serial Monitor
  Serial.print("Motion detected: ");
  Serial.println(motionState);

  // Control the LED based on the motion sensor state
  if (motionState == HIGH) {
    // If motion is detected, turn on the LED
    digitalWrite(ledPin, HIGH);
  } else {
    // If no motion is detected, turn off the LED
    digitalWrite(ledPin, LOW);
  }

  // Wait for 500 milliseconds before repeating the loop
  delay(500);
}
