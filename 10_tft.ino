 /*
     tft.setTextColor(TFT_RED, TFT_BLACK); // This time we will use green text on a black background
     tft.drawCentreString("34.56", 120, 54, 6);       // Draw text centre at position 120, 54 using font 6
  // Set the font colour to be yellow with no background, set to font 7
  tft.setTextColor(TFT_YELLOW); 
  tft.setTextFont(2);
  tft.println(1234.56);
  tft.drawNumber(runTime, 130, 225,2);
  tft.drawFloat
  // Test some print formatting functions
  float fnumber = DHT.temperature ;
//  float fnumber = 123.45;
   // Set the font colour to be blue with no background, set to font 4
  tft.setTextColor(TFT_BLUE);    
  tft.setTextFont(4);
  tft.print("Float = "); tft.println(fnumber);
    tft.drawChar(':', xcolon, ypos - 8, 8);     // Hour:minute colon
    tft.drawNumber(i, x, y, font);
    tft.drawString("ms per character", xpos, 180, 4);
    tft.drawFloat(test, decimal_places, x, y, font);
    padding = tft.textWidth("Quick brown", font); // get the width of the widest text in pixels   
    tft.setTextPadding(padding); // Setting to zero switches off padding
    tft.setTextDatum(TC_DATUM); // Top Centre is datum
    
  tft.fillScreen(random(0xFFFF)); 
   tft.setCursor(0, 0, 2);
   // Set "cursor" at top left corner of display (0,0) and select font 2

   
// char deneme = f_humidity ;
// tft.drawCentreString("deneme", 240, 160, 4);       // Draw text centre at position 240, 160 using font 6

//    tft.setCursor (50, 5);// Adding a background colour erases previous text automatically
//    tft.setTextFont(7);        // Select font 1 which is the Adafruit GLCD font
//   tft.print(tft_time);
/*   
 * 
char tft_datetime [20];
sprintf(tft_datetime, "%02d:%02d:%4d,%02d:%02d:%02d", now.day(),now.month(),now.year(), now.hour(), now.minute(), now.second());
    tft.setTextColor(TFT_GREEN, TFT_BLACK); // This time we will use green text on a black background
    tft.setCursor (50, 5);// Adding a background colour erases previous text automatically
    tft.setTextFont(7);        // Select font 1 which is the Adafruit GLCD font
    tft.print(tft_datetime);

    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
*/








