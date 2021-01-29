#include "VirtualWire.h"
#include <Wire.h>

const int receive_pin = 5; //old 5 -->8 --> 6:pwm and 4:sd/cs dedicated pins
const int led_pin = 2;

void rx_setup()
{
    Serial.begin(9600);	// Debugging only
    Serial.println("setup");

// Initialise the IO and ISR
    vw_set_rx_pin(receive_pin);
   
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec

    vw_rx_start();       // Start the receiver PLL running
}

void rx_loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
	int i;
        buf[buflen] = '\0';
        digitalWrite(led_pin, HIGH);
        
	// Message with a good checksum received, print it.
	// Serial.print("Got: ");
	Serial.print(buflen);
        Serial.print(" Veri: ");
	for (i = 0; i < buflen; i++)
	{
	    Serial.write(buf[i]);
             
	}
	Serial.println();
   digitalWrite(led_pin, LOW);

    char  tt[6]={buf[0],buf[1], buf[2],buf[3],buf[4],'\0'};
    char  rh[6]={buf[6],buf[7], buf[8],buf[9],buf[10],'\0'};
    char  _co2[5]={buf[12], buf[13],buf[14],buf[15],'\0'};
    char tvoc[5]={buf[18], buf[19],buf[20],buf[21],'\0'};

    sd_tt =   atof(tt); //convert received ASCII to original float
    sd_rh =   atof(rh); //convert received ASCII to original float

    sd_co2 =  atol(_co2); // a string to a long integer
    sd_tvoc = atol (tvoc);
/*
  Serial.print(tt);
  Serial.print(" derece. ");

  Serial.print(rh);
  Serial.println(" rh..");
  Serial.println();
  
  */
  delay(100);
  digitalWrite(led_pin, LOW); 

    tft.setTextColor(TFT_CYAN, TFT_BLACK); // This time we will use green text on a black background

    tft.drawString(tt, 250, 80, 7);
    tft.drawString(rh, 250, 140, 7);

    rgb_2();
    int  padding_co2 = tft.textWidth("99999", 6); // get the width of the text in pixels and font for 4
    tft.setTextColor(color_a, TFT_BLACK); // This time we will use green text on a black background
    tft.setTextPadding(padding_co2);         tft.drawRightString(tft_co2, 410, 220, 6);
        tft.drawNumber(sd_co2, 10, 255,6);

//   sprintf(tft_co2, "%4s", _co2);
//   tft.drawString(tft_co2, 315, 220, 6);
     
if(sd_co2 > max_sd_co2)
    {
     max_sd_co2 = sd_co2;
     char maks_pwm [5];
     sprintf(maks_pwm, "%4d", max_pwm);
     tft.drawNumber(max_sd_co2 , 150, 265, 4);//  tft.drawFloat(test, decimal_places, x, y, font);
    }
    
    
    
    
    int  padding1 = tft.textWidth("9999", 6); // get the width of the text in pixels and font for 4
    tft.setTextColor(TFT_CYAN, TFT_BLACK); // This time we will use green text on a black background
    tft.setTextPadding(padding1);    
         tft.drawNumber(sd_tvoc, 325, 255,6);
     
//   sprintf(tft_tvoc, "%3s", tvoc);
//    tft.drawRightString (tft_tvoc, 410, 270, 6);
//  tft.drawString (tft_tvoc, 350, 270, 6);

   tft.setTextPadding(0); // Setting to zero switches off padding

  }
    
    
}
