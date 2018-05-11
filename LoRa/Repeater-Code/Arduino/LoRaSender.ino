#include <SPI.h>
#include <LoRa.h>

int counter = 0;
String Serialrecived;
void setup() {
  LoRa.begin(433E6);
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("Ready");
}

void loop() {
  while (Serial.available()) {
    Serialrecived = Serial.readString();

    Serial.print("Sending packet: ");
    Serial.println(Serialrecived);

    // send packet
    LoRa.beginPacket();
    LoRa.print(Serialrecived);

    LoRa.endPacket();
    Serial.println("Sent");

    delay(10);
  }

}
