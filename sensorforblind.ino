
#define pingPin 2        //trig pin of sr04
#define echoPin 3

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(pingPin,OUTPUT); 
   pinMode(echoPin,INPUT);
   pinMode(12,OUTPUT);   //pin12 is used as GND pin  for buzzer since arduino nano has only two GND pins
   pinMode(A3,OUTPUT);   //pin A3 provides the output on buzzer
}

void loop() {
   long duration, cm;
  digitalWrite(12, LOW);   //Buzzer GND is always low


   //send a signal at ping pin at an interval of 0.002 seconds to check for an object
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);    
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);

  
   duration = pulseIn(echoPin, HIGH);  //check time using pulseIn function
   
   cm = microsecondsToCentimeters(duration);   //functin call to find distance
   
  /* Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
   
   for debugging
   */

   
   if (cm<30&&cm>20) 
                         {analogWrite(A3,255); 
                          delay(1000); 
                          analogWrite(A3,0); 
                          delay(1000); }    //sound buzzer every second if obstacle distance is between 20-30cm. 
  
   
   else if (cm<20&&cm>10) {analogWrite(A3,255); 
                           delay(500); 
                           analogWrite(A3,0); 
                           delay(500); }   //sound buzzer every 0.5 seconds if obstacle distance is between 10-20cm. 
  
   
   else if (cm<10&&cm>0)  {analogWrite(A3,255); 
                           delay(100); 
                           analogWrite(A3,0);
                           delay(100); }    //sound buzzer every 0.1 seconds if obstacle distance is between 0-10cm. 
  
   
   else                     analogWrite(A3,0); //do not sound the buzzer
}



//function to return distance in cm from microseconds
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
