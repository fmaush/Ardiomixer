#define encoderOutA 2 // CLK pin of Rotary Enocoder
#define encoderOutB 3 // DT pin of Rotary Enocoder
#define encoderOutC 4 // Button Press
boolean gerade = true;
int presentState;
int previousState;
long penis2 = 500;
long langerpenis = 20000;


void setup() {
  pinMode (encoderOutA, INPUT);
  pinMode (encoderOutB, INPUT);
  pinMode (encoderOutC, INPUT_PULLUP);


  Serial.begin (9600);
  previousState = digitalRead(encoderOutA);   // Get current state of the encoderOutA
}
void loop() {
  int penis = digitalRead(encoderOutC);
  presentState = digitalRead(encoderOutA);
  if (presentState != previousState)
  {
    if (gerade) {
      if (digitalRead(encoderOutB) != presentState)
      {
        Serial.println("+1");
        gerade = false ;
      }
      else {
        Serial.println("-1");
        gerade = false;

      }
    } else {
      gerade = true;
    }
  }
  previousState = presentState; // Replace previous state of the encoderOutA with the current state


  if (penis == LOW && penis2 >= langerpenis)  {
    Serial.println("Button");
    penis2 = 0;


  }
  else if (penis2 < langerpenis) {
    penis2 ++;
  }

}
