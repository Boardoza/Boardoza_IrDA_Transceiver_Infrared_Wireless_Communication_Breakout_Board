#include <Arduino.h>

// --- SETTINGS ---
const int IR_RX_PIN = 2; // IR Receiver OUT/DATA pin

// Variable to track the last known state
int lastState = -1; 

void setup() {
    // Enable internal pull-up resistor for stability
    pinMode(IR_RX_PIN, INPUT_PULLUP);
    
    Serial.begin(115200);
    delay(1000); // Startup safety
    
    Serial.println("--- IR Receiver Mode Started ---");
    Serial.println("Waiting for signal (1 = Signal, 0 = No Signal)...");
    Serial.println("--------------------------------------------------");
}

void loop() {
    // Read the raw pin state
    // Standard IR receivers output LOW when receiving a 38kHz signal
    int rawState = digitalRead(IR_RX_PIN);
    
    // Convert logic: 1 for Signal Present, 0 for No Signal
    int signalPresent = (rawState == LOW) ? 1 : 0;

    // Only print if the state has changed to prevent Serial Monitor spam
    if (signalPresent != lastState) {
        Serial.println(signalPresent);
        
        // Update the last state
        lastState = signalPresent;
    }
    
    // Small delay to prevent processor overload
    delay(1);
}