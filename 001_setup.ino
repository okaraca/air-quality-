
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  tft.init();
  tft.setRotation(1);
  tft.invertDisplay(1);
  tft.fillScreen(TFT_BLACK);
  co2.setup();
  zh03_setup();
  sd_setup();
  ds3231_setup ();
  bme280_setup();
  rx_setup();
}


