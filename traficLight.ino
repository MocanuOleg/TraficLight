#define greenLED 0
#define redLED 1
#define yellowLED 2
#define greenButton 7
#define redButton 8

enum States {
  Red = 1,
  RedBlink,
  Yellow,
  Green,
  GreenBlink
};
enum States myState = Red;
enum States prevState;




unsigned long currentTime = 0; //start counting the seconds
unsigned long prevTime = 0;
int redLedDuration = 5000; //5sec
int greenLedDuration = 5000; //5sec
int yellowLedDuration = 3000; //3sec
//int yellowLedState = LOW;
int blinkcount = 0;
int blinkDuration = 250;
bool redLedState = LOW;
bool greenLedState = LOW;

bool greenWasPressed = false;
bool redWasPressed = false;









void setup() {
  // put your setup code here, to run once:
  pinMode(greenLED,OUTPUT);
  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(greenButton,INPUT);
  pinMode(redButton,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:



currentTime = millis();
switch (myState) {
  case Red:
    digitalWrite(redLED,HIGH);
    if(digitalRead(greenButton) == HIGH){
      digitalWrite(redLED,LOW);
      prevTime=currentTime; 
      myState = RedBlink;
    }  
    if (currentTime - prevTime > redLedDuration) { 
      digitalWrite(redLED,LOW);
      prevTime=currentTime;  
      myState = RedBlink;
      
    }
    
  break;
  case RedBlink:
  if (digitalRead(greenButton) == HIGH) {
    digitalWrite(redLED, LOW);  // Turn off red LED
    blinkcount = 0;  // Reset blink counter
    myState = Yellow;  // Switch to Yellow immediately
    greenWasPressed = false;  // Reset green button flag
    break;  // Exit the RedBlink state and go to Yellow
  }

  // Continue blinking logic
  if (currentTime - prevTime > blinkDuration) {
    prevTime = currentTime;
    redLedState = !redLedState;  // Toggle red LED
    digitalWrite(redLED, redLedState);

    if (redLedState == LOW) {
      blinkcount++;
    }
  }

  // After 3 blinks, switch to Yellow
  if (blinkcount > 2) {
    digitalWrite(redLED, LOW);
    blinkcount = 0;
    if (greenWasPressed) {
      myState = Yellow;  // Switch to Yellow after blinking completes
      greenWasPressed = false;  // Reset the button press flag
    } else {
      myState = Yellow;  // Switch to Yellow (default behavior)
    }
    prevState = RedBlink;
  }
  break;
  case Yellow:

    digitalWrite(yellowLED,HIGH);

    if(digitalRead(greenButton) == HIGH)
      greenWasPressed = true;
    if(digitalRead(redButton) == HIGH)
      redWasPressed = true;



    if (currentTime - prevTime > yellowLedDuration) {

      digitalWrite(yellowLED,LOW);
      prevTime=currentTime;
      
      if(greenWasPressed){
        prevTime=currentTime;
        myState = Green;
        greenWasPressed =false;

      }
      else if(redWasPressed){
        prevTime=currentTime;
        myState = Red;
        redWasPressed =false;
      }
      else{
      
      
      

      myState = ((prevState == RedBlink) ? Green : Red);
      }
    }
    


  
  
    break;
  case Green:
    digitalWrite(greenLED,HIGH);
    if(digitalRead(redButton) == HIGH){
        digitalWrite(greenLED,LOW);
        prevTime=currentTime; 
        myState = GreenBlink;
    }  


     
    if (currentTime - prevTime > greenLedDuration) {      
      digitalWrite(greenLED,LOW);
      prevTime=currentTime;  
      myState = GreenBlink;
      
    }
  
    break;
  case GreenBlink:

   if (digitalRead(redButton) == HIGH) {
    digitalWrite(greenLED, LOW);  // Turn off green LED
    blinkcount = 0;  // Reset blink counter
    myState = Yellow;  // Switch to Yellow immediately
    redWasPressed = false;  // Reset red button flag
    break;  // Exit the GreenBlink state and go to Yellow
  }

  // Continue blinking logic
  if (currentTime - prevTime > blinkDuration) {
    prevTime = currentTime;
    greenLedState = !greenLedState;  // Toggle green LED
    digitalWrite(greenLED, greenLedState);

    if (greenLedState == LOW) {
      blinkcount++;
    }
  }

  // After 3 blinks, switch to Yellow
  if (blinkcount > 2) {
    digitalWrite(greenLED, LOW);
    blinkcount = 0;
    if (redWasPressed) {
      myState = Yellow;  // Switch to Yellow after blinking completes
      redWasPressed = false;  // Reset the button press flag
    } else {
      myState = Yellow;  // Switch to Yellow (default behavior)
    }
    prevState = GreenBlink;
  }
  break;

}
}




