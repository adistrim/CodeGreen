// Include the necessary library
#include <ESP8266WiFi.h>

// Define the LED pins
const int ledPin1 = D1;
const int ledPin2 = D2;
const int ledPin3 = D3;
const int ledPin4 = D4;
const int ledPin5 = D5;

// Define the number of rounds before turning on D5
const int roundsBeforeD5 = 4;
int roundCount = 0;

void setup() {
    // Initialize the LED pins as OUTPUT
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(ledPin4, OUTPUT);
    pinMode(ledPin5, OUTPUT);
}

void loop() {
    // Check if it's time to turn on D5
    if (roundCount >= roundsBeforeD5) {
        // Turn on D5 for 3 seconds
        digitalWrite(ledPin5, HIGH);
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        delay(3000);  // 3 seconds
        digitalWrite(ledPin5, LOW);
        roundCount = 0;  // Reset the round count
    } else {
        // Turn on LEDs 1 and 3 while turning off LEDs 2 and 4
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, LOW);

        // Wait for 1 second
        delay(1000);

        // Turn off LEDs 1 and 3 while turning on LEDs 2 and 4
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin4, HIGH);

        // Wait for 1 second
        delay(1000);

        roundCount++;  // Increment the round count
    }
}
