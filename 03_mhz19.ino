void co2_loop (){
    pwm = ( co2.read_pwm_value()) / 2.50; //divide 2.5 for 2000 ppm calibration
 // pwm = ( co2.read_pwm_value()) ; // 5000 ppm calibration
    rgb();
    tft.setCursor (10, 210);// Adding a background colour erases previous text automatically
    tft.setTextFont(6);        // Select font 1 which is the Adafruit GLCD font
    int  padding3 = tft.textWidth("9999", 6); // get the width of the text in pixels and font for 4
    tft.setTextColor(color, TFT_BLACK); // This time we will use green text on a black background
    tft.setTextPadding(padding3); 
   
    tft.drawNumber(pwm, 10, 210,6);
    
 //   char tft_pwm [4];
 //   sprintf(tft_pwm, "%4d", pwm);
 //   tft.print(tft_pwm);
     
    tft.setTextPadding(0); // Setting to zero switches off padding
    
if(pwm > max_pwm)
    {
     max_pwm = pwm;
     char maks_pwm [5];
      sprintf(maks_pwm, "%4d", max_pwm);
     tft.drawNumber(max_pwm , 150, 235, 4);//  tft.drawFloat(test, decimal_places, x, y, font);
     tft.setTextColor(TFT_GREEN, TFT_BLACK);
     tft.drawString("Co2", 150, 215, 4);//  tft.drawFloat(test, decimal_places, x, y, font);
     tft.drawString("ppm", 150, 280, 4);//  tft.drawFloat(test, decimal_places, x, y, font);

    }

   
     }


