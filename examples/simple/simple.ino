/*
 * --- Program name ---
 * Description
 *  
 * */

// --- Compile-Time Switches ---
// --- Libraries ---
#include <Arduino.h>
#include <Wire.h> 
#include <TMP1075.h>

// --- Constants ---

// --- VARIABLES ---

// --- STRUCTS ---

// --- OBJECTES ---
TMP1075::TMP1075 tmp1075 = TMP1075::TMP1075(Wire,0x4C);  

// ------------------------------------------------------------------------
//                                S E T U P
// ------------------------------------------------------------------------
void setup(){
    Serial.begin(115200);
    while (!Serial);             // Leonardo: wait for Serial monitor
    delay(500);
    Serial.println("TMP1075 Tester");
    Wire.begin();  
    tmp1075.begin();  
    tmp1075.setConversionTime(TMP1075::ConversionTime220ms);
}

// ------------------------------------------------------------------------
//                                L O O P
// ------------------------------------------------------------------------
void loop(){
  uint32_t tS1;
  float tempCur;
  
  tS1 = micros();
  tempCur = tmp1075.getTemperatureCelsius(); 
  tS1= micros() - tS1;
  
  Serial.print("Temp: " + String(tempCur) + "degC in " + String(tS1) + "us" );
  Serial.print("\n");

  delay(500);
}

// ------------------------------------------------------------------------
//                      SUB - ROUTINES
// ------------------------------------------------------------------------

// ........................................................................
