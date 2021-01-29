/*
TFT_HX8357  KEYWORD1

init  KEYWORD2
drawPixel KEYWORD2

drawChar  KEYWORD2
setWindow KEYWORD2

pushColor KEYWORD2
pushColor KEYWORD2

pushColors  KEYWORD2
pushColors  KEYWORD2

fillScreen  KEYWORD2

drawLine  KEYWORD2
drawFastVLine KEYWORD2
drawFastHLine KEYWORD2

drawRect  KEYWORD2
fillRect  KEYWORD2
drawRoundRect KEYWORD2
fillRoundRect KEYWORD2

setRotation KEYWORD2
invertDisplay KEYWORD2

drawCircle  KEYWORD2
drawCircleHelper  KEYWORD2
fillCircle  KEYWORD2
fillCircleHelper  KEYWORD2

drawElipse  KEYWORD2
fillElipse  KEYWORD2

drawTriangle  KEYWORD2
fillTriangle  KEYWORD2

drawBitmap  KEYWORD2

setCursor KEYWORD2
setCursor KEYWORD2
setTextColor  KEYWORD2
setTextSize KEYWORD2
setTextFont KEYWORD2
setTextWrap KEYWORD2
setTextDatum  KEYWORD2
setTextPadding  KEYWORD2

setFreeFont KEYWORD2

writecommand  KEYWORD2
writedata KEYWORD2
fgColor KEYWORD2
bgColor KEYWORD2
fgWrite KEYWORD2
bgWrite KEYWORD2
addrCmd KEYWORD2
commandList KEYWORD2

getRotation KEYWORD2

fontsLoaded KEYWORD2
color565  KEYWORD2

drawChar  KEYWORD2
drawNumber  KEYWORD2
drawFloat KEYWORD2

drawString  KEYWORD2
drawCentreString  KEYWORD2
drawRightString KEYWORD2

height  KEYWORD2
width KEYWORD2
textWidth KEYWORD2
fontHeight  KEYWORD2

setWindow KEYWORD2
hi_byte KEYWORD2
lo_byte KEYWORD2
*/

/*
  //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Now set padding width to be 3 digits wide in font 8
  // Padding height is set automatically, all numeric digits are the same width
  // in fonts 1 to 8
  // The value on screen will now be correct as all digits are over-printed

  padding = tft.textWidth("999", font); // get the width of the text in pixels
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextPadding(padding);

  for (int i = 499; i >= 0; i--) {
    tft.drawNumber(i, x, y + 140, font); // Use 1 decimal place


      // Set text padding to 120 pixels wide area to over-write old values on screen
   tft.setTextColor(TFT_YELLOW, TFT_GREEN);
  tft.setTextPadding(120);



    tft.setTextPadding(55*3); // Allow for 3 digits each 55 pixels wide
 * /
 */
