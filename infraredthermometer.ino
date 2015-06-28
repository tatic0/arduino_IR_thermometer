#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#define TFT_CS     10
#define TFT_RST    9  // you can also connect this to the Arduino reset 
#define TFT_DC     8
#define Landscape  1
// Color definitions
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

// IR part
#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

float temp;

void setup() {
  mlx.begin();  
 // Use this initializer if you're using a 1.8" TFT
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  uint16_t time = millis();
  tft.fillScreen(ST7735_BLACK);
  tft.setRotation (Landscape);
  tft.print("You are getting nerdier every second you stare at this screen...");
  delay(300);
}

void loop() {
   tft.setCursor(45, 50);
   tft.setTextSize(3);
   temp=mlx.readObjectTempC();
   //tft.print(mlx.readObjectTempC());
   tft.print(temp);
   delay(500);
   tft.fillScreen(ST7735_BLACK);
}
