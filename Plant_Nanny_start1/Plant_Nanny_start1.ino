int photocellPin = 1;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the analog resistor divider
int sensorPin = 0;
int potPin = 3;
int i=0;
float val = 0;
float val2=0;
float val3=0;
int buttonState=0;
int lastButtonState=0;
int buttonPushCounter=0;
int tilt=0;
int sub=0;
void setup(void) {
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  pinMode(10, INPUT);
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);   
  
}
 
void loop(void) {
   buttonState = digitalRead(10);
     if (buttonState != lastButtonState){
        if (buttonState == HIGH){
          buttonPushCounter++;
          
          }
    }
    lastButtonState = buttonState;

if (buttonPushCounter % 2 == 0){
      
     Serial.println("On");

  
  if(sub==0){
   tilt= digitalRead(2);}
   else if(sub==1){
    tilt = 1;
   }
  

    Serial.print("Start = "); Serial.println(tilt);
    Serial.print("Sub = "); Serial.println(sub);
       
  
  photocellReading = analogRead(photocellPin);  
 
  
  // We'll have a few threshholds, qualitatively determined
  if (photocellReading < 10) {
    
    digitalWrite(13,HIGH);
    
  } else if (photocellReading < 200) {
    digitalWrite(13,HIGH);
    digitalWrite(2,LOW);
   
  } else if (photocellReading < 500) {
    digitalWrite(13,LOW);
    digitalWrite(2,LOW);
    int reading = analogRead(sensorPin);
   float voltage = reading * 5.0;
    voltage /= 1024.0; 
    float temperatureC = (voltage - 0.5)*10  ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
 Serial.print(temperatureC); Serial.println(" degrees C"); 
 delay(2000);
 
  } else if (photocellReading < 800) {
    digitalWrite(13,LOW);
    digitalWrite(2,LOW);
    int reading = analogRead(sensorPin); 
    float voltage = reading * 5.0;
    voltage /= 1024.0;  
    float temperatureC = (voltage - 0.5) * 10 ;  //converting from 10 mv per degree wit 500 mV offset
                                              //to degrees ((voltage - 500mV) times 100)
 Serial.print(temperatureC); Serial.println(" degrees C");
 delay(2000);
  } else {
    Serial.println(" - Very bright");
    delay(2000);
  }
  
  
  if (tilt==HIGH)
    {
     Serial.println("Plant is fine");
     delay(1000);
    }else if (tilt==LOW){
     
     val = analogRead(potPin);
     Serial.println("Try moving the plant to the left or right to get more light");
      if(val==val2){
        Serial.println("Plant is wilting");
        Serial.println("Try moving the plant");
        delay(2000);
      }else if (val!=val3){
        Serial.println("Lets hope for the best");
        tilt=1;
        sub=1;
        delay(2000);
        }
    }
    delay(1000);
    val2= analogRead(potPin);
    val3=val;}else {
      Serial.println("Off");sub=0;
      }
      
    
}
