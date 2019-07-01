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

int day,month,year,minute,second,hour;



void setup(){
	Serial.begin(9600); // only for debug the results . 
	Sim800l.begin(); // initializate the library.

	// the parameter to send is UTC of your country
	Sim800l.updateRtc(-3); //

}

void loop(){
	Sim800l.RTCtime(&day,&month,&year,&hour,&minute,&second);
	//at this moment the variables have the real time. 
	Serial.print(day);
	Serial.print('/');
	Serial.print(month);
	Serial.print('/');
	Serial.print(year);
	Serial.print(' ');
	Serial.print(hour);
	Serial.print(':');
	Serial.print(minute);
	Serial.print(':');
	Serial.print(second);
	Serial.println();
}

/*Aang Studios
 * ADMINIXTRATOR
 */
