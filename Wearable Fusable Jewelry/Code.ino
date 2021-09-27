// *Code derived from existing example sketch 
// "strandtest" from the Adafruit NeoPixel Library


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


#define LED_PIN   8
#define LED_COUNT 1

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

void setup() {
  
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  strip.begin();           
  strip.show();           
  strip.setBrightness(50);
}

void loop() {
  // Fill along the length of the strip in various colors...
  colorWipe(strip.Color(255,   0,   0), 50); // Red
  delay(1000);
  colorWipe(strip.Color(  0, 255,   0), 50); // Green
  delay(1000);
  colorWipe(strip.Color(  0,   0, 255), 50); // Blue
  delay(1000);
  colorWipe(strip.Color(  0, 255, 255), 50); // Cyan
  delay(1000);
  colorWipe(strip.Color(  255, 0, 255), 50); // Purple
  delay(1000);
  colorWipe(strip.Color(  255, 255, 0), 50); // Yellow
  delay(1000);
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
