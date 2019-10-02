/* Created on the 2nd of October 2019 by ADMINIXTRATOR
 *  minixtrator@gmail.com
 *  
 *  LOCATION TRACKER WITH Sim800L
 *  
 *  This code is designed to work with the GSM Sim800l Library in this repository

      PINOUT:
          _____________________________
         |ARDUINO UNO  >>>   SIM800L  |
          -----------------------------
              GND      >>>   GND
          RX or 10     >>>   TX
          TX or 11     >>>   RX
         RESET or 2    >>>   RST

     POWER SOURCE 3.4V - 4.5V >>> VCC
 *  
 */
#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library

String textSms, numberSms, message;
bool error;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600); // only for debug the results .
  Sim800l.begin(); // initializate the library.
  //don't forget to catch the return of the function delAllSms!
  error = Sim800l.delAllSms(); //clean memory of sms;

}

void loop() {
  // put your main code here, to run repeatedly:

  textSms = Sim800l.readSms(1); //read the first sms


  if (textSms.length() > 7)  // optional you can avoid SMS empty
  {

    numberSms = Sim800l.getNumberSms(1); // Here you have the number
    //for debugin
    textSms.toUpperCase();  // set all char to mayus ;)

    if (textSms.indexOf("Loc") != -1) {
      #define Td 11
      #define Rd 10

      SoftwareSerial serialSIM800(Td,Rd);
      serialSIM800.begin(9600);
      // Initiation begins..
      serialSIM800.println("AT+CGATT=1"); //Connect SIM to GPROS
      delay(1000);
      serialSIM800.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\""); //Activate bearer profile with connection type GPRS
      delay(1000);
      serialSIM800.println("AT+SAPBR=3,1,\"APN\",\"RCMNET\""); //Set VPN for bearer Profile
      delay(1000);
      serialSIM800.println("AT+SAPBR=1,1"); //Open Bearer profile
      delay(1000);
      serialSIM800.println("AT+SAPBR=2,1"); // Get the IP address of the bearer profile 
      delay(1000);
      serialSIM800.println("AT+CIPGSMLOC=1,1"); //Request for location Pincode, latitude and longitude
      delay(100);

      SendMessage("Still on this");
    }

    }
    else if (textSms.indexOf("Loc") = -1) {
      message = "Error! Invalid Command."
      SendMessage(message);
    }
    else{
      message = "Tracking Failed"
      SendMessage(message);
    }
      
}

String message;

String SendMessage(message){

  serialSIM800.println("AT+CMGF=1");
  delay(1000);
  serialSIM800.println("AT+CMGS=\"+2349059329620\"\r");
  delay(1000);
  serialSIM800.println(message);
  delay(100);
  serialSIM800.println((char)26);
}
