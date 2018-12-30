/********************************************************
 
 */


#include <NTP.h>



void NTP::initNtpServer(String server, unsigned int port){
  WiFiUDP udp;
  udp.begin(port);    
  _udp = udp;
  _ServerLink = server;
  Serial.print("Server: ");
  Serial.println(server);
}
  
time_t NTP::getNtpTime(){
  while (_udp.parsePacket() > 0) ; 
  Serial.println("Transmit NTP Request");
  sendNTPpacket();
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
    int size = _udp.parsePacket();
    if (size >= 48) {
      Serial.println("Receive NTP Response");
      _udp.read(_packetBuffer, 48);  
      unsigned long secsSince1900;
      secsSince1900 =  (unsigned long)_packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)_packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)_packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)_packetBuffer[43];
      return secsSince1900 - 2208988800UL + _timeZone * 60;//;
    }
  }
  Serial.println("No NTP Response :-(");
  return 0;
}
void NTP::sendNTPpacket(){
  memset(_packetBuffer, 0, 48);
  _packetBuffer[0] = 0b11100011;   
  _packetBuffer[1] = 0;    
  _packetBuffer[2] = 6;     
  _packetBuffer[3] = 0xEC;  
  _packetBuffer[12]  = 49;
  _packetBuffer[13]  = 0x4E;
  _packetBuffer[14]  = 49;
  _packetBuffer[15]  = 52;                 
  _udp.beginPacket("pool.ntp.br", 123); 
  _udp.write(_packetBuffer, 48);
  _udp.endPacket();
}
