#include <Arduino.h>

// --- SETTINGS ---
const int IR_TX_PIN = 1; // Safe GPIO pin (do not use 10!)

// Timing Settings
const int CARRIER_FREQ_KHZ = 38;    // 38 kHz Carrier
const int PACKET_RATE_HZ   = 10;    // 10 packets per second rate (10 Hz)
const int BURST_COUNT      = 8;     // Number of packets to send at once (8 times)
const int LONG_WAIT_MS     = 1000;  // Wait time at end of loop (1 second)

// Calculated Values (Automatic)
const int PACKET_PERIOD_MS = 1000 / PACKET_RATE_HZ; // 100 ms period
const int BURST_DURATION_MS = PACKET_PERIOD_MS / 2; // 50% duty cycle (50 ms Signal)

// --- HELPER FUNCTION: Outputs 38 kHz Signal ---
void transmit38kHz(int duration_ms) {
    // For 38 kHz, period ~26 µs (13 µs High / 13 µs Low)
    unsigned long startTime = millis();
    
    while (millis() - startTime < duration_ms) {
        digitalWrite(IR_TX_PIN, HIGH);
        delayMicroseconds(13); 
        digitalWrite(IR_TX_PIN, LOW);
        delayMicroseconds(13);
    }
}

void setup() {
    pinMode(IR_TX_PIN, OUTPUT);
    Serial.begin(115200);
    delay(1000); // Startup safety
    
    Serial.println("--- IR Test Mode Started ---");
    Serial.printf("Speed: %d Hz (Each packet %d ms)\n", PACKET_RATE_HZ, PACKET_PERIOD_MS);
    Serial.printf("Packet Count: %d items\n", BURST_COUNT);
    Serial.println("-------------------------------");
}

void loop() {
    Serial.println("Sending Signal Packet... (8 x High)");

    // 1. Send signal as many times as requested (8 times)
    for (int i = 0; i < BURST_COUNT; i++) {
        unsigned long packetStart = millis();

        // A) Signal Part (38 kHz Carrier Present) - Ex: 50 ms
        transmit38kHz(BURST_DURATION_MS); 

        // B) Silence Part (No Carrier) - Complete the period
        digitalWrite(IR_TX_PIN, LOW);
        
        // Wait for the rest of the 100 ms period
        while (millis() - packetStart < PACKET_PERIOD_MS) {
            // Empty wait (delay can be used instead of busy wait but this is more precise)
            delay(1); 
        }
    }

    // 2. Long Wait (1 Second)
    Serial.println("Waiting... (1 sec)");
    delay(LONG_WAIT_MS);
}