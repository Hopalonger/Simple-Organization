#include <mdns.h>
#include <ESP8266WiFi.h>
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

#include <mDNSResolver.h>          https://github.com/madpilot/mDNSResolver

#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <Adafruit_NeoPixel.h>
//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
//*******************************************************Settings*************************************************
// Change to the Server Hostname
#define HOSTNAME      "Simple.local"
// Color
#define R 255
#define G 255
#define B 255
// Number of LED's
#define LED 60
// Led Connected Pin
#define PIN 6
// Device Code
#define Code "aaaa"
//*******************************************************Settings End*********************************************
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED, PIN, NEO_GRB + NEO_KHZ400);
IPAddress   ip = 1;
using namespace mDNSResolver;
WiFiClient wifiClient;
WiFiUDP udp;
Resolver resolver(udp);
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

  resolver.setLocalIP(WiFi.localIP());
  IPAddress   ip = resolver.search(HOSTNAME);
  if (ip != INADDR_NONE) {
    Serial.print("Resolved: ");
    Serial.println(ip);
  } else {
    Serial.println("Not resolved");
  }
  Serial.print("Scanning for Device Code:");
  Serial.println(Code);

}

void loop() {
  String ipString = String(ip[0]);
  for (byte octet = 1; octet < 4; ++octet) {
    ipString += '.' + String(ip[octet]);
  }

  // put your main code here, to run repeatedly:
  HTTPClient http;  //Declare an object of class HTTPClient
  http.begin(ipString);  //Specify request destination

  int httpCode = http.GET();
  if (httpCode > 0) { //Check the returning code

    String payload = http.getString();
    Serial.print("Received: '");
    Serial.println(payload);
    String Data = payload;
    String Data4 = Data.substring(0, 4);
    Serial.print("Received Device Code:");
    Serial.println(Data.substring(0, 4));
    if (Data4 == Code) {
      Serial.print("Recived LED:");
      String LEDs = Data.substring(4);
      Serial.println(LED);
      Data = "";
      Data4 = "";
      int l = LEDs.toInt();
      strip.setPixelColor(l, R, G, B);
    }
    else {
      Serial.println("HTTP Not Working");

    }
    resolver.loop();
  }
}
