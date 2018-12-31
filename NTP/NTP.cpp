/********************************************************
 AUTOR: JOHNATAM RENAN HORST
 DATA: 31/12/2018
 DESCRISAO: CODIGO CPP DA CLASSE NTP.
 OBSERVAÇÕES:
	UTIILIZADO CODIGO DE LOGICA E EXEMPLO DISPONIBILIZADO PELO CANAL DO YOUTUBEINTERNET
	INTERNET E COSISAS/ ANDRÉ MICHELON
	LINK: https://www.youtube.com/watch?v=9Z-ROKOg5eg
	/ 
 */

#include <NTP.h>


NTP::NTP(){
  WiFiUDP udp;
  udp.begin(_serverPort);    
  _udp = udp;
  if(Serial){
	Serial.print("Server: ");
	Serial.print(_serverLink); 
	Serial.print(" - Port: ");
	Serial.print(_serverPort);
	Serial.print(" - Time Zone: ");
	Serial.println(_timeZone);
  }
}
NTP::NTP(String server, unsigned int port){
  WiFiUDP udp;
  udp.begin(port);    
  _udp = udp;
  _serverPort = port;
  _serverLink = server;
  if(Serial){
	Serial.print("Server: ");
	Serial.print(_serverLink); 
	Serial.print(" - Port: ");
	Serial.print(_serverPort);
	Serial.print(" - Time Zone: ");
	Serial.println(_timeZone);
  }
}
NTP::NTP(String server, unsigned int port, signed int timeZone){
  WiFiUDP udp;
  udp.begin(port);    
  _udp = udp;
  _serverPort = port;
  _serverLink = server;
  _timeZone = timeZone;
  if(Serial){
	Serial.print("Server: ");
	Serial.print(_serverLink); 
	Serial.print(" - Port: ");
	Serial.print(_serverPort);
	Serial.print(" - Time Zone: ");
	Serial.println(_timeZone);
  }
}
NTP::NTP(signed int timeZone){
  WiFiUDP udp;
  udp.begin(_serverPort);    
  _udp = udp;
  _timeZone = timeZone;
  if(Serial){
	Serial.print("Server: ");
	Serial.print(_serverLink); 
	Serial.print(" - Port: ");
	Serial.print(_serverPort);
	Serial.print(" - Time Zone: ");
	Serial.println(_timeZone);
  }
}  
time_t NTP::getNtpTime(){
  while (_udp.parsePacket() > 0) ; 
  if(Serial){
  Serial.println("Transmit NTP Request");
  }
  sendNTPpacket();
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
    int size = _udp.parsePacket();
    if (size >= 48) {
		if(Serial){
			Serial.println("Receive NTP Response");
		}
		_udp.read(_packetBuffer, 48);  
		unsigned long secsSince1900;
		secsSince1900 =  (unsigned long)_packetBuffer[40] << 24;
		secsSince1900 |= (unsigned long)_packetBuffer[41] << 16;
		secsSince1900 |= (unsigned long)_packetBuffer[42] << 8;
		secsSince1900 |= (unsigned long)_packetBuffer[43];
		return secsSince1900 - 2208988800UL + (_timeZone * 3600);//;
	  }
	}
	if(Serial){
		Serial.println("No NTP Response :-(");
	}
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
  _udp.beginPacket(_serverLink.c_str(), _serverPort); 
  _udp.write(_packetBuffer, 48);
  _udp.endPacket();
}

