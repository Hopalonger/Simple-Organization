#include <SPI.h>
#include <LoRa.h>
#include <Adafruit_NeoPixel.h>

// Color
int R = 255;
int G = 0;
int B = 123;


// Indicator Pin
#define IND 8
// Indicator LEDs
#define LND 8

#define indicator 40
#define indicator 0

// Hardware
String Device = "aaaa";
int leds = 60;
#define PIN 6
int clock = 5000; //Miliseconds before restarting tasks / Delay Make sure it is faster than the server



// Other things Please dont change
String Data = "";
String LED = "";
int sendpixel;
int Send;
String Data4 = "";
int count = 0;
// Set to NEO_KHZ400 if using a 8MHz 3.3v Board
Adafruit_NeoPixel strip = Adafruit_NeoPixel(leds, PIN, NEO_GRB + NEO_KHZ400);
Adafruit_NeoPixel ind = Adafruit_NeoPixel(LND, IND, NEO_GRB + NEO_KHZ400);
uint32_t low = strip.Color(0, 0, 0);
void Indicator() {
  count = 0;
  while (count < LND) {
    ind.setPixelColor(count, 0, 0, 0);
    count++;
  }
  ind.show();
}
void Start() {

  count = 0;
  while (count < LND) {
    ind.setPixelColor(count, 255, 255, 255);
    count++;
  }
  ind.show();

  count = 0;
  while (count < leds) {
    strip.setPixelColor(count, 255, 255, 255);
    count++;
  }
  strip.show();
  delay(5000);

  for ( int i = 0; i < LND; i++) {
    ind.setPixelColor(i, low);
    ind.show();
  }

  for ( int i = 0; i < leds; i++) {
    strip.setPixelColor(i, low);
    strip.show();
  }

  Serial.println("Light Check");

}
void setup() {
  LoRa.begin(433E6);
  LoRa.begin(433E6);
  Serial.begin(9600);
  while (!Serial);
  strip.begin();
  strip.show();

  Serial.println("LoRa Receiver");
  Start();
  if (!
      LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received Device Code: '");

    // read packet
    while (LoRa.available()) {
      Data = LoRa.readString();
      Data4 = Data.substring(0, 4);
      Serial.println(Data.substring(0, 4));
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
  if (Data4 == Device) {
    Serial.print("Recived LED:");
    LED = Data.substring(4);
    Serial.println(LED);

    Data = "";
    Data4 = "";
    sendpixel = LED.toInt();
   
  strip.setPixelColor(sendpixel, R, G, B);
  strip.show();
 LED = -1;
    }

  }

  


