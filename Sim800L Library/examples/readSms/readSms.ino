/* minixtrator@gmail.com


    This code is designed to work with the GSM Sim800l Library in this repository

      PINOUT:
          _____________________________
         |ARDUINO UNO  >>>   SIM800L  |
          -----------------------------
              GND      >>>   GND
          RX or 10     >>>   TX
          TX or 11     >>>   RX
         RESET or 2    >>>   RST

     POWER SOURCE 3.4V - 4.5V >>> VCC


*/


#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library
String text;     // to almacenate the text of the sms
uint8_t index;   // to indicate the message to read.


void setup(){
	Serial.begin(9600); // only for debug the results . 
	Sim800l.begin(); // initializate the library. 
	index=1; // first position in the prefered memory storage. 
	text=Sim800l.readSms(index);   	
	Serial.println(text);

}

void loop(){
	//do nothing
}

/*Aang Studios
 * ADMINXTRATOR
 * /
 */
