#include <Arduino.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to enable it.
#endif

BluetoothSerial SerialBT;

#define LED_PIN 12

const int UNIT_TIME = 150; //mms

const char* morseLetters[] = {
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--.."
};

const char* morseNumbers[] = {
    "-----",
    ".----",
    "..---",
    "...--",
    "....-",
    ".....",
    "-....",
    "--...",
    "---..",
    "----."
};

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    if (SerialBT.begin("ESP32 T to MO")) {
        Serial.println("Bluetooth initialized successfully");
        Serial.println("Connect to ESP32 Wrover to Send Messages");
    } else {
        Serial.println("Bluetooth failed");
    }
}

void flashMorseSequence(String sequence) {
    for (int i = 0; i < sequence.length(); i++) {
        char symbol = sequence[i];

        digitalWrite(LED_PIN, HIGH);

        if (symbol == '.') {
            delay(UNIT_TIME);
        } else if (symbol == '-') {
            delay(UNIT_TIME * 3);
        }

        digitalWrite(LED_PIN, LOW);

        if (i < sequence.length() - 1) {
            delay(UNIT_TIME);
        }
    }
}

void translateAndTransmit(String message) {
    message.toUpperCase();

    for (int i = 0; i < message.length(); i++) {
        char c = message[i];
        String morseSymbol = "";
        if (c >= 'A' && c <= 'Z') {
            morseSymbol = morseLetters[c - 'A'];
        } else if (c >= '0' && c <= '9') {
            morseSymbol = morseNumbers[c - '0'];
        } else if (c == ' ') {
            delay(UNIT_TIME * 4);

            SerialBT.print(" / ");
            Serial.print(" / ");
            continue;
        } else {
            continue;
        }

        SerialBT.print(morseSymbol);
        SerialBT.print(" ");
        Serial.print(morseSymbol);
        Serial.print(" ");

        flashMorseSequence(morseSymbol);

        delay(UNIT_TIME * 3);
    }

    SerialBT.println();
    Serial.println();
}

void loop() {
    if (SerialBT.available()) {
        String message = SerialBT.readStringUntil('\n');
        message.trim();

        if (message.length() > 0) {
            Serial.print("Received: ");
            Serial.println(message);
            SerialBT.print("Translating: ");
            SerialBT.println(message);

            translateAndTransmit(message);
        }
    }
    delay(20);
}