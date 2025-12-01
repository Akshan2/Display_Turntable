#include "Stepper.h"

const int steps_per_revolution=200;

// Initializing the stepper library on pins 6 through 9:
Stepper myStepper = Stepper(steps_per_revolution,6,7,8,9);

// Defining the pin for the analog signal:
const int analog_pin=A0;

void setup() {
  // Begin serial communication for debugging:
  Serial.begin(9600);
}

void loop() {
  // Read analog input (0 to 1023):
  int analog_value = analogRead(analog_pin);

  // Map analog value to a speed range (1 to 200 RPM):
  int motor_speed = map(analog_value, 0, 1023, 1, 200);

  // Set the motor speed:
  myStepper.setSpeed(motor_speed);

  // Print the speed for debugging (optional):
  Serial.print("Analog Value: ");
  Serial.print(analog_value);
  Serial.print(" -> Motor Speed: ");
  Serial.println(motor_speed);

  // Step the motor continuously in one direction:
  myStepper.step(steps_per_revolution);
}
