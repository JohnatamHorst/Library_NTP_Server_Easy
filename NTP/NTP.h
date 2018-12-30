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
  void initNtpServer(String server, unsigned int port);
  time_t getNtpTime();
  void sendNTPpacket();

  private:
    // Variaveis e Funcoes privadas
  byte _packetBuffer[48];     
  const int _timeZone = -2;
  String _ServerLink = "pool.ntp.br";
  WiFiUDP _udp;
};
#endif
