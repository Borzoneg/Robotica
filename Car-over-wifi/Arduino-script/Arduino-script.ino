#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define M 10

char *pwd = "borzone599699";
char *ssid = "Vodafone-30134537";
char buf[M];
IPAddress staticIP(192,168,1,40);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WiFiUDP Udp;

void setup() {

	car_setup(); // setup of the car located in car.ino
	Serial.begin(115200);
	Serial.println();

	WiFi.begin("Vodafone-30134537", "borzone599699"); // start wifi session
	WiFi.config(staticIP, gateway, subnet); // set the esp to be on a static ip

	Serial.print("Connecting to WiFi: ");
	Serial.println(ssid);

	while (WiFi.status() != WL_CONNECTED){ // wait for the connection to estabilish
		delay(500);
		Serial.print(".");
	}

	Serial.print("Connected to WiFi with ip: ");
	Serial.println(WiFi.localIP());

		if(Udp.begin(1025) == 0){ // open udp socket to listen on port 1025
			Serial.println("No socket available, closing");
			exit(1);
		}
	Serial.print("UDP socket opened on port 1025");

}

int incomingByte;

void loop() {
	 if(Udp.parsePacket() != 0){ // if there are datas on the socket
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
	 	Udp.read(buf, M); // read it and store it in the buffer
	 	Serial.println(buf[0]);
	 	drive(buf[0]); // send it to the car application to compute
	 }
}
