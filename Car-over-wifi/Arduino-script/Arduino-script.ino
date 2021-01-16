#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#define M 10

char *pwd = "borzone599699";
char *ssid = "Vodafone-30134537";
char buf[M];

WiFiUDP Udp;

void setup() {

	car_setup(); // setup of the car located in car.ino
  	Serial.begin(115200);

	WiFi.begin(ssid, pwd); // start wifi session
	Serial.print("Connecting to WiFi: ");
	Serial.println(ssid);

	while(WiFi.status() != WL_CONNECTED); // wait for the connection to estabilish

	Serial.print("Connected to WiFi with ip: %d");
	Serial.println(WiFi.localIP());
  
  	if(Udp.begin(1025) == 0){ // open udp socket to listen on port 1025
  		Serial.println("No socket available, closing");
  		exit(1);
  	}

}

void loop() {
	if(Udp.parsePacket() != 0){ // if there are datas on the socket
		Udp.read(buf, M); // read it and store it in the buffer
		drive(buf[0]); // send it to the car application to compute
	}
}
