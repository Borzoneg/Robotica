
void setup() {

	Serial.begin(115200);
	car_setup(); // setup of the car located in car.ino
  wifi_setup(); // setup the wifi module with WiFi-module.ino sketch
  udp_setup(); // setup udp connection
	
}

int incomingByte;

void loop() {
	drive(udp_read_char());
}
