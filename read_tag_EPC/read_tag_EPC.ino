#include <SoftwareSerial.h>
SoftwareSerial NFCserial(2, 3); // RX, TX

uint8_t initialise_cmd_iso14443_1[5] = {0x03, 0x50, 0x02, 0x3E, 0xC5};   // inventory EPC

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
  NFCserial.write(initialise_cmd_iso14443_1, 5);   // for inventory epc 
  show_serial_data();
  delay(2000);
}