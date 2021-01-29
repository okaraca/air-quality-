#define TFT_GREY 0x7BEF
// ********** https://github.com/Bodmer/TFT_HX8357
//#define TFT_GREY 0x5AEB // New colour

#include <TFT_HX8357.h> // Hardware-specific library

TFT_HX8357 tft = TFT_HX8357();       // Invoke custom library

#include "Wire.h"

#include "SparkFunBME280.h"
BME280 mySensor; //Global sensor object

uint16_t color ;
uint16_t color_a ;
float f_temperature ;
float f_humidity;
float f_pressure;

float max_temperature =0.0 ;
float min_temperature =100.0;
float max_humidity =0.0 ;
float min_humidity =100.0;


#include <MH_Z19.h>

#define CO2_PWM_PIN 6 //6
#define CO2_UART_TX_PIN 9
#define CO2_UART_RX_PIN 10

MH_Z19 co2(CO2_PWM_PIN, CO2_UART_TX_PIN, CO2_UART_RX_PIN);

int pwm;
float max_pwm =100.0 ;

//*********** timer
// loop timer definitions
/* Two "independant" timed events */
const long eventTime_1_oled = 1000; //in ms
int say=0;
/* When did they start the race? */
unsigned long previousTime_1 = 0;

// *********definitiosn for SD micro card
#include <SPI.h> //for the SD card module
#include <SD.h> // for the SD card

// change this to match your SD shield or module;
// Arduino Ethernet shield and modules: pin 4
// Arduino Mega  modules: pin 53
// Data loggin SD shields and modules: pin 10
// Sparkfun SD shield: pin 8

const int chipSelect = 4; //53 or 10 or 4
// Create a file to store the data
File myFile;

// ********** definitions for outside bme280&ccs811

  char tft_co2 [5];
  char tft_tvoc [5];
  float sd_tt ;
  float sd_rh ;
  int sd_co2 ;
  int sd_tvoc ;
  int max_sd_co2 = 100 ;
  
// ************* definition for SDS021 or ZH03
// #include <SoftwareSerial.h>
// SoftwareSerial particleSensor(A14, A15); // RX, TX


#include <WinsenZH03.h>
WinsenZH03 sensorZH;

float pm1 ; // 1um particles detected in ug/m3
float pm25; //2.5um particles detected in ug/m3
float pm10; //10um particles detected in ug/m3
float max_pm10 = 0.0;
float max_pm25 = 0.0;

