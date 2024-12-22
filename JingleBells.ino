#include <Adafruit_CircuitPlayground.h>

bool leftButtonPressed;
bool rightButtonPressed;
int jingle = 0;


void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(200);
}

void loop() {
  //AllOneColor(255, 0, 0);
  //delay(2000);
  //IndividualColors();
  rightButtonPressed = CircuitPlayground.rightButton();
  if (rightButtonPressed) {
    ShortJingleBells();
  }
  //delay(2000);
    //CandleLight(20);
  //delay(100);

  

  //Blink Blue and White
  BlinkBlueWhite();
  AllOneColor(255,255,255);
  delay(30000);
  AllOneColor(0,0,255);
  delay(30000);

  //Red and Green Pulse
  RunBlueWhitePulse();

  RunBlueWhiteCircle();

  //Blink Rainbow
  BlinkRainbow(1000);


  //Blink Red and Green
  AllOneColor(255,0,0);
  delay(30000);
  AllOneColor(0,255,0);
  delay(30000);

  //Red and Green Pulse
  RunRedGreenPulse();

  RunRedGreenCircle();

  if (jingle == 20){
    ShortJingleBells();
    jingle = 0;
  }
  jingle++;

}

void RainbowWheel() {
  for(int i = 0; i < 100; i++){
    for(int colors = 0; colors < 10; colors++){
      delay(500);
        CircuitPlayground.setPixelColor(colors, 255, 0, 0); //RED
        if (colors + 1 == 10) {
          CircuitPlayground.setPixelColor(0,0,255,0); //GREEN
        }
        else {
          CircuitPlayground.setPixelColor(colors + 1,0,255,0);//GREEN
        }
    }
  }
}

void RainbowWheel2() {
  for(int i = 0; i < 100; i++){
    for(int colors = 0; colors < 10; colors++){
      delay(1000);
        CircuitPlayground.setPixelColor(colors, 255, 0, 0); //RED
        if (colors + 1 == 10) {
          CircuitPlayground.setPixelColor(0,0,255,0); //GREEN
        }
        else {
          CircuitPlayground.setPixelColor(colors + 1,0,255,0);//GREEN
        }
        if (colors - 1 == -1) {
          CircuitPlayground.setPixelColor(9,0,255,0); //GREEN
        }
        else {
          CircuitPlayground.setPixelColor(colors - 1,0,255,0);//GREEN        
        }
    }
  }
}

void RunRedGreenPulse() {
  int p = 0;
  do{   
    PulseUp(255,0,0,100);
    PulseDown(255,0,0,100);
    PulseUp(0,255,0,100);
    PulseDown(0,255,0,100);
    p++;
  } while (p < 10);
}

void RunRedGreenCircle() {
  int z = 0;
    do{
    ColorCircle(255,0,0,100);
    ReverseColorCircle(0,255,0,100);
    ColorCircle(0,255,0,100);
    ReverseColorCircle(255,0,0,100);
    z++;    
  } while (z < 10);  
}

void RunBlueWhitePulse() {
  int p = 0;
  do{   
    PulseUp(0,0,255,100);
    PulseDown(0,0,255,100);
    PulseUp(255,255,255,100);
    PulseDown(255,255,255,100);
    p++;
  } while (p < 10);
}

void RunBlueWhiteCircle() {
  int z = 0;
    do{
    ColorCircle(0,0,255,100);
    ReverseColorCircle(255,255,255,100);
    ColorCircle(255,255,255,100);
    ReverseColorCircle(0,0,255,100);
    z++;    
  } while (z < 10);  
}

void BlinkBlueWhite() {
  CircuitPlayground.setBrightness(255);
  BlinkAll(0,0,255,1500, 25000);
  BlinkAll(255,255,255,1500, 25000);  
}

void BlinkRainbow(int delaybetweenblinks) {
  CircuitPlayground.setBrightness(200);
  int z = 0;
  do{
    AllOneColor(255, 255, 255); //WHITE
    delay(delaybetweenblinks);
    AllOneColor(255, 0, 0); //RED
    delay(delaybetweenblinks);
    AllOneColor(0, 0, 255); //BLUE
    delay(delaybetweenblinks);
    AllOneColor(0, 255, 0); //GREEN
    delay(delaybetweenblinks);
    AllOneColor(255, 128, 0); //YELLOW
    delay(delaybetweenblinks);
    AllOneColor(64, 0, 255); //PURPLE
    delay(delaybetweenblinks);
    AllOneColor(255, 64, 0); //ORANGE
    delay(delaybetweenblinks);
    AllOneColor(255, 0, 64); //PINK 
    delay(delaybetweenblinks); 
    z++;    
  } while (z < 10); 
}

void IndividualColors() {
  CircuitPlayground.setPixelColor(0, 255, 255, 255); //WHITE
  CircuitPlayground.setPixelColor(1, 255, 0, 0); //RED
  CircuitPlayground.setPixelColor(2, 0, 0, 255); //BLUE
  CircuitPlayground.setPixelColor(3, 0, 255, 0); //GREEN
  CircuitPlayground.setPixelColor(4, 255, 128, 0); //YELLOW
  CircuitPlayground.setPixelColor(5, 64, 0, 255); //PURPLE
  CircuitPlayground.setPixelColor(6, 255, 64, 0); //ORANGE
  CircuitPlayground.setPixelColor(7, 255, 0, 64); //PINK  
}

void AllOneColor(int R, int G, int B) {
  CircuitPlayground.setPixelColor(0, R, G, B); 
  CircuitPlayground.setPixelColor(1, R, G, B);
  CircuitPlayground.setPixelColor(2, R, G, B);
  CircuitPlayground.setPixelColor(3, R, G, B);
  CircuitPlayground.setPixelColor(4, R, G, B);
  CircuitPlayground.setPixelColor(5, R, G, B);
  CircuitPlayground.setPixelColor(6, R, G, B);
  CircuitPlayground.setPixelColor(7, R, G, B);
  CircuitPlayground.setPixelColor(8, R, G, B);
  CircuitPlayground.setPixelColor(9, R, G, B); 
}

void PulseUp(int R, int G, int B, int delayspeed) {
  for(int i = 0; i <= 255; i = i + 10) {
      CircuitPlayground.setBrightness(i);
      AllOneColor(R, G, B);
      delay(delayspeed); 
  }
}
void PulseDown(int R, int G, int B, int delayspeed) {
  for(int i = 255; i >= 0; i = i - 10) {
      CircuitPlayground.setBrightness(i);
      AllOneColor(R, G, B);
      delay(delayspeed); 
  }
}

void ColorCircle(int R, int G, int B, int delayspeed) {
  for(int i = 0; i <= 9; i++) {
      CircuitPlayground.setBrightness(255);
      CircuitPlayground.setPixelColor(i, R, G, B);
      delay(delayspeed); 
  }
}

void ReverseColorCircle(int R, int G, int B, int delayspeed) {
  for(int i = 9; i >= 0; i--) {
      CircuitPlayground.setBrightness(255);
      CircuitPlayground.setPixelColor(i, R, G, B);
      delay(delayspeed); 
  }
}

void BlinkAll(int R, int G, int B, int delayspeed, int howlongms) {
      CircuitPlayground.setBrightness(255);
      while(howlongms > 0) {
        AllOneColor(R,G,B);
        delay(delayspeed);
        AllOneColor(0,0,0);
        delay(delayspeed);
        howlongms = howlongms - (delayspeed * 2);
      }
  }

void CandleLight(int endhowlong) {
  CircuitPlayground.setBrightness(200); // LEDs full blast!
  uint8_t prev = 64;              // Start brightness in middle
  int howlong = 0;
  while(howlong < endhowlong){
    uint8_t lvl = random(64, 128); // End brightness at 128±64
    split(prev, lvl, 32);          // Start subdividing, ±32 at midpoint
    prev = lvl;                    // Assign end brightness to next start
    howlong++;
  }
}

void split(uint8_t y1, uint8_t y2, uint8_t offset) {
    if(offset) { // Split further into sub-segments w/midpoint at ±offset
      uint8_t mid = (y1 + y2 + 1) / 2 + random(-offset, offset);
      split(y1 , mid, offset / 2); // First segment (offset is halved)
      split(mid, y2 , offset / 2); // Second segment (ditto)
    } else { // No further subdivision - y1 determines LED brightness
      uint32_t c = (((int)(pow((float)y1 / 255.0, 2.7) * 255.0 + 0.5) // Gamma
                   * 0x1004004) >> 8) & 0x008080; // Expand to 32-bit RGB color
      for(uint8_t i=0; i<10; i++) CircuitPlayground.strip.setPixelColor(i, c);
      CircuitPlayground.strip.show();
      delay(4);
    }
}

void BlueLightBlueWhite() {
  // delay(500);
  
  // CircuitPlayground.setPixelColor(5, 0xFF0000);
  // CircuitPlayground.setPixelColor(6, 0x808000);
  // CircuitPlayground.setPixelColor(7, 0x00FF00);
  // CircuitPlayground.setPixelColor(8, 0x008080);
  // CircuitPlayground.setPixelColor(9, 0x0000FF);
 
  delay(5000);

  CircuitPlayground.setPixelColor(1, 0x0000FF);
  CircuitPlayground.setPixelColor(2, 0x0000FF);
  CircuitPlayground.setPixelColor(3, 0x0000FF);
  CircuitPlayground.setPixelColor(4, 0x0000FF);
  CircuitPlayground.setPixelColor(5, 0x0000FF);
  CircuitPlayground.setPixelColor(6, 0x0000FF);
  CircuitPlayground.setPixelColor(7, 0x0000FF);
  CircuitPlayground.setPixelColor(8, 0x0000FF);
  CircuitPlayground.setPixelColor(9, 0x0000FF);
 
  delay(5000);

  CircuitPlayground.setPixelColor(1, 0x008080);
  CircuitPlayground.setPixelColor(2, 0x008080);
  CircuitPlayground.setPixelColor(3, 0x008080);
  CircuitPlayground.setPixelColor(4, 0x008080);
  CircuitPlayground.setPixelColor(5, 0x008080);
  CircuitPlayground.setPixelColor(6, 0x008080);
  CircuitPlayground.setPixelColor(7, 0x008080);
  CircuitPlayground.setPixelColor(8, 0x008080);
  CircuitPlayground.setPixelColor(9, 0x008080);
 
  delay(5000);

  CircuitPlayground.setPixelColor(1, 0xFFFFFF);
  CircuitPlayground.setPixelColor(2, 0xFFFFFF);
  CircuitPlayground.setPixelColor(3, 0xFFFFFF);
  CircuitPlayground.setPixelColor(4, 0xFFFFFF);
  CircuitPlayground.setPixelColor(5, 0xFFFFFF);
  CircuitPlayground.setPixelColor(6, 0xFFFFFF);
  CircuitPlayground.setPixelColor(7, 0xFFFFFF);
  CircuitPlayground.setPixelColor(8, 0xFFFFFF);
  CircuitPlayground.setPixelColor(9, 0xFFFFFF);
 
  delay(5000);  
}

void ShortJingleBells() {
    int onetonedelay = 150;
    int twotonedelay = 500;
    int threetonedelay = 1300;

    CircuitPlayground.setBrightness(200);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 1000);
    delay(twotonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(329, 1000);
    delay(twotonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(392, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(261, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(294, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 2000);
    delay(threetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(349, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(349, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(349, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(349, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(349, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 250);
    delay(280);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(329, 250);
    delay(280);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(294, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(294, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(294, 1000);
    delay(twotonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(392, 1000);
    delay(twotonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 1000);
    delay(twotonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(329, 1000);
    delay(twotonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(392, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(261, 500);
    delay(onetonedelay);
    AllOneColor(0,255,0);
    CircuitPlayground.playTone(294, 500);
    delay(onetonedelay);
    AllOneColor(255,0,0);
    CircuitPlayground.playTone(329, 2000);
    delay(threetonedelay);
    AllOneColor(0,255,0);
}

void RedGreen() {
  delay(1000);
  CircuitPlayground.setPixelColor(0, 255, 0, 0);
  CircuitPlayground.setPixelColor(1, 0, 255, 0);
  CircuitPlayground.setPixelColor(2, 255, 0, 0);
  CircuitPlayground.setPixelColor(3, 0, 255, 0);
  CircuitPlayground.setPixelColor(4, 255, 0, 0);
  CircuitPlayground.setPixelColor(5, 0, 255, 0);
  CircuitPlayground.setPixelColor(6, 255, 0, 0);
  CircuitPlayground.setPixelColor(7, 0, 255, 0);
  CircuitPlayground.setPixelColor(8, 255, 0, 0);
  CircuitPlayground.setPixelColor(9, 0, 255, 0);
  delay(1000);
  CircuitPlayground.setPixelColor(1, 255, 0, 0);
  CircuitPlayground.setPixelColor(2, 0, 255, 0);
  CircuitPlayground.setPixelColor(3, 255, 0, 0);
  CircuitPlayground.setPixelColor(4, 0, 255, 0);
  CircuitPlayground.setPixelColor(5, 255, 0, 0);
  CircuitPlayground.setPixelColor(6, 0, 255, 0);
  CircuitPlayground.setPixelColor(7, 255, 0, 0);
  CircuitPlayground.setPixelColor(8, 0, 255, 0);
  CircuitPlayground.setPixelColor(9, 255, 0, 0);
  CircuitPlayground.setPixelColor(0, 0, 255, 0);
}

