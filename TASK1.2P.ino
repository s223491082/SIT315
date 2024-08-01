// Define pin constants
const int motionSensorPin = 2; // Pin connected to the motion sensor output
const int ledPin = 13;         // Built-in LED on the Arduino board

// Variable to store the motion status
volatile bool motionDetected = false;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the LED pin as output
  pinMode(ledPin, OUTPUT);

  // Attach interrupt to the motion sensor pin
  attachInterrupt(digitalPinToInterrupt(motionSensorPin), motionISR, RISING);
}

void loop() {
  // Check if motion is detected
  if (motionDetected) {
    // Print the motion status to the Serial Monitor
    Serial.println("Motion detected!");

    // Turn on the LED
    digitalWrite(ledPin, HIGH);

    // Reset the motionDetected flag
    motionDetected = false;
  } else {
    // Turn off the LED if no motion is detected
    digitalWrite(ledPin, LOW);
  }

  // Optional: Add a small delay
  delay(500);
}

// Interrupt Service Routine (ISR) for motion detection
void motionISR() {
  motionDetected = true;
}

