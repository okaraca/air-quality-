// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc; 
// RTC_DS1307 rtc;


char daysOfTheWeek[7][10] = {"Pazar ", "Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma", "Cumartesi"};

//*********************************
//*********************************
void ds3231_setup ()  {
#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif
rtc.begin ();
    delay(1000); // wait for console opening
   
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
  
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
 //  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  }
//*********************************
void ds3231_tft_loop () {
   
    DateTime now = rtc.now();
    
//****************************

  tft.setTextColor(TFT_GREEN, TFT_BLACK);   

//test for the date
char tft_date [12];
sprintf(tft_date, "%02d:%02d:%4d", now.day(),now.month(),now.year());
tft.drawString(tft_date, 305, 5, 4);
 int  padding = tft.textWidth("999999999", 4); // get the width of the text in pixels and font for 4
 tft.setTextColor(TFT_GREEN, TFT_BLACK);
 tft.setTextPadding(padding);  
  
char tft_day [9];
sprintf(tft_day, "%9s", daysOfTheWeek[now.dayOfTheWeek()]); //"%12s"
tft.drawCentreString(tft_day, 365, 30, 4);
// tft.drawRightString(tft_day, 395, 30, 4);

 tft.setTextPadding(0); // Setting to zero switches off padding

char tft_time [12];
   sprintf(tft_time, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
   tft.drawString(tft_time, 50, 5, 7);
  // Serial.println(tft_date);

}

