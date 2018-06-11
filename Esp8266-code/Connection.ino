#include <WiFiManager.h>

#include <Adafruit_NeoPixel.h>

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//******************************************************************************
// Device Code
String Code = "aaaa";
// Server IP
String  ipString = "10.42.252.161";
//color
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
//*******************************************************************************
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED, PIN, NEO_GRB + NEO_KHZ400);
Adafruit_NeoPixel ind = Adafruit_NeoPixel(LND, IND, NEO_GRB + NEO_KHZ400);

WiFiClient wifiClient;
WiFiUDP udp;

IPAddress ip;
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
  Serial.begin(115200);
  int WiFiCounter = 0;
  // We start by connecting to a WiFi network
  Serial.println("Connecting to Internet. Connect Through Gatway.");

  WiFiManager wifiManager;

  wifiManager.autoConnect("Organization");
  
 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Resolving ");
  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
}

void loop() {
  
  // Required to clear the UDP buffer, as we can't unjoin a multicast group yet
  Serial.println("Running");
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    Serial.print("Connecting to:");

    HTTPClient Check;
    HTTPClient http;  //De lare an object of class HTTPClient
    
    String url = "http://" + ipString + "/newfile.txt";
    String Power = "http://" + ipString + "/power.txt";
    Serial.println(url);
    Serial.println(Power);
    Check.begin(Power);

    int httpCode = Check.GET();                                                                  //Send the request

    if (httpCode > 0) { //Check the returning code
      String Client = Check.getString();
      Serial.println("Checking Server");
      if (Client.toInt() > 100) {
        Check.end();
        
        Serial.println("Recent");
        String url = "http://" + ipString + "/newfile.txt";
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
          Serial.println("Test");
          if ( Code == payload.substring(0, 4)) {
            Serial.print("Got Code");
            Serial.println(payload.substring(0, 4));
            Serial.print("Got LED:");
            Serial.println(payload.substring(4));
            String light = payload.substring(4);
            strip.setPixelColor(light.toInt(), R, G, B);
            Indicator();
            light = "";
            delay(5000); 
          }
          else {
            Serial.println("Not THis Device");
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
