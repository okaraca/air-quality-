/*
WinsenZH03.h - This library allows you to set and read the ZH03 Winsen Sensor module.
Created by Tomas Leiva , Nov 10, 2017.
*/

// #include <WinsenZH03.h>
// WinsenZH03 sensorZH;



void zh03_setup() {
	//Serial.begin(9600);  //UART to pc
  Serial1.begin(9600); //UART to sensor
  sensorZH.begin(&Serial1);//configure the serial that the sensor will use
   //sensorZH.setAs(QA);//configure the sensor QA mode 
  sensorZH.setAs(ACTIVE);//configure the sensor QA mode 
  // sensorZH.readOnce();//Every time a sample is taken, this function should be set, only in QA.
  sensorZH.wake();

}


void zh03_loop() {
	 sensorZH.readContinus();
   // sensorZH.readOnce();//Every time a sample is taken, this function should be set, only in QA.
 
	 pm1 = sensorZH.readPM1_0();
   pm25 = sensorZH.readPM2_5();
   pm10 = sensorZH.readPM10();

    int  padding_pm1 = tft.textWidth("99.9", 6); // get the width of the text in pixels and font for 4
    tft.setTextColor(TFT_WHITE, TFT_BLACK); // This time we will use green text on a black background
    tft.setTextPadding(padding_pm1);         
         tft.drawNumber(pm1, 220, 220,6);

     //     tft.drawNumber(pm25, 220, 220,6);
     //     tft.drawFloat(pm10, 1, 220, 270,6);
		
	  int  padding_pm10 = tft.textWidth("99.9", 6); // get the width of the text in pixels and font for 4
    tft.setTextColor(TFT_WHITE, TFT_BLACK); // This time we will use green text on a black background
    tft.setTextPadding(padding_pm1);         
     		tft.drawNumber(pm10, 220, 270,6);
		
		Serial.print("PM1.0: ");
		Serial.print(sensorZH.readPM1_0());
    Serial.print("...");
    Serial.print(pm1);
		Serial.println("  ug/m3");
		Serial.print("PM2.5: ");
		Serial.print(sensorZH.readPM2_5());
		Serial.println("  ug/m3");
		Serial.print("PM10: ");
		Serial.print(sensorZH.readPM10());
		Serial.println("  ug/m3");
	 // delay(1000);
}




