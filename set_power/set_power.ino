#include <SoftwareSerial.h>
SoftwareSerial NFCserial(2, 3); // RX, TX

uint8_t initialise_cmd_set_power[22] = {0x14, 0xF0, 0x06, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x72, 0x61, 0x70, 0x69, 0x64, 0x72, 0x61, 0x64, 0x69, 0x6F, 0x19, 0xE9};   // for power Set

void setup() {
  Serial.begin(9600);
  NFCserial.begin(115200);
  }

void show_serial_data() {
  int count = 0;
  bool started = false;
  while (count < 1000)
  {
    if(NFCserial.available() != 0)
    {
      Serial.print(NFCserial.read(), HEX);
      Serial.print("-");
      started = true;
    }
    else if (started)
      break;
    count++;
    delay(1);
  }
  Serial.println("");
}

void loop() 
{
  Serial.println("Response:");
  NFCserial.write(initialise_cmd_set_power, 22);   // for set power
  show_serial_data();
  delay(3000);
}