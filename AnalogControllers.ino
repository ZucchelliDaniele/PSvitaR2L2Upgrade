//FROM https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>

// Pin definitions for analog inputs
const int R2_PIN = A3; // Analog pin for R2
const int L2_PIN = A2; // Analog pin for L2

// Create an instance of the Joystick class
Joystick_ Joystick;

void setup() {
  // Initialize the Joystick library with default configuration
  Joystick.begin();

  // Initialize analog pins
  pinMode(R2_PIN, INPUT);
  pinMode(L2_PIN, INPUT);

  // Print setup info to Serial Monitor
  Serial.begin(9600);
  Serial.println("Setup complete. Starting joystick simulation.");
}

void loop() {
  // Read and map the analog value for R2
  int R2Value = analogRead(R2_PIN);
  R2Value = map(R2Value, 170, 400, 0, 255); // Adjust map range for R2
  R2Value = constrain(R2Value, 0, 255); // Ensure value is within 0-255 range

  // Read and map the analog value for L2
  int L2Value = analogRead(L2_PIN);
  L2Value = map(L2Value, 169, 700, 0, 255); // Adjust map range for L2
  L2Value = constrain(L2Value, 0, 255); // Ensure value is within 0-255 range
  
  Joystick.setRxAxisRange(0, 255);
  Joystick.setRyAxisRange(0, 255);
  // Update the analog axes (assuming you use X and Y axes)
  Joystick.setRxAxis(L2Value); // Set the analog value for the X axis
  Joystick.setRyAxis(R2Value); // Set the analog value for the Y axis

  // Print the results to the Serial Monitor
  Serial.print("L2: ");
  Serial.print(L2Value);
  Serial.print(" - R2: ");
  Serial.println(R2Value);

  // Wait for 20 milliseconds before the next loop
  delay(20);
}
