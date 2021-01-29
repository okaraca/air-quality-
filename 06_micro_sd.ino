// sd card setup 
void sd_setup(){
    
 // setup for the SD card
  Serial.print("Initializing SD card...");

 // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {

 // if(!SD.begin(chipSelect)) {  // original mega
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  
  //open file
  myFile=SD.open("okuma.csv", FILE_WRITE); 

  // if the file opened ok, write to it:
  if (myFile) {
    Serial.println("File opened ok");
    // print the headings for our data
    myFile.println("Date, Time,  RHum,Temperature ºC, pressure (pascal), co2_pwm, pm2.5, pm10");
  }
  myFile.close();//
 delay(2500);

  
}


// *********************buradan --> sd logging
void sd_logging() {
  DateTime now = rtc.now();
  myFile = SD.open("okuma.csv", FILE_WRITE);
  if (myFile) {
   char sd_datetime [20];
   sprintf(sd_datetime, "%02d:%02d:%4d,%02d:%02d:%02d", now.day(),now.month(),now.year(), now.hour(), now.minute(), now.second());
   myFile.print(sd_datetime);
   
     myFile.print(",");
     myFile.print(f_humidity,2);
     myFile.print(",");
     myFile.print(f_temperature,2);
     myFile.print(",");
     myFile.print(f_pressure);
     myFile.print(",");  
     myFile.print(pwm); 
     myFile.print(",");  
     myFile.print(sd_tt); 
     myFile.print(",");  
     myFile.print(sd_rh);
     myFile.print(",");  
     myFile.print(sd_co2);
     myFile.print(",");  
     myFile.print(sd_tvoc);
     myFile.print(",");
     myFile.print(pm1,1);// pm25,2
     myFile.print(","); 
     myFile.print (pm25,1);
     myFile.print(","); 
     myFile.println(pm10,1);
     myFile.close();
     Serial.println("sd card write success !!");
    } 
} 

// buraya --> sd logging endssss
 
/*
  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  while (!card.init(SPI_HALF_SPEED, chipSelect)) {

  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  while (!card.init(SPI_HALF_SPEED, 10, 11, 12, 13)) {

 // see if the card is present and can be initialized:
  if (!SD.begin(10, 11, 12, 13)) {

 // if(!SD.begin(chipSelect)) {  // original mega
    Serial.println("initialization failed!");

  
*/

