
/* Simple usage of Virtual Buttons and Virtual led widgets
   Created by Nava 4/2018
   Using NodeMCU board - where the leds are connected to GPIO 2 & 16.
   V1, V2 are assigned to led widget
   V3, V4 are assigned to buttons widget
*/
 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//
char auth[] = "your auth code here";
char ssid[] = "your wifi ssid";
char pass[] = "you wifi passphrase";

// 
  WidgetLED led1(V1);
  WidgetLED led2(V2);
  

  
void setup() {
  pinMode(2, OUTPUT);
  pinMode(16, OUTPUT);
  Blynk.begin(auth, ssid, pass);

}

BLYNK_WRITE(V3) {
  int A = param.asInt();
  if (A) {digitalWrite(2, !A); led1.on();} 
    else {digitalWrite(2, !A); led1.off();} 
}
BLYNK_WRITE(V4) {
  int A = param.asInt();
  if (A) {digitalWrite(16, !A); led2.on();}
    else {digitalWrite(16, !A); led2.off();}  
}
void loop() {
  Blynk.run();
}
