#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <Adafruit_NeoPixel.h>
//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <mDNSResolver.h>
#include <esp8266wifi.h>
#include <esp8266httpclient.h>
// Change to the Server Hostname 
IPAddress ip = resolver.search("Simple.local");
// Color
int R = 255;
int G = 0;
int B = 123;
// Led Frequency
// Set to NEO_KHZ800 if using a 8MHz 3.3v Board
Adafruit_NeoPixel strip = Adafruit_NeoPixel(leds, PIN, NEO_GRB + NEOKZH400);
Adafruit_NeoPixel ind = Adafruit_NeoPixel(LND, IND, NEO_GRB + NEO_KHZ400);


// Enable Debug Led On Pin 1
bool Debug = True;
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

void Indicator() {
  count = 0;
  while (count < LND) {
    ind.setPixelColor(count, 255, 255, 255);
    count++;
  }

}
void Start() {
count = 0;
  while (count < LND) {
    strip.setPixelColor(count, 255, 255, 255);
    count++;
  }
   count = 0;
  while (count < LND) {
    ind.setPixelColor(count, 255, 255, 255);
    count++;
  }
  ind.show();
  
  strip.show();
  delay(5000)
  count = 0;
  while (count < LND) {
    strip.setPixelColor(count, 0, 0, 0);
    count++;
  }
  
  count = 0;
  while (count < LND) {
    ind.setPixelColor(count, 0, 0, 0);
    count++;
  }
  ind.show();
  strip.show();
}


void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);

    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    //reset saved settings
    //wifiManager.resetSettings();
    
    //set custom ip for portal
    //wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

    //fetches ssid and pass from eeprom and tries to connect
    //if it does not connect it starts an access point with the specified name
    //here  "AutoConnectAP"
    //and goes into a blocking loop awaiting configuration
    wifiManager.autoConnect("AutoConnectAP");
    //or use this for auto generated name ESP + ChipID
    //wifiManager.autoConnect();

    
    //if you get here you have connected to the WiFi
    Serial.println("Connected to Internet.");
    Serial.println("Running Light Test");
    Adafruit_NeoPixel De = Adafruit_NeoPixel(1, 2, NEO_GRB + Frq);
    De.setPixelColor(0,0,255,0)
    }
  
    Start();

}

void loop() {
    // put your main code here, to run repeatedly:
    HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin("http://jsonplaceholder.typicode.com/users/1");  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();
      Serial.print("Received: '");
      Serial.println(payload);
      Data = payload;
      Data4 = Data.substring(0, 4);
      Serial.print("Received Device Code:");
      Serial.println(Data.substring(0, 4));
      if (Data4 == Device) {
    Serial.print("Recived LED:");
    LED = Data.substring(4);
    Serial.println(LED);
    Data = "";
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
}
}
