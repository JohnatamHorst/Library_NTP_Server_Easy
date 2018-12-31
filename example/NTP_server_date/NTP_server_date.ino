#include <TimeLib.h> 
#include <ESP8266WiFi.h>
#include <NTP.h>


const char*       ssid          = "wifi_Johnatan";   
const char*       pwd           = "99434266";

void setup() {
  Serial.begin(9600);
  delay(250);
  Serial.println("TimeNTP Example");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pwd);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  NTP ntp("pool.ntp.br",123); 
  unsigned long foo = ntp.getNtpTime(); 
  setTime(foo);

}

void loop() {
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.println(second());
  delay(1000);

}
