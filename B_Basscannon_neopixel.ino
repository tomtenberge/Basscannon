//include neopixel library
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
// Define neopixel strips
Adafruit_NeoPixel neo_strip1 = Adafruit_NeoPixel(15, 12, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neo_strip2 = Adafruit_NeoPixel(15, 11, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neo_strip3 = Adafruit_NeoPixel(15, 10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neo_strip4 = Adafruit_NeoPixel(15, 9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neo_strip5 = Adafruit_NeoPixel(15, 8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neo_strip6 = Adafruit_NeoPixel(15, 7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neo_strip7 = Adafruit_NeoPixel(15, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neo_strip8 = Adafruit_NeoPixel(15, 5, NEO_GRB + NEO_KHZ800);
//Colors
uint32_t maroon =   neo_strip1.Color(0x80, 0x00, 0x82);//#800000
uint32_t Brown =    neo_strip1.Color(0x9A, 0x63, 0x24);//#9A6324
uint32_t Olive =    neo_strip1.Color(0x80, 0x80, 0x00);//#808000
uint32_t Teal =     neo_strip1.Color(0x46, 0x99, 0x90);//#469990
uint32_t Navy =     neo_strip1.Color(0x00, 0x00, 0x75);//#000075
uint32_t Black =    neo_strip1.Color(0x00, 0x00, 0x00);//#000000
uint32_t Red =      neo_strip1.Color(0xFF, 0x00, 0x00);//#E6194B
uint32_t Orange =   neo_strip1.Color(0xF5, 0x82, 0x31);//#F58231
uint32_t Yellow =   neo_strip1.Color(0xFF, 0xE1, 0x19);//#FFE119
uint32_t Lime =     neo_strip1.Color(0xBF, 0xEF, 0x45);//#BFEF45
uint32_t Green =    neo_strip1.Color(0x00, 0xFF, 0x00);//#3CB44B
uint32_t Cyan =     neo_strip1.Color(0x42, 0xD4, 0xF4);//#42D4F4
uint32_t Blue =     neo_strip1.Color(0x00, 0x00, 0xFF);//#4363D8
uint32_t Purple =   neo_strip1.Color(0x91, 0x1E, 0xB4);//#911EB4
uint32_t Magenta =  neo_strip1.Color(0xF0, 0x32, 0xE6);//#F032E6
uint32_t Grey =     neo_strip1.Color(0xA9, 0xA9, 0xA9);//#A9A9A9
uint32_t Pink =     neo_strip1.Color(0xFA, 0xBE, 0xBE);//#FABEBE
uint32_t Apricot =  neo_strip1.Color(0xFF, 0xD8, 0xB1);//#FFD8B1
uint32_t Beige =    neo_strip1.Color(0xFF, 0xFA, 0xC8);//#FFFAC8
uint32_t Mint =     neo_strip1.Color(0xAA, 0xFF, 0xC3);//#AAFFC3
uint32_t Lavender = neo_strip1.Color(0xE6, 0xBE, 0xFF);//#E6BEFF
uint32_t White =    neo_strip1.Color(0xFF, 0xFF, 0xFF);//#FFFFFF
uint32_t Yellow2 =   neo_strip1.Color(0xFF, 0xFF, 0x00);//#FFE119

//refresh all strips
void neo_show() {
  neo_strip1.show();
  neo_strip2.show();
  neo_strip3.show();
  neo_strip4.show();
  neo_strip5.show();
  neo_strip6.show();
  neo_strip7.show();
  neo_strip8.show();
}
void neo_setled(int strip, int led, uint32_t color1){
  switch (strip) {
    case 0:
      neo_strip1.setPixelColor(led, color1);
      neo_strip2.setPixelColor(led, color1);
      neo_strip3.setPixelColor(led, color1);
      neo_strip4.setPixelColor(led, color1);
      neo_strip5.setPixelColor(led, color1);
      neo_strip6.setPixelColor(led, color1);
      neo_strip7.setPixelColor(led, color1);
      neo_strip8.setPixelColor(led, color1);
    break;
    case 1:
      neo_strip1.setPixelColor(led, color1);
    break;
    case 2:
      neo_strip2.setPixelColor(led, color1);
    break;
    case 3:
      neo_strip3.setPixelColor(led, color1);
    break;
    case 4:
      neo_strip4.setPixelColor(led, color1);
    break;
    case 5:
      neo_strip5.setPixelColor(led, color1);
    break;
    case 6:
      neo_strip6.setPixelColor(led, color1);
    break;
    case 7:
      neo_strip7.setPixelColor(led, color1);
    break;
    case 8:
      neo_strip8.setPixelColor(led, color1);
    break;
    case 99:
      for (int i = 0; i <= 14;i++)
      {
        neo_setled(0,i,color1);
      }
    break;
    default:
    break;
  }
}
void neo_set_intensity(float intensity)
{
  maroon =   neo_strip1.Color((0x80 * intensity), (0x00 * intensity), (0x82 * intensity));//#800000
  Brown =    neo_strip1.Color((0x9A * intensity), (0x63 * intensity), (0x24 * intensity));//#9A6324
  Olive =    neo_strip1.Color((0x80 * intensity), (0x80 * intensity), (0x00 * intensity));//#808000
  Teal =     neo_strip1.Color((0x46 * intensity), (0x99 * intensity), (0x90 * intensity));//#469990
  Navy =     neo_strip1.Color((0x00 * intensity), (0x00 * intensity), (0x75 * intensity));//#000075
  Black =    neo_strip1.Color((0x00 * intensity), (0x00 * intensity), (0x00 * intensity));//#000000
  Red =      neo_strip1.Color((0xFF * intensity), (0x00 * intensity), (0x00 * intensity));//#E6194B
  Orange =   neo_strip1.Color((0xF5 * intensity), (0x82 * intensity), (0x31 * intensity));//#F58231
  Yellow =   neo_strip1.Color((0xFF * intensity), (0xE1 * intensity), (0x19 * intensity));//#FFE119
  Lime =     neo_strip1.Color((0xBF * intensity), (0xEF * intensity), (0x45 * intensity));//#BFEF45
  Green =    neo_strip1.Color((0x00 * intensity), (0xFF * intensity), (0x00 * intensity));//#3CB44B
  Cyan =     neo_strip1.Color((0x42 * intensity), (0xD4 * intensity), (0xF4 * intensity));//#42D4F4
  Blue =     neo_strip1.Color((0x00 * intensity), (0x00 * intensity), (0xFF * intensity));//#4363D8
  Purple =   neo_strip1.Color((0x91 * intensity), (0x1E * intensity), (0xB4 * intensity));//#911EB4
  Magenta =  neo_strip1.Color((0xF0 * intensity), (0x32 * intensity), (0xE6 * intensity));//#F032E6
  Grey =     neo_strip1.Color((0xA9 * intensity), (0xA9 * intensity), (0xA9 * intensity));//#A9A9A9
  Pink =     neo_strip1.Color((0xFA * intensity), (0xBE * intensity), (0xBE * intensity));//#FABEBE
  Apricot =  neo_strip1.Color((0xFF * intensity), (0xD8 * intensity), (0xB1 * intensity));//#FFD8B1
  Beige =    neo_strip1.Color((0xFF * intensity), (0xFA * intensity), (0xC8 * intensity));//#FFFAC8
  Mint =     neo_strip1.Color((0xAA * intensity), (0xFF * intensity), (0xC3 * intensity));//#AAFFC3
  Lavender = neo_strip1.Color((0xE6 * intensity), (0xBE * intensity), (0xFF * intensity));//#E6BEFF
  White =    neo_strip1.Color((0xFF * intensity), (0xFF * intensity), (0xFF * intensity));//#FFFFFF
  Yellow2 =   neo_strip1.Color((0xFF * intensity), (0xFF * intensity), (0x00 * intensity));//#FFE119
}
