#include "max6675.h"

// Define the pins for the MAX6675 module
int thermoDO = 4;  // SO (Serial Out)
int thermoCS = 5;  // CS (Chip Select)
int thermoCLK = 6; // SCK (Serial Clock)

// Create an instance of the MAX6675 library
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  Serial.println("MAX6675 Thermocouple Test");
  
  // Give the sensor time to stabilize
  delay(500);
}

void loop() {
  // Read the temperature from the MAX6675
  double temperature = thermocouple.readCelsius();
  
  // Print the temperature to the serial console
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  // Wait for a second before the next reading
  delay(1000);
}
