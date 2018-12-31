#### Autor:

Nome: Johnatam Renan Horst

Data: 30/12/2018

Email: johnatam.horst@hotmail.com

gitHub: JohnatamHorst

#### Descrisão:

Biblioteca que obtém data/hora de um servidor externo, via opção do usuário, instancia internamente o protocolo udp para comunicação com o mesmo e realiza o tratamento lógico da informação enviada pelo servidor NTP, retornando os segundos desde 01/01/1970. É necessário estar conectado com a internet para a utilização desta biblioteca

#### Funcionalidade:

No momento que é estanciado é possível escolher o Servidor NTP preferido assim como possível utilizar o  default (Server = pool.ntp.br, Porta de Acesso = 123, Time Zone =  -2), caso o mesmo não for informado no Construtor.

#### Funções:

1. NTP();

   ​	Utiliza valores default para obter data e hora.

   ​	servidor = "pool.ntp.br"

   ​	serverPort = 123

   ​	timeZone = -2  Para Horário Brasileiro | ""-3" deve ser utilizado para horário de Verão Brasileiro 

2. NTP(String serverLink, unsigned int serverPort);

   ​	Utiliza somente o valor de timeZone default(-2), serverLink e Port especificados via Construtor

3. NTP(String serverLink, unsigned int serverPort, signed int timeZone);

   ​	O Construtor especifica todos os parâmetros

4. NTP(signed int timeZone);

   ​	É especificado somente a timeZone, demais são utilizado valores default	

5. getNtpTime();

   ​	função retorna os segundos desde 01/01/1970, retorna dados do tipo unsigned Long ou time_t



   ​	Para passar os valores para a biblioteca Time, deve ser utilizada a função setTime(unsigned long)




