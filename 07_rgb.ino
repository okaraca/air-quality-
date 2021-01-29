void rgb (){
// change color of co2 
  if(pwm <800){
 color = TFT_GREEN;
  }
  else if (pwm>800 && pwm<1200){
 color = TFT_CYAN;
  }
  else if (pwm >1200){
color = TFT_RED;

  }  }

void rgb_2 (){
// change color of co2 
  if(sd_co2 <800){
 color_a = TFT_GREEN;
  }
  else if (sd_co2>800 && pwm<1200){
 color_a = TFT_CYAN;
  }
  else if (pwm >1200){
color_a = TFT_RED;

  }  }
