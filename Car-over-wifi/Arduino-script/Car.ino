#define ES 3
#define ED 4
#define IN1S 5
#define IN2S 6
#define IN1D 7
#define IN2D 8

void car_setup(){
  pinMode(ES, OUTPUT);
  pinMode(ED, OUTPUT);
  pinMode(IN1S, OUTPUT);
  pinMode(IN2S, OUTPUT);
  pinMode(IN1D, OUTPUT);
  pinMode(IN2D, OUTPUT);
}


void enable(){
	digitalWrite(ES, HIGH);
	digitalWrite(ED, HIGH); 
}


void disable(){
	digitalWrite(ES, LOW);
	digitalWrite(ED, LOW); 
}


void forward(){
	digitalWrite(IN1D, HIGH);
	digitalWrite(IN2D, LOW);
	
	digitalWrite(IN1S, HIGH);
	digitalWrite(IN2S, LOW); 
}


void back(){
	digitalWrite(IN1D, LOW);
	digitalWrite(IN2D, HIGH);
	
	digitalWrite(IN1S, LOW);
	digitalWrite(IN2S, HIGH); 
}


void right(){
	digitalWrite(IN1D, HIGH);
	digitalWrite(IN2D, LOW);
	
	digitalWrite(IN1S, LOW);
	digitalWrite(IN2S, HIGH); 
}


void left(){
	digitalWrite(IN1D, LOW);
	digitalWrite(IN2D, HIGH);
	
	digitalWrite(IN1S, HIGH);
	digitalWrite(IN2S, LOW); 
}


void drive(char command){
	switch(command){
		case 'w':
			forward();
		break;

		case 'a':
			left();
		break;

		case 's':
			back();
		break;

		case 'd':
			right();
		break;

		case 'q':
			disable();
		break;

		case 'e':
			enable();
		break;
	}
}