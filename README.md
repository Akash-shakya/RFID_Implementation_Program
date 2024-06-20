# RFID_Implementation_Program
This GitHub repository contains Arduino code designed for managing RFID systems. With this code, users can set the RFID frequency and adjust the transmission power. Additionally, the code allows users to retrieve detailed information about the RFID reader. It also facilitates the detection of RFID tags and the extraction of their Electronic Product Code (EPC). This repository provides a comprehensive solution for customizing and optimizing RFID operations using Arduino.

<h2>Connecting the RRUHFOEM01 RFID Reader Module to Arduino</h2>
<h3>To use the RRUHFOEM01 RFID reader module with an Arduino, follow the connection instructions below:</h3>

• VCC: Connect the VCC pin of the RFID module to the 5V pin on the Arduino.<br>
• GND: Connect the GND pin of the RFID module to the GND pin on the Arduino.<br>
• TX: Connect the TX pin of the RFID module to Digital Pin 2 on the Arduino.<br>
• RX: Connect the RX pin of the RFID module to Digital Pin 3 on the Arduino.<br>

<h3>Configuration Password:</h3> 
• It is used when changing any system level command and interface configuration. Remaining bytes must be Null.<br>
• Default configuration password is rapidradio.<br>
• Hex Command of rapidradio is 7261706964726164696f<br>
• we make this of length 16 so we add additional zeros.<br>
• so the password is 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x72, 0x61, 0x70, 0x69, 0x64, 0x72, 0x61, 0x64, 0x69, 0x6F<br>

<h1>BASIC COMMUNICATION FRAME FORMAT</h1>
This format is essential for understanding how data is structured and transmitted between devices.

![image](https://github.com/Akash-shakya/RFID_Implementation_Program/assets/48617331/ba45fa6f-5f0c-4c98-8797-39f24ed1f9d2)


<h2>For Set the Power</h2>
Power of RFID reader by sending the following command :
0x14, 0xF0, 0x06, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x72, 0x61, 0x70, 0x69, 0x64, 0x72, 0x61, 0x64, 0x69, 0x6F, 0x31, 0x17

• 14 : Frame length <br>
• F0-06 : Command Code for Set Power<br>
• 13 : 13H in Hex means 19 in Decimal, So power is set to 19 dBm<br>
• 00-00-00-00-00-00-72-61-70-69-64-72-61-64-69-6F : Password of RFID module<br>
• 3117 : CRC<br>

<h2>For Set the Frequency</h2>
Frequency of RFID reader by sending the following command :
0x15, 0xF0, 0x03, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x72, 0x61, 0x70, 0x69, 0x64, 0x72, 0x61, 0x64, 0x69, 0x6F, 0x83, 0x54. 

• 15 : Frame length <br>
• F0-03 : Command Code for Set Frequency <br>
• 07 : Maximum frequency <br> 07 for set maximum frequency 866.5 MHz
• 02 : Minimum frequency <br> 02 for set minimum frequency 865.5 MHz
• 00-00-00-00-00-00-72-61-70-69-64-72-61-64-69-6F : Password of RFID module <br>
• 83-54 : CRC <br>
![image](https://github.com/Akash-shakya/RFID_Implementation_Program/assets/48617331/f49b844f-d581-43e4-8597-1e531292e293)

<h2>To get reader Details</h2>
we get the Reader details by sending the following command : 0x03, 0xF0, 0x02, 0x8B, 0x2F
• 03: Frame length<br>
• F0-02 : Command Code for Get Reader details<br>
• 8B-2F : CRC<br>

<h2>Read the EPC of tag</h2>
EPC is read by sending the following Command : 0x03, 0x50, 0x02, 0x3E, 0xC5
• 03: Frame length<br>
• 50-02 : Command Code for Get EPC<br>
• 3E-C5 : CRC<br>

<b>Note</b> : For Calculation of CRC : Enter all Hex command in sequence including the Frame length without spacing in online CRC Calculator tool.   
