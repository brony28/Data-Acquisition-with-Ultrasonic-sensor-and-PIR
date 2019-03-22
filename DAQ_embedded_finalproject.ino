
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int clk=0;
int i;
int trigPin=A0; //Sensor Trip pin connected to Arduino pin A0
int echoPin=A1;  //Sensor Echo pin connected to Arduino pin A1
int myCounter=0;  //declare your variable myCounter and set to 0
int servoControlPin=6; //Servo control line is connected to pin 6
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in inches
float speedOfSound=776.5; //
void setup() {
 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(inputPin, INPUT);     // declare sensor as input
pinMode(LED_BUILTIN, OUTPUT); 
Serial.begin(9600);
  // put your setup code here, to run once:
}
void loop() {
  val = digitalRead(inputPin);  // read input value
 
  if (val == HIGH) // check if the input is HIGH
  
  {       
     i++;
    digitalWrite(LED_BUILTIN, HIGH);  // turn LED ON
    if (pirState == LOW)
    {
      
     
    
      // we have just turned on
      Serial.println(&quot;Motion detected!&quot;);
      // We only want to print on the output change, not state

      pirState = HIGH;
  
clk=millis()/1000;
    }
    
Serial.print(i);
Serial.print(&quot;\t&quot;);
    
  } else {
    digitalWrite(LED_BUILTIN, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned off
      Serial.println(&quot;Motion ended!&quot;);
      // We only want to print on the output change, not state
      pirState = LOW;
//     delay(5000);
  
    }
  }

digitalWrite(trigPin, LOW); //Set trigger pin low
  delayMicroseconds(2000); //Let signal settle
  digitalWrite(trigPin, HIGH); //Set trigPin high
  delayMicroseconds(15); //Delay in high state
  digitalWrite(trigPin, LOW); //ping has now been sent
  delayMicroseconds(10); //Delay in high state
  
  pingTime = pulseIn(echoPin, HIGH);  //pingTime is presented in microceconds
  pingTime=pingTime/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in
a second)
  pingTime=pingTime/3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
  targetDistance= speedOfSound * pingTime;  //This will be in miles, since speed of sound was miles per
hour
  targetDistance=targetDistance/2; //Remember ping travels to target and back from target, so you must
divide by 2 for actual target distance.
  targetDistance= targetDistance*63360;    //Convert miles to inches by multipling by 63360 (inches per
mile)
  
 
  delay(250); //pause to let things settle
  Serial.println(targetDistance);
   // put your main code here, to run repeatedly:
}
