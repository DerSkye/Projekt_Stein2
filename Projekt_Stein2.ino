//change ssid and password for new network. hard coded

#include "WiFi.h"     //Including Library for WiFi Login
int ledPin2 = 2;      //Defining pinport 2 as ledPin2
int ledPin16 = 16;    //Defining pinport 16 ledPin16
                      //circuit will close over grnd
const char* ssid = "";   //defining SSID 
const char* password =  "";     //defining password for ssid

void setup() {
 
  Serial.begin(300);
 
  WiFi.begin(ssid, password);   //try to connect with WiFi
  pinMode(ledPin2, OUTPUT);     //setting Pins as Output
  pinMode(ledPin16, OUTPUT);
}
  void loop () {
    while(1 == 1){    //looping forever true
      
      while (WiFi.status () == WL_CONNECTED){   //loop true as long wifi connected
        digitalWrite(ledPin16, LOW);            //setting led pin 16 off
        digitalWrite(ledPin2, HIGH);            //seeting led pin 2 on
        delay(1000);}                           //waiting

      while (WiFi.status() != WL_CONNECTED) {   //loop true as long wifi not connected
        digitalWrite(ledPin2, LOW);             //setting led pin 2 off
        digitalWrite(ledPin16, HIGH);           //setting led pin 16 on
        delay(5000);                            //wait for initiali connect with wifi (second command disrupt first command on boot)
        WiFi.begin(ssid, password);             //next try for connecting with wifi
        delay(5000);                            //waiting for avoiding disrupting of connecting
        }}
    }



 
