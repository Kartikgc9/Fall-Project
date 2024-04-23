//constants
Servo motorFL;                   
Servo motorFR;
Servo motorBL;
Servo motorBR;
Servo mount;
float inches;
float duration;
const int servoPin = 9;
const int pingPin = 7;


//setup
void setup(){
  Serial.begin(9600);
  motorFL.attach(O0);
  motorFR.attach(O1);
  motorBL.attach(O2);
  motorBR.attach(O3);
  mount.attach(servoPin);
}

//loop
void loop(){
  //detecting object
  pinMode(5, OUTPUT);          // Set pin to OUTPUT
  digitalWrite(5, LOW);        // Ensure pin is low
  delayMicroseconds(2);
  digitalWrite(5, HIGH);       // Start ranging
  delayMicroseconds(5);              //   with 5 microsecond burst
  digitalWrite(5, LOW);        // End ranging
  pinMode(8, INPUT);           // Set pin to INPUT
  duration = pulseIn(8, HIGH); // Read echo pulse
  inches = duration / 74 / 2;   
	
  //if encounters objects 
  if(inches < 2){
    motorFL.write(90);
  	motorFR.write(90);
  	motorBL.write(90);
  	motorBR.write(90);
  	delay(200);
  	
    motorFL.write(180);
  	motorFR.write(180);
  	motorBL.write(0);
  	motorBR.write(0);
  	delay(2000);
  	
    motorFL.write(180);
  	motorFR.write(180);
  	motorBL.write(180);
  	motorBR.write(180);
  	delay(1000);
  	
  	motorFL.write(0);
  	motorFR.write(0);
  	motorBL.write(180);
  	motorBR.write(180);
  	delay(1000);
  	return; 
  }
  //keeps going
  else if (inches >= 2){
  	motorFL.write(180);
  	motorFR.write(180);
  	motorBL.write(180);
  	motorBR.write(180);
  }
}