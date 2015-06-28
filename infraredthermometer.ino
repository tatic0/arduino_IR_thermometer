#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#define TFT_CS     10
#define TFT_RST    9  // you can also connect this to the Arduino reset 
#define TFT_DC     8
#define Landscape  1
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

float temp;

void setup() {
  mlx.begin();
  Serial.begin(9600);  
 // Use this initializer if you're using a 1.8" TFT
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  uint16_t time = millis();
  time = millis() - time;
  tft.fillScreen(ST7735_BLACK);
  tft.setRotation (Landscape);
  tft.println("You are getting nerdier every second you stare at this screen...");
  delay(300);
}

void loop() {
   tft.setTextSize(1);
   tft.setTextColor(WHITE);
   tft.setCursor(35,15);
   tft.print("uptime: ");
   tft.print(millis() / 1000);
   tft.print("s");
   tft.setCursor(35, 50);
   tft.setTextSize(3);
   temp=mlx.readObjectTempC();
   if (temp < 5) {
     tft.setTextColor(BLUE);
   }
   else if (temp > 30) {
     tft.setTextColor(RED);
   }
   //tft.setTextColor(MAGENTA);
   tft.print(temp);
   //tft.println(mlx.readObjectTempC());
   //Serial.println(mlx.readObjectTempC());
   tft.setCursor(35,75);
   tft.setTextSize(1);
   tft.println("Celsius degrees");
   delay(500);
   tft.fillScreen(ST7735_BLACK);
}
