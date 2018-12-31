/********************************************************
 AUTOR: JOHNATAM RENAN HORST
 DATA: 31/12/2018
 DESCRISAO: HEADER DA CLASSE NTP.
 OBSERVAÇÕES:
	UTIILIZADO CODIGO DE LOGICA E EXEMPLO DISPONIBILIZADO PELO CANAL DO YOUTUBEINTERNET
	INTERNET E COSISAS/ ANDRÉ MICHELON
	LINK: https://www.youtube.com/watch?v=9Z-ROKOg5eg
	/ 
 */

#include <Arduino.h>
#include <WiFiUDP.h>

#ifndef NTP_h
  // Evita que a Biblioteca seja incluida mais de uma vez
  #define NTP_h

// Definicao da Classe Counter
class NTP {
  public:
    // Metodos e Propriedades publicos
  NTP();
  NTP(String _serverLink, unsigned int _serverPort);
  NTP(String _serverLink, unsigned int _serverPort, signed int _timeZone);  
  NTP(signed int _timeZone);
  time_t getNtpTime();

  private:
    // Variaveis e Funcoes privadas	
  byte _packetBuffer[48];     
  signed int _timeZone = -2;				//default
  String _serverLink = "pool.ntp.br";		//default
  unsigned int _serverPort= 123;			//default
  WiFiUDP _udp;	
  bool serialAvailable = false;
  void sendNTPpacket();
};
#endif
