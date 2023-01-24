#include <Arduino.h>
#include <Wire.h>
#include <cstring>
#include <string>
#include <iostream>

#define I2C_SDA 21
#define I2C_SCL 22

#define SEALEVELPRESSURE_HPA (1013.25)

TwoWire I2CBME = TwoWire(0);

const int delay_time = 50;

int count = 65;

void setup() {
    Serial.begin (115200);
    Wire.begin(I2C_SDA, I2C_SCL);
    Wire.beginTransmission(0x63);
    Wire.write(0x00);
}

void initialization_lcd(){
    
}

void displayON(){
    Wire.write(19);
    Wire.endTransmission();
}

void displayOff(){
    Wire.write(20);
    Wire.endTransmission();
}

void display(std::string s){ //uint8_t characters[], int length, 
    const int length = s.length();
 
    // declaring character array (+1 for null terminator)
    char* char_array = new char[length + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());
 
    for (int i = 0; i < length; i++)
    {
        std::cout << char_array[i];
        Wire.endTransmission();
    }
}

static bool initialized = false;

void loop() {
    if (!initialized) {
        initialized = true;
        display("hello world");
    }
}