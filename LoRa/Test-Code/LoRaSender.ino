#include <SPI.h>
#include <LoRa.h>

int counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  LoRa.begin(433E6);
  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  String Data ="aaaa45";
  Serial.print("Sending packet: ");
  Serial.println(Data);
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print(Data);
//  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(5000);
}
