#include <ESP8266WiFi.h>          // Required Esp8266 Library's For functionality
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiUdp.h>
#include <ESP8266HTTPClient.h>

#include <mDNSResolver.h>          //https://github.com/madpilot/mDNSResolver Also under the Libary manager under as esp8266_mDNS
#include <ESP8266WiFi.h>          //https://github.com/tzapu/WiFiManager Also under the Libary manager under as WifiManager
#include <Adafruit_NeoPixel.h>
//needed for library Wifi Manager
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
//*******************************************************Settings*************************************************
// Change to the Server Hostname
#define HOSTNAME      "raspberrypi-2.local"
// Color
#define R 255
#define G 255
#define B 255
// Number of LED's
#define LED 60
// Led Connected Pin
#define PIN 6
// Indicator Pin
#define IND 8
// Indicator LEDs
#define LND 8
// Device Code
#define Code "aaaa"
//*******************************************************Settings End*********************************************
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED, PIN, NEO_GRB + NEO_KHZ400);
Adafruit_NeoPixel ind = Adafruit_NeoPixel(LND, IND, NEO_GRB + NEO_KHZ400);
IPAddress   ip = 1;
using namespace mDNSResolver;
WiFiClient wifiClient;
WiFiUDP udp;
Resolver resolver(udp);
void Indicator() {
  int count = 0;
  while (count < LND) {
    ind.setPixelColor(count, 255, 255, 255);
    count++;
  }

}
void Start() {
  int count = 0;
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
  delay(5000);
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
  wifiManager.autoConnect("Organization");
  //or use this for auto generated name ESP + ChipID
  //wifiManager.autoConnect();


  //if you get here you have connected to the WiFi
  Serial.println("Connected to Internet.");
  Serial.println("Running Light Test");
  delay(2000);
  if (WiFi.status() == WL_CONNECTED){

  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Resolving ");
  Serial.println(HOSTNAME);
  
  resolver.setLocalIP(WiFi.localIP());
  
  IPAddress   ip = resolver.search(HOSTNAME);
  if (ip != INADDR_NONE) {
    Serial.print("Resolved: ");
    Serial.println(ip);
    
  } else {
    Serial.println("Not resolved");
    Serial.println(ip);
  }
  Serial.print("Scanning for Device Code:");
  Serial.println(Code);
  }
}

void loop() {
  while (WiFi.status() == WL_CONNECTED ) {
    
    String Ip2 = "http://" + ip;
    // put your main code here, to run repeatedly:
    HTTPClient http;  //Declare an object of class HTTPClient
    http.begin( Ip2 + "/newfile.txt");  //Specify request destination

    int httpCode = http.GET();
    if (httpCode > 0) { //Check the returning code

      String payload = http.getString();
          delay(100);
          Serial.print("Received: '");
          Serial.println(payload);
          String Data4 = payload.substring(0, 4);
          delay(100);
          Serial.print("Received Device Code:");
          Serial.println(Data4);
          delay(100);
          if (Data4 == Code) {
            Serial.print("Recived LED:");
            String LEDs = payload.substring(4);
            Serial.println(LED);
            delay(100);
            payload = "";
            Data4 = "";
            delay(100);
            int l = LEDs.toInt();
            strip.setPixelColor(l, R, G, B);
            LEDs = "";
            delay(100);
            l = 0;
            Indicator();
            http.end();
      }
      else {
        Serial.println("HTTP Not Working");

      }
       resolver.loop();
       delay(1000);
    }
  }
}
