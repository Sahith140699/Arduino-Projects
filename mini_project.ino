#include "PubSubClient.h"
#include "ESP8266WiFi.h"

const char* ssid = "Virus";
const char* password = "password123";
char*  topic = "channels/731181/publish/O5FFLQ3NPVVD530A";
char* server = "mqtt.thingspeak.com";
char* clientID = "sahith12";
char mqttPass[] = "M6LXOF3ZRLMDMLDD";                // Change to your MQTT API Key from Account > MyProfile.
long ChannelID = 731181;

WiFiClient wifiClient;
PubSubClient client(server , 1883 , wifiClient);

//const int s0 = D4;  
//const int s1 = D5;  
//const int s2 = D6;  
//const int s3 = D7;  
//const int out = D8;   
// 
//int red = 0;  
//int green = 0;  
//int blue = 0;  

//void callback(char* topic, byte* payload, unsigned int length)
//{
//
//}

void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

 pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
 
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);
  }
  Serial.print("");
  Serial.println("WiFi connected");
  Serial.println("IP address");
  Serial.print(WiFi.localIP());

  String clientName = "miniProject";
  Serial.print("Connecting to");
  Serial.print(server);
  Serial.print("as");
  Serial.println(clientName);

  if(client.connect(clientID,(char*)clientName.c_str(),mqttPass))
  {
    Serial.println("Connected to MQTT broker");
    Serial.print("Topic is: ");
    Serial.println(topic);

    if(client.publish(topic, "-1"))
    {
      Serial.println("Publish ok");
    }
    else
    {
      Serial.println("Published failed");
    }
  }
  else
  {
    Serial.println("MQTT connect failed");
    Serial.println("Will reset and try again...");
    abort();
  }
}

void loop()
{
  static int counter = 0;
//  digitalWrite(s2, LOW);  
//  digitalWrite(s3, LOW);  
//  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
//  digitalWrite(s3, HIGH);   
//  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
//  digitalWrite(s2, HIGH);   
//  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  String payload = "field1=";   //dataString+="&field" + String( index+1 ) + "="+String( dataArray [ index ] );
  payload += String(red);
  //payload +="&status=MQTTPUBLISH";

  if(client.connected())
  {
    Serial.print("Sending payload");
    Serial.println(payload);

    if(client.publish(topic,(char*)payload.c_str()))
    {
      Serial.println("Publish OK");
    }
    else
    {
      Serial.println("Publish Failed");
    }
  }
  ++counter;
  delay(20000);
  
}
