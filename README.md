# SmartShoes-for-blind-Persons-Using-Arduino
This paper presents an idea about dealing the problems faced by visually impaired individuals through assistive device in form of shoes. According to the WORLD HEALTH ORGANIZATION (WHO) survey in 2014 there is estimated 285 millions of people are visually impairment in which 37 millions of people are BLIND across the Globe over 15 millions of people are from INDIA. Where INDIA contributes to 21% of total blind population that’s why most of the blind people dependent on other people for their activities. Hence, we are introducing a assistive shoe for blind people which will help them in their needed activities. The shoes will detect the nearby objects or obstacles and simultaneously send a message to the receiver in audio/vibration form. So it helps the visually impaired person to acquire the extra knowledge about the obstacles around them without any help or any guidance. It will make them more independent because there should be an “EYE” for an “I”.


UNIVERSITY OF MUMBAI







PROJECT REPORT ON 

Smart Shoes for blind Person
 SUBMMITTED BY 
Mr. Shekade Dnyaneshwar Vitthal 

UNDER THE GUIDANCE OF 
Ms. Rashmi Pote

TO

UNIVERSITY OF MUMBAI 
IN PARTIAL FULLFILMENT OF 
F.Y.M.sc.(COMPUTER SCIENCE)

SEM-2nd 
ACADEMIC YEAR 2021-2022





UNIVERSITY OF MUMBAI
 
 

CERTIFICATE

This is to certify that “Mr. Shekade Dnyaneshwar Vitthal” Examination Seat No. 69  Student of DEPARTMENT OF COMPUTER SCIENCE, UNIVERSITY OF MUMBAI   has successfully completed the project work entitled “Smart shoes for blind Person” during the academic year 2021-2022. In partial fulfilment of the requirement for the award of Degree in Masters of Computer Science under University of Mumbai.
It is further certified that student completed all required phases of project.


PLACE: VIdhyanagari, Mumbai
DATE: ________



____________                                                                             __________________
PROJECT GUIDE                                                                     Head of DEPARTMENT
     (Ms. Rashmi Pote)                                                                                  (Ms. Jaya Bharti)
    

                                            ______________________
                                          INTERNAL EXAMINAR       

1.	ABSTRACT
This paper presents an idea about dealing the problems faced by visually impaired individuals through assistive device in form of shoes. According to the WORLD HEALTH ORGANIZATION (WHO) survey in 2014 there is estimated 285 millions of people are visually impairment in which 37 millions of people are BLIND across the Globe over 15 millions of people are from INDIA. Where INDIA contributes to 21% of total blind population that’s why most of the blind people dependent on other people for their activities. Hence, we are introducing a assistive shoe for blind people which will help them in their needed activities. The shoes will detect the nearby objects or obstacles and simultaneously send a message to the receiver in audio/vibration form. So it helps the visually impaired person to acquire the extra knowledge about the obstacles around them without any help or any guidance. It will make them more independent because there should be an “EYE” for an “I”.









I.	INTRODUCTION
In India most of the people are facing the problem of visual impairment which are preventing them to become independent. Where in unknown environment it becomes a real challenge for them to loco mote. Where obstacles passing away from the visually impaired person, so that the blind people have to develop their hearing sense or any guide to localize him to the new atmosphere. Where they uses cane, trained dog or other assistive electronics devices for movement. The purpose of the paper is to design a smart assistive shoe for visually impaired people so they get rid of the cane and make them more independent. This will also help them to survive freely in this fast-paced life-now-a day.




II.	LITERATURE SURVEY


Where from the fig. 1 it shows in India there are world 21% blind people present and the counting is 15 million of people across the globe. Where the fig. 1 also shows that there is only 5% people who receives any kind of assistive things they want. So this is the small step to help the needy people. This shoe has an ergonomic design and an embedded electronic system. This system may be classified the cheapest assistive material for blind people.









 
III.	PROPOSED DESIGN
In order to overcome the difficulties in the existing method and to provide the cost effective and user friendly system for blind navigation, the following design is proposed. Fig.1 shows that this project mainl b y consist on four parts namely Ultrasonic sensors, Microcontroller, , Power supply.


Fig. 1 Block diagram of Assistive Device




    



IV.	HARDWARE DESCRIPTION
•	Arduino nano 
 
•	Ultrasonic sensor 
 





•	9v Battery

 

•	Buzzer
 




















•	Shoe And Time to Exicution

 











1.	SOFTWARE USED
Arduino Ide for sensor testing and coding

 









2.	HARDWARE IMPLEMENTATION
To implement, the ultrasonic sensors, Arduino microcontroller and SD card are used. Based on signals, decision is made in Arduino to manage and give timely signals. The input string is from the ultrasonic sensors which generate high frequency sound waves and evaluate the echo which is received back by the sensor. Sensors calculate the time interval between sending the signal and receiving the echo to determine the distance to an object. Ultrasonic sensor can measure distances in centimeters and inches.








 






















3.	FLOWCHART DESIGN
	




V.	CODING



 

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


//function to return distance in cm from microseconds
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2


VI.	CONCLUSION
It has been observed that developed support system- is accurate in detecting the obstacle and alerting the visually impaired person find their way bypassing every obstacle that comes on their way to the destination. The ultrasonic sensor has been fully utilized in order to advance the mobility of the blind and visual impaired people in safe and independent way. This system does not require a huge device to be hold for a long distance, and it also does not require any special training. This system also resolves limitations that are related to the most of the movement problems that may influence the blind people in their environment.






VII.	ADVANTAGES
•	Low design time. 
•	Low production cost.
•	This system is applicable for both the indoor and outdoor environment.
•	 Setting the destination is very easy.
•	It is dynamic system.
•	Less space




VIII.	FUTURE SCOPE

Future work will be focused on enhancing the performance of the system and reducing the load on the user by adding the camera to guide the blind exactly. Images acquired by using web camera and NI-smart cameras helps in identification of objects as well as scans the entire instances for the presence of number of objects in the path of the blind person. It can also detect the material and shape of the object. Matching percentage has to be nearly all the time correct as there no chance for correction for a blind person if it is to be trusted and reliable one. The principles of mono pulse radar can be utilized for determining long range target objects. The other scope may include a new concept of optimum and safe path detection based on neural networks for a blind person.



REFRENCES

[1]. Amjed S. Al-Fahoum, Heba B. Al-Hmoud, and Ausaila A. Al-Fraihat, “A Smart Infrared Microcontroller- Based Blind Guidance System”, Hindawi Transactions on Active and Passive Electronic Components,Vol.3, No.2, pp.1-7, June 2013.
[2]. Harshad Girish Lele, Viten Vilas Lonkar, Varun Vasant Marathe and Mrunmayi Mohan Modak, “Electronic Path Guidance for Visually Impaired People”, The International Journal Of Engineering And Science (IJES), Vol.2, No.4, pp.9-12, April 2013.
[3]. Pooja Sharma, Mrs. Shimi S. L. and Dr. S.Chatterji, “Design of microcontroller based Virtual Eye for the Blind”, International Journal of Scientific Research Engineering & Technology (IJSRET), Vol.3, No.8, pp.1137-1142, November 2014.
[4]. Pooja Sharma, Mrs. Shimi S. L. and Dr. S.Chatterji, “A Review on Obstacle Detection and Vision”, International Journal of Engineering Sciences and Research Technology”, Vol.4, No.1, pp. 1-11, January 2015.
[5]. Naseer Muhammad and Engr.Qazi Waqar Ali, “Design of Intelligent Stick Based on Microcontroller with GPS Using Speech IC”, International Journal of Electrical and Computer Engineering (IJECE) Vol.2, No.6, pp. 781~784 , December 2012.

