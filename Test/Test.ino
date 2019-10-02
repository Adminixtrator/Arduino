#include <Sim800l.h>
#include <SoftwareSerial.h>
#define Txd 10
#define Rxd 11
Sim800l Sim800l;  //to declare the library


SoftwareSerial serialSIM800(Txd,Rxd);

void setup() {
  // put your setup code here, to run once:

  delay(5000);
  Serial.begin(9600);
  serialSIM800.begin(9600);
  delay(1000);
  Serial.write("Setup Complete! Welcome MINIXTRATOR");
  delay(100);

  
  
    
      // Initiation begins..
      
}

void loop() {
  // put your main code here, to run repeatedly:
  serialSIM800.begin(9600);
  
  if (serialSIM800.available() > 0){
    Serial.write(serialSIM800.read());
  }

        serialSIM800.println("AT+CGATT=1"); //Connect SIM to GPROS
  delay(10);
  serialSIM800.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\""); //Activate bearer profile with connection type GPRS
  delay(10);
  serialSIM800.println("AT+SAPBR=3,1,\"APN\",\"RCMNET\""); //Set VPN for bearer Profile
  delay(10);
  serialSIM800.println("AT+SAPBR=1,1"); //Open Bearer profile
  delay(10);
  serialSIM800.println("AT+SAPBR=2,1"); // Get the IP address of the bearer profile 
  delay(10);
  serialSIM800.println("AT+CIPGSMLOC=1,1"); //Request for location Pincode, latitude and longitude
  delay(10);
  
}
