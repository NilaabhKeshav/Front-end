#define enA 2
#define in1 52
#define in2 50
#define enB 3
#define in3 30
#define in4 31
#define in5 12
#define in6 13
#define enC 4
#define button 53
#define jx A0
#define jy A1
int xAxis, yAxis;
float motorSpeedA = 0.0;
float motorSpeedB = 0.0;
float motorSpeedC = 0.0;
int buttonValue;
void setup() { 
  pinMode(enA, OUTPUT);//pwm
  pinMode(enB, OUTPUT);//pwm
  pinMode(enC, OUTPUT);//pwm
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(button,INPUT);
  pinMode(jx,INPUT);
  pinMode(jy,INPUT);
  }
void loop() {
  xAxis = analogRead(jx);
  yAxis = analogRead(jy);
  buttonValue=digitalRead(button);
if (yAxis < 470 && xAxis>470 && xAxis<550 && (buttonValue==LOW))//back
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
    motorSpeedA = map(yAxis, 470, 0, 0, 25);
    motorSpeedB = map(yAxis, 470, 0, 0, 25);
    motorSpeedC = map(yAxis, 470, 0, 0, 25);
  }
  else if (yAxis > 550 &&  xAxis>470 && xAxis<550 && buttonValue==LOW) //front
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    motorSpeedA = map(yAxis, 550, 1023, 0, 25);
    motorSpeedB = map(yAxis, 550, 1023, 0, 25);
    motorSpeedC = map(yAxis, 550, 1023, 0, 25);
  }
  
  
  else if (xAxis > 550 &&  yAxis>470 && yAxis<550 && buttonValue==HIGH)//left turn
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 50 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(xAxis, 550,1023, 0, 25);
    motorSpeedB = map(xAxis, 550, 1023, 0, 25);
    motorSpeedC = map(xAxis, 550, 1023, 0, 25);
  }
  else if (xAxis > 550 && yAxis>470 && yAxis<550 && buttonValue==LOW)//right turn
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 50 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(xAxis, 550, 1023, 0, 25);
    motorSpeedB = map(xAxis, 550, 1023, 0, 25);
    motorSpeedC = map(xAxis, 550, 1023, 0, 25);
  }
  /*else if(xAxis>550 && yAxis>550 && buttonValue==LOW)//top right
  { 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    motorSpeedB=map(xAxis,550,1023,0,50);
    motorSpeedC=map(xAxis,550,1023,0,50);
    motorSpeedA=1.732*motorSpeedB;
  }
  
  else if(xAxis>550 && yAxis<470 && buttonValue==LOW)//bottom right
  { 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    motorSpeedB=map(xAxis,550,1023,0,50);
    motorSpeedC=map(xAxis,550,1023,0,50);
    motorSpeedA=1.732*motorSpeedB;
  }

  else if(xAxis<470 && yAxis>550 && buttonValue==LOW)//top left
  { 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    motorSpeedB=map(xAxis,470,0,0,50);
    motorSpeedC=map(xAxis,470,0,0,50);
    motorSpeedA=1.732*motorSpeedB;
  }

  else if(xAxis<470 && yAxis<470 && buttonValue==LOW)//bottom left
  { 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    motorSpeedB=map(xAxis,470,0,0,50);
    motorSpeedC=map(xAxis,470,0,0,50);
    motorSpeedA=1.732*motorSpeedB;   
    //Bottom left 45 angle
  }
*/
  else if(yAxis>550 && xAxis>470 && xAxis<550 && (buttonValue==HIGH))//clockwise rotation
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    motorSpeedA=motorSpeedB=motorSpeedC=25.0;
  }

  
  else if(yAxis<470 && xAxis>470 && xAxis<550 && (buttonValue==HIGH))//anticlockwise rotation
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    motorSpeedA=motorSpeedB=motorSpeedC=25.0;
  }

  else {
    motorSpeedA = 0.0;
    motorSpeedB = 0.0;
    motorSpeedC = 0.0;
  }
  
  
  analogWrite(enA, motorSpeedA);//for speed of motor 1
  analogWrite(enB, motorSpeedB);//for speed of motor 2
  analogWrite(enC, motorSpeedC);//for speed of motor 3
}
