#include <SoftwareSerial.h>
SoftwareSerial NFCserial(2, 3); // RX, TX

uint8_t initialise_cmd_set_freq[23] = {0x15, 0xF0, 0x03, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x72, 0x61, 0x70, 0x69, 0x64, 0x72, 0x61, 0x64, 0x69, 0x6F, 0x83, 0x54};   // for frequency Set

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
  NFCserial.write(initialise_cmd_set_freq, 23);   // for frequency set
  show_serial_data();
  delay(3000);
}
