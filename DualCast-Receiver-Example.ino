// Example program for RoboticWorx DualCast www.roboticworx.io

#define CONNECTED_TO_PA3 4 // IO1
#define CONNECTED_TO_PA4 5 // IO2
#define CONNECTED_TO_PA5 6 // IO3
#define CONNECTED_TO_PA6 7 // IO4
#define CONNECTED_TO_PA7 15 // IO5
// Connect the pins above to the corresponding pins on the receiver! Change the pin values to whatever matches your setup.

void setup()
{
  // Initialize serial communication for debugging
  Serial.begin(115200);
  
  // Set the defined pins as inputs
  pinMode(CONNECTED_TO_PA3, INPUT);
  pinMode(CONNECTED_TO_PA4, INPUT);
  pinMode(CONNECTED_TO_PA5, INPUT);
  pinMode(CONNECTED_TO_PA6, INPUT);
  pinMode(CONNECTED_TO_PA7, INPUT);

  // Needed to drive motor in example
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
}

// This function reads the 5 GPIO pins and converts them to a binary number (0-31)
// with IO1 as the 1's bit, IO2 as the 2's bit, etc.
// After 100ms (1/10th of a second) since receiving the command, the receiver will set all of these back to LOW. 
int readBinaryInput()
{
  int value = 0;
  value |= digitalRead(CONNECTED_TO_PA3) << 0;  // IO1 -> bit 0 (1's place)
  value |= digitalRead(CONNECTED_TO_PA4) << 1;  // IO2 -> bit 1 (2's place)
  value |= digitalRead(CONNECTED_TO_PA5) << 2;  // IO3 -> bit 2 (4's place)
  value |= digitalRead(CONNECTED_TO_PA6) << 3;  // IO4 -> bit 3 (8's place)
  value |= digitalRead(CONNECTED_TO_PA7) << 4;  // IO5 -> bit 4 (16's place)
  return value;
}

void loop()
{
  // Read the binary number formed by the 5 GPIO inputs.
  int binaryNumber = readBinaryInput();
  
  // Print the result to the Serial Monitor.
  Serial.print("Binary input: ");
  Serial.println(binaryNumber);

  // if (binaryNumber == whatever) 
    // do something...
  
  // Small delay to prevent spamming prints
  delay(25);

  // Example:
  if (binaryNumber == 8) // If received an 8
  {
    digitalWrite(18, HIGH); // Move motor CW for 5 sec (connected to motor driver)
    digitalWrite(17, LOW);

    delay(5000);

    digitalWrite(18, HIGH); // Stop motor for 3 sec
    digitalWrite(17, HIGH);

    delay(3000);

    digitalWrite(18, LOW); // Move motor back CCW for 5 sec
    digitalWrite(17, HIGH);

    delay(5000);

    digitalWrite(18, HIGH); // Stop motor
    digitalWrite(17, HIGH);

    // By the time we have gotten here, the pins have already reset and are ready for the next command. (Been longer than 100ms)
  }

}
