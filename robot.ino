#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

int a0 = 1;
int a1 = 2;
int a2 = 6;
int a3 = 7;
const char*  ssid ="GO";
const char*  password ="12345678";

WiFiUDP Udp;
unsigned int localUdpPort =4210;
char incomingPacket[255]; //buffer for incoming packets
char replyPacket[] ="forword";
char replyPacket1[] ="backword";
char replyPacket2[] ="left";
char replyPacket3[] ="right";

void forword()
{ 
  digitalWrite(a0,HIGH);
  digitalWrite(a1,LOW);
  digitalWrite(a2,HIGH);
  digitalWrite(a3,LOW);
  delay(20);

    
}
void backword()
{
  digitalWrite(a0,LOW);
  digitalWrite(a1,HIGH);
  digitalWrite(a2,LOW);
  digitalWrite(a3,HIGH);
  delay(20);

}
void left()
{
  digitalWrite(a0,HIGH);
  digitalWrite(a1,LOW);
  digitalWrite(a2,LOW);
  digitalWrite(a3,HIGH);
  delay(30);

}
void right()
{
  digitalWrite(a0,LOW);
  digitalWrite(a1,HIGH);
  digitalWrite(a2,HIGH);
  digitalWrite(a3,LOW);
  delay(30);
}
void Stop()
{
  digitalWrite(a0,LOW);
  digitalWrite(a1,LOW);
  digitalWrite(a2,LOW);
  digitalWrite(a3,LOW);
  delay(30);
}
void setup()
{
  Serial.begin(115200);
  //analogReadResolution(10);
  Serial.println();
  pinMode(a0,OUTPUT); 
  pinMode(a1,OUTPUT); 
  pinMode(a2,OUTPUT); 
  pinMode(a3,OUTPUT); 
  
  Serial.printf("Connecting to %s", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay (500);
  Serial.print(".");}
  
  Serial.println("connected");
  
  Udp.begin(localUdpPort);
  Serial.printf("now listening at IP %s,UDP port %d\n",WiFi.localIP().toString().c_str(),localUdpPort);
  delay(20);
}
void loop()
{
  int packetSize= Udp.parsePacket ();
  if(packetSize)
  {
    Serial.printf("Received %d bytes from %s, port %d\n",packetSize,Udp.remoteIP().toString().c_str(),Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    Serial.printf("UDP packet contents: %s\n", incomingPacket);
    Serial.println(packetSize);
    if (len == 2)
    forword();  
    else if(len == 3)
    backword();    
    else if(len ==4)
    left();
    else if (len == 5)
    right();
    else
    Stop();   
  }
}

  
  
