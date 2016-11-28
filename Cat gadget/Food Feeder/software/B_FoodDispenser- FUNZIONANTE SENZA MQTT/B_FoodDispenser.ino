
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET LED_BUILTIN

Adafruit_SSD1306 display(OLED_RESET);

void printText(String text){
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(text);
  display.display();
  delay(500);
  
}

