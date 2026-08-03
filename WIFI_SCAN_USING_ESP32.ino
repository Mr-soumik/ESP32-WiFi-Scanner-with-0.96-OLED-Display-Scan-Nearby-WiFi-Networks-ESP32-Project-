#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ===========================
// Animation Function Prototypes
// ===========================

void heartAnimation();
void ecgAnimation();
void carAnimation();
void catAnimation();
void rocketAnimation();
void earthAnimation();
void rainAnimation();
void starfieldAnimation();
void eyesAnimation();
void robotAnimation();
void wifiAnimation();
void loadingAnimation();

// ===========================
// Global Variables
// ===========================

int starX[40];
int starY[40];
int rainX[30];
int rainY[30];

void setup()
{
  Wire.begin(21,22);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    while(true);
  }

  randomSeed(analogRead(0));

  for(int i=0;i<40;i++)
  {
    starX[i]=random(128);
    starY[i]=random(64);
  }

  for(int i=0;i<30;i++)
  {
    rainX[i]=random(128);
    rainY[i]=random(64);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(18,20);
  display.println("WELCOME");
  display.display();

  delay(2000);
}

void loop()
{
  heartAnimation();
  ecgAnimation();
  carAnimation();
  catAnimation();
  rocketAnimation();
  earthAnimation();
  rainAnimation();
  starfieldAnimation();
  eyesAnimation();
  robotAnimation();
  wifiAnimation();
  loadingAnimation();
}// ===============================
// HEART BEAT ANIMATION
// ===============================

void drawHeart(int x, int y, int s)
{
  display.fillCircle(x-s*3,y-s*2,s*3,SSD1306_WHITE);
  display.fillCircle(x+s*3,y-s*2,s*3,SSD1306_WHITE);

  display.fillTriangle(
      x-s*6,
      y-s,

      x+s*6,
      y-s,

      x,
      y+s*8,

      SSD1306_WHITE);
}

void heartAnimation()
{
  for(int k=0;k<3;k++)
  {
    // Beat 1
    for(int s=2;s<=5;s++)
    {
      display.clearDisplay();
      drawHeart(64,28,s);
      display.display();
      delay(40);
    }

    for(int s=5;s>=2;s--)
    {
      display.clearDisplay();
      drawHeart(64,28,s);
      display.display();
      delay(40);
    }

    delay(120);

    // Beat 2
    for(int s=2;s<=5;s++)
    {
      display.clearDisplay();
      drawHeart(64,28,s);
      display.display();
      delay(35);
    }

    for(int s=5;s>=2;s--)
    {
      display.clearDisplay();
      drawHeart(64,28,s);
      display.display();
      delay(35);
    }

    delay(500);
  }
}// ======================================
// ECG HEART MONITOR ANIMATION
// ======================================

void ecgAnimation()
{
  for(int t=0; t<3; t++)
  {
    for(int x=0; x<128; x++)
    {
      display.clearDisplay();

      // ECG baseline
      display.drawLine(0, 32, 127, 32, SSD1306_WHITE);

      int y = 32;

      // ECG waveform
      if(x>15 && x<20) y=28;
      if(x>20 && x<24) y=40;
      if(x>24 && x<28) y=8;
      if(x>28 && x<32) y=55;
      if(x>32 && x<36) y=26;
      if(x>36 && x<42) y=32;

      display.drawLine(x-1,32,x,y,SSD1306_WHITE);

      // Heart icon
      display.fillCircle(110,15,4,SSD1306_WHITE);
      display.fillCircle(118,15,4,SSD1306_WHITE);

      display.fillTriangle(
        106,17,
        122,17,
        114,29,
        SSD1306_WHITE
      );

      display.display();
      delay(12);
    }

    delay(300);
  }
}// ======================================
// MOVING CAR ANIMATION
// ======================================

void drawCar(int x)
{
  // Car Body
  display.fillRect(x+10, 38, 40, 12, SSD1306_WHITE);

  // Car Roof
  display.fillTriangle(
    x+18, 38,
    x+30, 26,
    x+42, 38,
    SSD1306_WHITE
  );

  // Wheels
  display.fillCircle(x+18, 52, 4, SSD1306_WHITE);
  display.fillCircle(x+42, 52, 4, SSD1306_WHITE);

  // Wheel Centers
  display.drawCircle(x+18, 52, 2, SSD1306_BLACK);
  display.drawCircle(x+42, 52, 2, SSD1306_BLACK);

  // Window
  display.drawLine(x+24, 34, x+36, 34, SSD1306_BLACK);
}

void carAnimation()
{
  for(int x=-60; x<130; x+=2)
  {
    display.clearDisplay();

    // Road
    display.drawLine(0, 58, 127, 58, SSD1306_WHITE);

    // Road Markings
    for(int i=0;i<128;i+=16)
    {
      display.drawLine(i,60,i+8,60,SSD1306_WHITE);
    }

    // Car
    drawCar(x);

    display.display();
    delay(25);
  }

  delay(500);
}// ======================================
// WALKING CAT ANIMATION
// ======================================

void drawCat(int x, bool step)
{
  // Body
  display.fillRoundRect(x+10, 28, 24, 14, 4, SSD1306_WHITE);

  // Head
  display.fillCircle(x+38, 24, 7, SSD1306_WHITE);

  // Ears
  display.fillTriangle(x+33,19,x+36,12,x+39,19,SSD1306_WHITE);
  display.fillTriangle(x+38,19,x+41,12,x+44,19,SSD1306_WHITE);

  // Eyes
  display.drawPixel(x+36,23,SSD1306_BLACK);
  display.drawPixel(x+40,23,SSD1306_BLACK);

  // Tail
  display.drawLine(x+10,30,x+2,22,SSD1306_WHITE);
  display.drawLine(x+2,22,x+0,18,SSD1306_WHITE);

  if(step)
  {
    display.drawLine(x+14,42,x+12,50,SSD1306_WHITE);
    display.drawLine(x+20,42,x+22,50,SSD1306_WHITE);
    display.drawLine(x+28,42,x+26,50,SSD1306_WHITE);
    display.drawLine(x+34,42,x+36,50,SSD1306_WHITE);
  }
  else
  {
    display.drawLine(x+14,42,x+16,50,SSD1306_WHITE);
    display.drawLine(x+20,42,x+18,50,SSD1306_WHITE);
    display.drawLine(x+28,42,x+30,50,SSD1306_WHITE);
    display.drawLine(x+34,42,x+32,50,SSD1306_WHITE);
  }
}

void catAnimation()
{
  bool step=false;

  for(int x=-45;x<128;x+=2)
  {
    display.clearDisplay();

    display.drawLine(0,54,127,54,SSD1306_WHITE);

    drawCat(x,step);

    display.display();

    step=!step;

    delay(40);
  }

  delay(500);
}// ======================================
// ROCKET LAUNCH ANIMATION
// ======================================

void drawRocket(int x, int y)
{
  // Rocket Body
  display.fillRoundRect(x-4, y, 8, 20, 3, SSD1306_WHITE);

  // Nose
  display.fillTriangle(
    x-4, y,
    x+4, y,
    x, y-8,
    SSD1306_WHITE
  );

  // Left Fin
  display.fillTriangle(
    x-4, y+15,
    x-9, y+20,
    x-4, y+20,
    SSD1306_WHITE
  );

  // Right Fin
  display.fillTriangle(
    x+4, y+15,
    x+9, y+20,
    x+4, y+20,
    SSD1306_WHITE
  );

  // Window
  display.drawCircle(x, y+7, 2, SSD1306_BLACK);
}

void rocketAnimation()
{
  for(int y=64; y>-30; y-=2)
  {
    display.clearDisplay();

    // Stars
    for(int i=0;i<20;i++)
    {
      display.drawPixel(random(128), random(64), SSD1306_WHITE);
    }

    drawRocket(64, y);

    // Exhaust Flame
    if(y<60)
    {
      display.drawLine(64, y+20, 61, y+28, SSD1306_WHITE);
      display.drawLine(64, y+20, 67, y+28, SSD1306_WHITE);
      display.drawLine(64, y+20, 64, y+30, SSD1306_WHITE);
    }

    // Smoke
    if(y>15)
    {
      display.drawCircle(56,60,3,SSD1306_WHITE);
      display.drawCircle(64,58,5,SSD1306_WHITE);
      display.drawCircle(72,60,3,SSD1306_WHITE);
    }

    display.display();
    delay(35);
  }

  delay(800);
}// ======================================
// ROTATING EARTH ANIMATION
// ======================================

void earthAnimation()
{
  for(int frame=0; frame<72; frame++)
  {
    display.clearDisplay();

    // Stars
    for(int i=0; i<20; i++)
    {
      display.drawPixel((i*17+frame*3)%128,
                        (i*11)%64,
                        SSD1306_WHITE);
    }

    // Earth Outline
    display.drawCircle(64,32,20,SSD1306_WHITE);

    // Rotating Longitude Lines
    int shift = frame % 20;

    display.drawLine(64-shift,13,64-shift,51,SSD1306_WHITE);
    display.drawLine(64+shift,13,64+shift,51,SSD1306_WHITE);

    // Latitude Lines
    display.drawCircle(64,32,15,SSD1306_WHITE);
    display.drawCircle(64,32,8,SSD1306_WHITE);

    // Simple Continents
    display.fillCircle(58+shift/4,28,3,SSD1306_WHITE);
    display.fillCircle(69-shift/5,38,4,SSD1306_WHITE);
    display.fillCircle(60-shift/6,40,2,SSD1306_WHITE);

    display.setTextSize(1);
    display.setCursor(45,57);
    display.print("EARTH");

    display.display();

    delay(60);
  }

  delay(800);
}// ======================================
// PART 8
// RAIN + STARFIELD ANIMATION
// ======================================

// ---------- Rain Animation ----------
void rainAnimation()
{
  for(int frame=0; frame<180; frame++)
  {
    display.clearDisplay();

    // Clouds
    display.fillCircle(20,10,8,SSD1306_WHITE);
    display.fillCircle(32,10,10,SSD1306_WHITE);
    display.fillCircle(46,10,8,SSD1306_WHITE);

    display.fillCircle(82,12,8,SSD1306_WHITE);
    display.fillCircle(96,10,10,SSD1306_WHITE);
    display.fillCircle(110,12,8,SSD1306_WHITE);

    // Rain Drops
    for(int i=0;i<30;i++)
    {
      display.drawLine(
        rainX[i],
        rainY[i],
        rainX[i],
        rainY[i]+4,
        SSD1306_WHITE
      );

      rainY[i]+=4;

      if(rainY[i]>63)
      {
        rainY[i]=15;
        rainX[i]=random(128);
      }
    }

    display.display();
    delay(30);
  }

  delay(500);
}


// ---------- 3D Starfield Animation ----------
void starfieldAnimation()
{
  int speed = 1;

  for(int frame=0; frame<220; frame++)
  {
    display.clearDisplay();

    for(int i=0;i<40;i++)
    {
      display.drawPixel(
        starX[i],
        starY[i],
        SSD1306_WHITE
      );

      starX[i]-=speed;

      if(starX[i]<0)
      {
        starX[i]=127;
        starY[i]=random(64);
      }
    }

    display.display();

    if(frame%40==0 && speed<5)
      speed++;

    delay(20);
  }

  delay(500);
}// ======================================
// PART 9
// EYES + ROBOT + WIFI + LOADING
// ======================================

// ---------- Blinking Eyes ----------
void eyesAnimation()
{
  for(int i=0;i<3;i++)
  {
    // Eyes Open
    display.clearDisplay();

    display.drawCircle(40,32,12,SSD1306_WHITE);
    display.fillCircle(40,32,4,SSD1306_WHITE);

    display.drawCircle(88,32,12,SSD1306_WHITE);
    display.fillCircle(88,32,4,SSD1306_WHITE);

    display.display();
    delay(800);

    // Blink
    display.clearDisplay();

    display.drawLine(28,32,52,32,SSD1306_WHITE);
    display.drawLine(76,32,100,32,SSD1306_WHITE);

    display.display();
    delay(180);
  }

  delay(500);
}


// ---------- Robot Face ----------
void robotAnimation()
{
  for(int i=0;i<4;i++)
  {
    display.clearDisplay();

    display.drawRoundRect(20,10,88,44,6,SSD1306_WHITE);

    display.fillRect(36,22,10,10,SSD1306_WHITE);
    display.fillRect(82,22,10,10,SSD1306_WHITE);

    if(i%2==0)
      display.drawLine(42,42,86,42,SSD1306_WHITE);
    else
      display.drawCircle(64,42,6,SSD1306_WHITE);

    display.drawLine(64,10,64,3,SSD1306_WHITE);
    display.fillCircle(64,2,2,SSD1306_WHITE);

    display.display();
    delay(700);
  }

  delay(500);
}


// ---------- WiFi Animation ----------
void wifiAnimation()
{
  for(int j=0;j<5;j++)
  {
    display.clearDisplay();

    display.fillCircle(64,52,2,SSD1306_WHITE);

    if(j>=1)
      display.drawCircle(64,52,8,SSD1306_WHITE);

    if(j>=2)
      display.drawCircle(64,52,16,SSD1306_WHITE);

    if(j>=3)
      display.drawCircle(64,52,24,SSD1306_WHITE);

    if(j>=4)
      display.drawCircle(64,52,32,SSD1306_WHITE);

    display.setTextSize(1);
    display.setCursor(45,5);
    display.print("WiFi");

    display.display();
    delay(450);
  }

  delay(600);
}


// ---------- Loading Animation ----------
void loadingAnimation()
{
  display.clearDisplay();

  display.setCursor(32,20);
  display.setTextSize(1);
  display.print("LOADING...");

  display.drawRect(18,40,92,10,SSD1306_WHITE);

  for(int i=0;i<=88;i++)
  {
    display.fillRect(20,42,i,6,SSD1306_WHITE);
    display.display();
    delay(25);
  }

delay(800);
}