#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

//Access credentials

const char* ssid = "neel";
const char* pwd = "neesa1468";
const char* host = "http://192.168.2.7";
String get_host = "http://192.168.2.7";
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
delay(20);
WiFi.begin(ssid,pwd);

// starting the server
server.begin();

Serial.println("Connecting");


while(WiFi.status() != WL_CONNECTED)
{
  delay(500);
  
  Serial.print(".");


}
Serial.println();

Serial.print("Connected, IP address: ");
Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:
  get_device_status("led1");

}

void get_device_status(String device_name)
{

WiFiClient client = server.available();
HTTPClient http;
String url = get_host+"/IOT/iot_light.php?device_name="+ device_name;
http.begin(client,url);

int httpCode = http.GET();
String payload = http.getString();
Serial.print(" payload is : ");
Serial.println(payload);

}
