#include <Adafruit_NeoPixel.h>
#include <WiFiManager.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>  
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
//*********************************************************
// Which pin on the Arduino is connected to the NeoPixels for the Main Strip?
#define PIN            15
// How many NeoPixels are attached to the Arduino for the Main Strip?
#define NUMPIXELS      60
// Which pin on the Arduino is connected to the NeoPixels for the Indicator Strip?
#define IND 5
// How many NeoPixels are attached to the Arduino for the Indicator Strip?
#define LND 8
// Ip Address of Server (last 2 or 3 Digits of IP works best with static IP on the same subnet such as 10.42.252.179.
// 179 would be the number we want.
#define ipend 181
// Device Code 4 Char Alpha Numerical 
String Code = "aaaa";
//Color in RGB
#define R 255
#define G 255
#define B 255
//**************************************************************
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ind = Adafruit_NeoPixel(LND, IND, NEO_GRB + NEO_KHZ800);
WiFiClient wifiClient;
WiFiUDP udp;
IPAddress ip;
String Ip;
String Da;
void setup() {
  Serial.begin(115200);
  // Internet Connection With The Wifi Manager Libary
  WiFiManager wifiManager;
  wifiManager.autoConnect("Organization");
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  // Test the connected LEDS with a Green Color On Boot
  for (int i = 0; i < NUMPIXELS; i++) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Moderately bright green color.

    // Delay for a period of time (in milliseconds).

  }
  pixels.show(); // This sends the updated pixel color to the hardware.

  delay(5000);
  for ( int i = 0; i < NUMPIXELS; i++) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.

    // Delay for a period of time (in milliseconds).

  }
  pixels.show();
}
void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  Serial.println("Running");
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    Serial.print("Connecting to:");

    HTTPClient Check;
    HTTPClient http;  //De lare an object of class HTTPClient
    IPAddress ipstring = WiFi.localIP();
    Ip = String(ipstring[0]) + '.' + String(ipstring[1]) + '.' + String(ipstring[2]) + '.' + ipend ;
    String url = "http://" + Ip + "/access.txt;
    String Power = "http://" + Ip + "/recent.txt";
    Serial.println(url);
    Serial.println(Power);
    Check.begin(Power);

    int httpCode = Check.GET();                                                                  //Send the request

    if (httpCode > 0) { //Check the returning code
      String C = Check.getString();
      Serial.println("Checking Server");
      Serial.println("Got: " + C);
      if (C.toInt() > 100) {
        Check.end();
        Serial.println("Recent");
        http.begin(url);  //Specify request destination
        int bad = http.GET();
        Serial.print("Connecting:");
        Serial.println(bad);
        if (bad > 0) {
          Serial.println(url);
          String payload = http.getString();
          //Get the request response payload
          Serial.print("Got:");
          Serial.println(payload);    //Print the response payload
          if ( Code == payload.substring(0, 4)) {
            Serial.print("Got Code");
            Serial.println(payload.substring(0, 4));
            Serial.print("Got Data:");
            Serial.println(payload.substring(4));
            String D = payload.substring(4);
            int i = 0;
            while ( i < 7) {
              Serial.println(D);
              Serial.print(D.charAt(4 - i * 2));
              Serial.println(D.charAt(5 - i * 2));
              Da = String(D.charAt(4 - i * 2)) + String(D.charAt(5 - i * 2));
              D.remove(5 - i * 2);

              Serial.println(D);
              Serial.print("String: ");
              Serial.println(Da);
              Serial.println("Done");
              pixels.setPixelColor(Da.toInt(), R, G, B);
              i++;

            }
            pixels.show();
            Indicator();
            Da ="";
            
            delay(5000);
          }
          else {
            Serial.println("Not This Device");
          }
        }
      }
      else {
        Serial.println("Not Recent");
        Check.end();
      }
      http.end();   //Close connection
      delay(1000);
    }
  }
}

void Indicator() {
  int count = 0;
  while (count < LND) {
    ind.setPixelColor(count, 255, 255, 255);
    count++;
  }
  ind.show();


}
