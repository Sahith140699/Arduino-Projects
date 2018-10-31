#include<ESP8266WiFi.h>
#include<WiFiClient.h>
const char* ssid = "Virus";
const char* pwd = "password123";
const char* host = "api.thingspeak.com";
const char* url = "/apps/thinghttp/send_request?api_key=GHIG7YY8OWHFT4C9";
void setup()
{
  Serial.begin(115200);
  Serial.println();
  

 // Serial.println("Connecting to %s ",ssid);
  WiFi.begin(ssid,pwd);

  Serial.print("Connecting.....");
  while (WiFi.status()!= WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP Address");
  Serial.println(WiFi.localIP());

}

void loop() 
{
  WiFiClient client;

  Serial.printf("\n[Connecting to %s....",host);
  if(client.connect("www.wikipedia.org",80))
  {
    Serial.println("connected");
    Serial.println("[Sending the request]");
    client.print(String("GET")+"HTTP/1.1\r\n" +
                   "Host: " + "www.wikipedia.org" + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                 );
    Serial.println("[Response]");
    while (client.connected())
    {
      if(client.available())
      {
        String line = client.readStringUntil('\n');
        Serial.println(line);
        
      }
    }
    client.stop();
    Serial.println("[Disconnected]");
  }
  else
  {
    Serial.println("Connection Failed");
    client.stop();
  }
  delay(5000);
}
