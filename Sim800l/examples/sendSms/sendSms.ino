/* This library was refurbished by ADMINIXTRATOR @Aang Studios.
 *      minixtrator@@gmail.com
 *  Designed to work with the GSM Sim800l,maybe work with SIM900L
 *  
 *     This library use SoftwareSerial, you can define the RX and TX pin in the header "Sim800l.h" ,by default the pin is RX=10 TX=11..
 *     Be sure that gnd is attached to arduino too. 
 *     You can also change the other preferred RESET_PIN
 *    
 *     Esta libreria usa SoftwareSerial, se pueden cambiar los pines de RX y TX
 *     en el archivo header, "Sim800l.h", por defecto los pines vienen configurado en
 *     RX=10 TX=11.  
 *     Tambien se puede cambiar el RESET_PIN por otro que prefiera
 *     
 *    PINOUT: 
 *        _____________________________
 *       |  ARDUINO UNO >>>   SIM800L  |
 *        -----------------------------
 *            GND      >>>   GND
 *        RX  10       >>>   TX    
 *        TX  11       >>>   RX
 *       RESET 2       >>>   RST 
 *                 
 *   POWER SOURCE 3.4V to 4.7V >>> VCC
 *
 *    Refurbished on: June 28, 2019
 *    Refurbish Author: ADMINIXTRATOR
 *        
 *
*/

#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library
char* text;
char* number;
bool error; //to catch the response of sendSms


void setup(){
	Sim800l.begin(); // initializate the library. 
	text="Testing Sms";  //text for the message. 
	number="2926451386"; //change to a valid number.
	error=Sim800l.sendSms(number,text);
	// OR 
	//Sim800l.sendSms("+540111111111","the text go here")


}

void loop(){
	//do nothing
}