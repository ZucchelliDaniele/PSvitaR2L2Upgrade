//FROM https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>

// Pin definitions for analog inputs
const int R2_PIN = 10; // Analog pin for R2
const int L2_PIN = 18; // Analog pin for L2
const int R3_PIN = 7;
const int L3_PIN = 5;

// Create an instance of the Joystick class
Joystick_ Joystick;

void setup() {
  // Initialize the Joystick library with default configuration
  Joystick.begin();

  // Initialize analog pins
  pinMode(R2_PIN, INPUT);
  pinMode(L2_PIN, INPUT);
  pinMode(R3_PIN, INPUT);
  pinMode(L3_PIN, INPUT);

  // Print setup info to Serial Monitor
  Serial.begin(9600);
  Serial.println("Setup complete. Starting joystick simulation.");
}

void loop() {
  // Read and map the analog value for R2
  int R2Value = analogRead(R2_PIN);
  R2Value = map(R2Value, 170, 500, 0, 255); // Adjust map range for R2
  R2Value = constrain(R2Value, 0, 255); // Ensure value is within 0-255 range

  // Read and map the analog value for L2
  int L2Value = analogRead(L2_PIN);
  L2Value = map(L2Value, 170, 500, 0, 255); // Adjust map range for L2
  L2Value = constrain(L2Value, 0, 255); // Ensure value is within 0-255 range
  
  Joystick.setRxAxisRange(0, 255);
  Joystick.setRyAxisRange(0, 255);
  // Update the analog axes (assuming you use X and Y axes)
  Joystick.setRxAxis(L2Value); // Set the analog value for the X axis
  Joystick.setRyAxis(R2Value); // Set the analog value for the Y axis

  int R3Value = digitalRead(R3_PIN);
  Joystick.setButton(1, R3Value);

  int L3Value = digitalRead(L3_PIN);
  Joystick.setButton(0, L3Value);

  // Print the results to the Serial Monitor
  Serial.print("L2: ");
  Serial.print(L2Value);
  Serial.print(" - R2: ");
  Serial.print(R2Value);
  Serial.print(" - L3: ");
  Serial.print(L3Value);
  Serial.print(" - R3: ");
  Serial.println(R3Value);

  // Wait for 20 milliseconds before the next loop
  delay(20);
}