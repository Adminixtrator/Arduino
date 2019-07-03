#include <SoftwareSerial.h>
#define Txd 10
#define Rxd 11


SoftwareSerial serialSIM800(Txd,Rxd);

void setup() {

delay(5000);
Serial.begin(9600);
serialSIM800.begin(9600);
delay(1000);
Serial.write("Setup Complete! Welcome MINIXTRATOR");

}


void loop() {

if(Serial.available() > 0){

  switch (Serial.read()){
    case 's' :
      SendMessage();
      break;
    case 'r' :
      RecieveMessage();
      break;
    case 'd' :
      DialCall();
      break;
    case 'c' :
      ReciveCall();
      break;
  }
  }

  if(serialSIM800.available() > 0){

    Serial.write(serialSIM800.read());
  }
}

void SendMessage(){

  serialSIM800.println("AT+CMGF=1");
  delay(1000);
  serialSIM800.println("AT+CMGS=\"+2347056643929\"\r");
  delay(1000);
  serialSIM800.println("I am SMS from GSM Module");
  delay(100);
  serialSIM800.println((char)26);
  delay(1000);
  serialSIM800.println("Message sent..");
}

void RecieveMessage(){
  
  serialSIM800.println("AT+CNMI=2,2,0,0,0");
  delay(1000);
}

void DialCall(){
  serialSIM800.println("ATD+2347056643929;");
  delay(100);
}

void ReciveCall(){
  
  serialSIM800.println("ATA");
  delay(100);
}
