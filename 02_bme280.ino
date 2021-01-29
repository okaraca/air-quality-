
//*********************************
void bme280_setup()
{
 // Serial.begin(9600);
  while(!Serial);
  Serial.println("Reading basic values BME280     ");

  Wire.begin();

  if (mySensor.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("The chip did not respond. Please check wiring.");
    while(1); //Freeze
  }
}



void bme280_loop()
 {
   // -------------BME 280 readings
 f_temperature = mySensor.readTempC();
 f_humidity = mySensor.readFloatHumidity();
 f_pressure = mySensor.readFloatPressure();
  

 tft.setTextColor(TFT_CYAN, TFT_BLACK); // This time we will use green text on a black background
    tft.setCursor (5, 80);
    tft.setTextFont(7);        // Select font 1 which is the Adafruit GLCD font
    tft.print(f_temperature);
 
    // min&max definitions for temperature
tft.setTextColor(TFT_WHITE, TFT_BLACK); 

if(f_temperature < min_temperature)
    {
     min_temperature = f_temperature;
     tft.drawFloat(min_temperature,2, 165, 80, 4);//  tft.drawFloat(test, decimal_places, x, y, font);
    }
if(f_temperature > max_temperature)
    {
     max_temperature = f_temperature;
     tft.drawFloat(max_temperature,2, 165, 110, 4);//  tft.drawFloat(test, decimal_places, x, y, font);
    }
//**** humidity

    tft.setTextColor(TFT_CYAN, TFT_BLACK); // This time we will use green text on a black background
    tft.setCursor (5, 140);// Adding a background colour erases previous text automatically
    tft.setTextFont(7);        // Select font 1 which is the Adafruit GLCD font
    tft.print(f_humidity);

 // min&max definitions for humidty
    tft.setTextColor(TFT_WHITE, TFT_BLACK); 

if(f_humidity < min_humidity)
    {
     min_humidity = f_humidity;
     tft.drawFloat(min_humidity,2, 165, 140, 4);//  tft.drawFloat(test, decimal_places, x, y, font);
    }
if(f_humidity > max_humidity)
    {
     max_humidity = f_humidity;
     tft.drawFloat(max_humidity,2, 165, 170, 4);//  tft.drawFloat(test, decimal_places, x, y, font);
    }
 } 
  


/*

void bme280_loop()
{
  Serial.print("Humidity: ");
  Serial.print(mySensor.readFloatHumidity(), 0);
 float ftemp = mySensor.readTempC();
  Serial.print(" Pressure: ");
  Serial.print(mySensor.readFloatPressure(), 0);

  Serial.print(" Alt: ");
  Serial.print(mySensor.readFloatAltitudeMeters(), 1);
 // Serial.print(mySensor.readFloatAltitudeFeet(), 1);

  Serial.print(" Temp: ");
  Serial.print(ftemp, 2);
  Serial.print(mySensor.readTempC(), 2);
 // Serial.print(mySensor.readTempF(), 2);

  Serial.println();

  delay(50);
}
*/
