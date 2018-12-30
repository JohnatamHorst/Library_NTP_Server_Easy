/********************************************************
 
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
  NTP(String serverLink, unsigned int _serverPort);
 // void initNtpServer(String server, unsigned int port);
  time_t getNtpTime();

  private:
    // Variaveis e Funcoes privadas
	
  byte _packetBuffer[48];     
  const int _timeZone = -2;
  String _serverLink = "pool.ntp.br";
  unsigned int _serverPort= 123;
  WiFiUDP _udp;
  bool serialAvailable = false;
  void sendNTPpacket();
};
#endif
