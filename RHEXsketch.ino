/*Github repository of open-source RHEX: https://github.com/RapiciousAndrey/RHEX 

  If you have any questions send me email: rapiciousandrey@gmail.com
  

  I used "Amperka" motor shield, it can be byed only in Russia, 
  so you can use other motor shield.

  Pin connections:
  0(RX) - Bluetooth TX leg
  1(TX) - Bluetooth RX leg
  5v    - Bluetooth 5v leg.
  GND   - Bluetooth GND leg
  4     - Direction of right motors 
  5     - Speed of right motor(PWM)1&3 
  6     - Speed of left motor(PWM)1&3 
  7     - Direction of left motors 1&3
  
 

  
*/
char str; 
//this variables value will be recieved from bluetooh 

void setup() {
// Open serial port  
  Serial.begin(9600);

//Setting pinmode
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT); 
}

void loop() {

   if(Serial.available()){
       str = Serial.read();

       switch (str){
          case '1':
           digitalWrite(4,HIGH);
           digitalWrite(7,HIGH);
           analogWrite(5,255);
           analogWrite(6,255);
           break;
          case '2':
           digitalWrite(4,LOW);
           digitalWrite(7,LOW);
           analogWrite(5,255);
           analogWrite(6,255);
           break;
          case '3':
           digitalWrite(4,HIGH);
           digitalWrite(7,LOW);
           analogWrite(5,255);
           analogWrite(6,255);
           break;
          case '4':
           digitalWrite(4,LOW);
           digitalWrite(7,HIGH);
           analogWrite(5,255);
           analogWrite(6,255);   
           break;     
       }     
   }
   else{
      digitalWrite(4,HIGH);
      digitalWrite(7,HIGH);
      analogWrite(5,0);
      analogWrite(6,0);
           
   }
}
