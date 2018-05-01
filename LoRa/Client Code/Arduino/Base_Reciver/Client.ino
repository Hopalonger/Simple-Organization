
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
Adafruit_NeoPixel strip = Adafruit_NeoPixel(leds, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ind = Adafruit_NeoPixel(LND, IND, NEO_GRB + NEO_KHZ800);
void Indicator() {
  count = 0;
  while (count < LND) {
    ind.setPixelColor(count, 0, 0, 0);
    count++;
  }

}
void setup() {
  LoRa.begin(433E6);
  LoRa.begin(433E6);
  Serial.begin(9600);
  while (!Serial);
  strip.begin();
  strip.show();
  Serial.println("LoRa Receiver");

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
    Data = "";nb v
    Data4 = "";
  }
  sendpixel = LED.toInt();
  LED = -1;
  if (sendpixel >= leds) {
    Serial.println("Number to big");
    delay(clock);
  }
  else {
    bool Largetray = true;
    // Large Trays
    bool Large1 = true;
    bool Large2 = true;
    bool Large3 = true;
    bool Large4 = true;
    bool Large5 = true;
    bool Large6 = true;
    bool Large7 = true;
    bool Large8 = true;
    bool Large9 = true;
    //Large Trays Put Specified values Make Sure They are unique
    int Largetr1 = 45;
    int Largetr2 = 102;
    int Largetr3 = 103;
    int Largetr4 = 104;
    int Largetr5 = 105;
    int Largetr6 = 106;
    int Largetr7 = 107;
    int Largetr8 = 108;
    int Largetr9 = 109;
    //LargeTrays LED value Multi Diget do not add,
    int LargetrLED1 = 2;
    int LargetrLED2 = 23;
    int LargetrLED3 = 23;
    int LargetrLED4 = 23;
    int LargetrLED5 = 23;
    int LargetrLED6 = 23;
    int LargetrLED7 = 23;
    int LargetrLED8 = 23;
    int LargetrLED9 = 23;
    if (Largetray == true) {
      if (Large1 == true) {
        if (sendpixel == Largetr1) {
          Send = LargetrLED1;
          Serial.println("Using Large Tray 1");
          strip.setPixelColor(Send, R, G, B);
          strip.show();
          Send = "";
          sendpixel = "";
        }
        // End of start block

      }
      //One Block
      else if (Large2 == true) {
        if (sendpixel == Largetr2) {
          Send = LargetrLED2;
          Serial.print("Using Large Tray 2");
          strip.setPixelColor(Send, R, G, B);
          strip.show();
          Indicator();
          Send = "";
          sendpixel = "";
        }

      }
      // End Of Block 2
      else if (Large3 == true) {
        if (sendpixel == Largetr3) {
          Send = LargetrLED3;
          Serial.println("Using Large Tray 3");
          strip.setPixelColor(Send, R, G, B);
          strip.show();
          Indicator();
          Send = "";

          sendpixel = "";
        }

      }
      // End Of Block 3
      else if (Large4 == true) {
        if (sendpixel == Largetr4) {
          Send = LargetrLED4;
          Serial.println("Using Large Tray 4");
          strip.setPixelColor(Send, R, G, B);
          strip.show();
          Indicator();
          Send = "";
          sendpixel = "";
        }

      }
      // End Of Block 4
      else if (Large5 == true) {
        if (sendpixel == Largetr5) {
          Send = LargetrLED5;
          Serial.println("Using Large Tray 5");
          strip.setPixelColor(Send, R, G, B);
          strip.show();
          Indicator();
          Send = "";
          sendpixel = "";
        }

      }
      // End Of Block 5
      else if (Large6 == true) {
        if (sendpixel == Largetr6) {
          Send = LargetrLED6;
          Serial.println("Using Large Tray 6");
          strip.setPixelColor(Send, R, G, B);
          strip.show();
          Indicator();
          Send = "";
          sendpixel = "";
        }

      }
      // End Of Block 6

      else if (Large7 == true) {
        if (sendpixel == Largetr7) {
          Send = LargetrLED7;
          strip.setPixelColor(Send, R, G, B);
          strip.show();
          Indicator();
          Serial.println("Using Large Tray 7");
          Send = "";
          sendpixel = "";
        }

      }
      // End Of Block 7

      else if (Large8 == true) {
        if (sendpixel == Largetr8) {
          Send = LargetrLED8;
          Serial.println("Using Large Tray 8");
          strip.setPixelColor(Send, R, G, B);
          strip.show();
          Indicator();
          Send = "";
          sendpixel = "";
        }

      }
      // End Of Block 8

      else if (Large9 == true) {
        if (sendpixel == Largetr9) {
          Send = LargetrLED9;
          Serial.println("Using Large Tray 9");
          strip.setPixelColor(Send, R, G, B);
          strip.show();
          Indicator();
          Send = "";
          sendpixel = "";
        }

      }
      else
      {
        // End Of Block 9
        Send = sendpixel;
        strip.setPixelColor(Send, R, G, B);
        strip.show();
        Indicator();
        Send = "";
        sendpixel = "";
      }
    }
    else {
      // End Of Block 9
      Send = sendpixel;
      strip.setPixelColor(Send, R, G, B);
      strip.show();
      Indicator();
      Send = "";
      sendpixel = "";
    }

  }

}





