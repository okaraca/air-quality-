
void loop() {
  ds3231_tft_loop ();
  rx_loop();
 // zh03_loop();

/* Updates frequently */
  unsigned long currentTime = millis();
   if ((say >= 15) && ( currentTime - previousTime_1 >= eventTime_1_oled)) //sd write every 15 sec
          {
  say=0; 
  co2_loop();
  bme280_loop();
  zh03_loop();
  rx_loop();
  sd_logging();
  
}
else  if( currentTime - previousTime_1 >= eventTime_1_oled) // update OLED every 1.5 sec
        {
        /* Update the timing for the next event*/
  
  previousTime_1 = currentTime;
  
 bme280_loop();
 // zh03_loop();
 say =say+1;
  }}
  


