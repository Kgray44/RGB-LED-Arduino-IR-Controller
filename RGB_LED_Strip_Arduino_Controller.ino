#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    60
#define bright = 100

CRGB leds[NUM_LEDS];

char incoming_command = '0';
int l = 1;
boolean setting = 0;

void check_for_input() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incoming_command = Serial.read();
      
    // say what you got:
    //Serial.print("I received: ");
    //Serial.println(incoming_command);
  }
}

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(bright);
  randomSeed(analogRead(0));
}

void loop() {
  int L = 60-l;
  check_for_input();
  if (incoming_command == 'G'){ //Activation and deactivation button for the second control
    Serial.println("Switching: ");
    setting = !setting;
    Serial.println(setting);
    delay(1000);
  }
  else if (incoming_command == 'F'){ //Choosing second person's amount of LEDs
    for (int i = 60; i >= 0; i--) {
      leds[i] = CRGB (0,0,0);
      FastLED.show();
      delay(40);
    }
    leds[60] = CRGB (255,0,0);
    FastLED.show();
    pl:
    check_for_input();
    Serial.println(l);
    if (incoming_command == 'B'){
      if (l < 60){
        l++;
      }
    }
    if (incoming_command == 'D'){
      if (l > 0){
        l--;
      }
    }
    leds[l] = CRGB (255,0,0);
    FastLED.show();
    if (incoming_command != 'A'){
      goto pl;
    }
    for (int i = 59; i >= 0; i--) {
      leds[i] = CRGB (0,0,0);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == '0'){
    Serial.println("WHITE");
    for (int i = 0; i <= L; i++) {
      leds[i] = CRGB (255,255,255);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == '1'){
    Serial.println("RED");
    for (int i = 0; i <= L; i++) {
      leds[i] = CRGB (255,0,0);
      FastLED.show();
      delay(40);
    }
  }

  else if (incoming_command == '2'){
    Serial.println("ORANGE");
    for (int i = 0; i <= L; i++) {
      leds[i] = CRGB (255,128,0);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == '3'){
    Serial.println("YELLOW");
    for (int i = 0; i <= L; i++) {
      leds[i] = CRGB (255,255,0);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == '4'){
    Serial.println("GREEN");
    for (int i = 0; i <= L; i++) {
      leds[i] = CRGB (0,255,0);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == '5'){
    Serial.println("TEAL");
    for (int i = 0; i <= L; i++) {
      leds[i] = CRGB (0,255,255);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == '6'){
    Serial.println("BLUE");
    for (int i = 0; i <= L; i++) {
      leds[i] = CRGB (0,0,255);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == '7'){
    Serial.println("PINK");
    for (int i = 0; i <= L; i++) {
      leds[i] = CRGB (255,51,255);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == '8'){
    Serial.println("PURPLE");
    for (int i = 0; i <= L; i++) {
      leds[i] = CRGB (127,0,255);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == '9'){
    for (int i = 0; i <= L; i++) {
      leds[i] = CRGB (128,128,128);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'A' && setting == 0){
    for (int i = 60; i >= 0; i--) {
      leds[i] = CRGB (0,0,0);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'A' && setting == 1){
    for (int i = L; i >= 0; i--) {
      leds[i] = CRGB (0,0,0);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'B'){
    if (bright < 100){
      bright++;
    }
    FastLED.setBrightness(bright);
  }
  else if (incoming_command == 'D'){
    if (bright > 0){
      bright--;
    }
    FastLED.setBrightness(bright);
  }
  else if (incoming_command == 'C'){
    for (int i = 0; i <= 60; i++) {
      leds[i] = CRGB (0,0,0);
      FastLED.show();
      delay(20);
    }
    st:
    long ran = random(60);
    long de = random(2000);
    long d = random(50);
    leds[ran] = CRGB(255,255,255);
    FastLED.show();
    delay(d);
    leds[ran] = CRGB(0,0,0);
    FastLED.show();
    delay(de);
    check_for_input();
    if (incoming_command != 'A'){
      goto st;
    }
  }
  else if (incoming_command == 'E'){
    sp:
    rainbowCycle(10);
    if (incoming_command != 'A'){
      goto sp;
    }
  }
  
  //#2 Control
  else if (incoming_command == 'Q' && setting == 1){
    Serial.println("WHITE2");
    for (int i = L; i <= 60; i++) {
      leds[i] = CRGB (255,255,255);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'R' && setting == 1){
    Serial.println("OFF2");
    for (int i = 60; i >= L; i--) {
      leds[i] = CRGB (0,0,0);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'H' && setting == 1){
    for (int i = L; i <= 60; i++) {
      leds[i] = CRGB (255,0,0);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'I' && setting == 1){
    for (int i = L; i <= 60; i++) {
      leds[i] = CRGB (255,128,0);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'J' && setting == 1){
    for (int i = L; i <= 60; i++) {
      leds[i] = CRGB (255,255,0);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'K' && setting == 1){
    for (int i = L; i <= 60; i++) {
      leds[i] = CRGB (0,255,0);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'L' && setting == 1){
    for (int i = L; i <= 60; i++) {
      leds[i] = CRGB (0,255,255);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'M' && setting == 1){
    for (int i = L; i <= 60; i++) {
      leds[i] = CRGB (0,0,255);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'N' && setting == 1){
    for (int i = L; i <= 60; i++) {
      leds[i] = CRGB (255,51,255);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'O' && setting == 1){
    for (int i = L; i <= 60; i++) {
      leds[i] = CRGB (127,0,255);
      FastLED.show();
      delay(40);
    }
  }
  else if (incoming_command == 'P' && setting == 1){
    for (int i = L; i <= 60; i++) {
      leds[i] = CRGB (128,128,128);
      FastLED.show();
      delay(40);
    }
  }
}

void rainbowCycle(int SpeedDelay) {
  byte *c;
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< NUM_LEDS; i++) {
      c=Wheel(((i * 256 / NUM_LEDS) + j) & 255);
      setPixel(i, *c, *(c+1), *(c+2));
    }
    showStrip();
    delay(SpeedDelay);
    check_for_input();
    if (incoming_command == 'A'){
      goto ne;
    }
  }
  ne:
  delay(2);
}

byte * Wheel(byte WheelPos) {
  static byte c[3];
  
  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }

  return c;
}

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}
