
//start

//define RotaryEncoderPins

#define Rotary_Encoder_Out_A 2
#define Rotary_Encoder_Out_B 3
#define Rotary_Encoder_Button 4

//define FaderPins

/*
#define Fader1_Mute_Button 5
#define Fader1_Mute_Button_LED 
#define Fader1_Lock_Button 
#define Fader1_Lock_Button_LED 
#define Fader1_Solo_Button
#define Fader1_Solo_Button_LED
#define Fader1_Fader

#define Fader2_Mute_Button
#define Fader2_Mute_Button_LED
#define Fader2_Lock_Button
#define Fader2_Lock_Button_LED
#define Fader2_Solo_Button
#define Fader2_Solo_Button_LED
#define Fader2_Fader

#define Fader3_Mute_Button
#define Fader3_Mute_Button_LED
#define Fader3_Lock_Button
#define Fader3_Lock_Button_LED
#define Fader3_Solo_Button
#define Fader3_Solo_Button_LED
#define Fader3_Fader

#define Fader4_Mute_Button
#define Fader4_Mute_Button_LED
#define Fader4_Lock_Button
#define Fader4_Lock_Button_LED
#define Fader4_Solo_Button
#define Fader4_Solo_Button_LED
#define Fader4_Fader
*/

//define MastervolumeMuteButton Pin
#define MasterVolume_Mute_Button 8

//#define MasterVolume_Mute_Button_LED
//#define MasterVolume_Fader

//Rotary Encoder
int Rotary_Encoder_Present;
int Rotary_Encoder_Previous;

int Rotary_Encoder_Button_Previous;
int Rotary_Encoder_Button_Present;

//Fader 1
int Fader1_Mute_Button_Previous;
int Fader1_Mute_Button_Present;

int Fader1_Solo_Button_Previous;
int Fader1_Solo_Button_Present;

int Fader1_Lock_Button_Previous;
int Fader1_Lock_Button_Present;

int Fader1_Fader_Present;
int Fader1_Fader_Previous;

//Fader 2
int Fader2_Mute_Button_Previous;
int Fader2_Mute_Button_Present;

int Fader2_Solo_Button_Previous;
int Fader2_Solo_Button_Present;

int Fader2_Lock_Button_Previous;
int Fader2_Lock_Button_Present;

int Fader2_Fader_Present;
int Fader2_Fader_Previous;

//Fader 3
int Fader3_Mute_Button_Previous;
int Fader3_Mute_Button_Present;

int Fader3_Solo_Button_Previous;
int Fader3_Solo_Button_Present;

int Fader3_Lock_Button_Previous;
int Fader3_Lock_Button_Present;

int Fader3_Fader_Present;
int Fader3_Fader_Previous;

//Fader 4
int Fader4_Mute_Button_Previous;
int Fader4_Mute_Button_Present;

int Fader4_Solo_Button_Previous;
int Fader4_Solo_Button_Present;

int Fader4_Lock_Button_Previous;
int Fader4_Lock_Button_Present;

int Fader4_Fader_Present;
int Fader4_Fader_Previous;

//Mastervolume Buttons
int MasterVolume_Mute_Button_Previous;
int MasterVolume_Mute_Button_Present;
int MasterVolume_Fader_Present;
int MasterVolume_Fader_Previous;

//Variabels
boolean gerade = true;

void setup()
{
  //RotaryEncoder PinMode
  pinMode(Rotary_Encoder_Out_A, INPUT);
  pinMode(Rotary_Encoder_Out_B, INPUT);
  pinMode(Rotary_Encoder_Button, INPUT_PULLUP);

  //Fader1 PinMode
  pinMode(Fader1_Mute_Button, INPUT_PULLUP);
  pinMode(Fader1_Mute_Button_LED, OUTPUT);
  pinMode(Fader1_Lock_Button, INPUT_PULLUP);
  pinMode(Fader1_Lock_Button_LED, OUTPUT);
  pinMode(Fader1_Solo_Button, INPUT_PULLUP);
  pinMode(Fader1_Solo_Button_LED, OUTPUT);
  pinMode(Fader1_Fader, INPUT);

  //Fader2 PinMode
  pinMode(Fader2_Mute_Button, INPUT_PULLUP);
  pinMode(Fader2_Mute_Button_LED, OUTPUT);
  pinMode(Fader2_Lock_Button, INPUT_PULLUP);
  pinMode(Fader2_Lock_Button_LED, OUTPUT);
  pinMode(Fader2_Solo_Button, INPUT_PULLUP);
  pinMode(Fader2_Solo_Button_LED, OUTPUT);
  pinMode(Fader2_Fader, INPUT);

  //Fader3 PinMode
  pinMode(Fader3_Mute_Button, INPUT_PULLUP);
  pinMode(Fader3_Mute_Button_LED, OUTPUT);
  pinMode(Fader3_Lock_Button, INPUT_PULLUP);
  pinMode(Fader3_Lock_Button_LED, OUTPUT);
  pinMode(Fader3_Solo_Button, INPUT_PULLUP);
  pinMode(Fader3_Solo_Button_LED, OUTPUT);
  pinMode(Fader3_Fader, INPUT);

  //Fader4 PinMode
  pinMode(Fader4_Mute_Button, INPUT_PULLUP);
  pinMode(Fader4_Mute_Button_LED, OUTPUT);
  pinMode(Fader4_Lock_Button, INPUT_PULLUP);
  pinMode(Fader4_Lock_Button_LED, OUTPUT);
  pinMode(Fader4_Solo_Button, INPUT_PULLUP);
  pinMode(Fader4_Solo_Button_LED, OUTPUT);
  pinMode(Fader4_Fader, INPUT);

  //Mastervolume
  pinMode(MasterVolume_Button, INPUT_PULLUP);
  pinMode(MasterVolume_Button_LED, OUTPUT);
  pinMode(MasterVolume_Fader, INPUT);

  //Setting previous states
  Rotary_Encoder_Previous = digitalRead(Rotary_Encoder_Out_A);
  Rotary_Encoder_Button_Previous = digitalRead(Rotary_Encoder_Button);
  Fader1_Mute_Button_Previous = digitalRead(Fader1_Mute_Button);
  Fader1_Lock_Button_Previous = digitalRead(Fader1_Lock_Button);
  Fader1_Solo_Button_Previous = digitalRead(Fader1_Solo_Button);
  Fader2_Mute_Button_Previous = digitalRead(Fader2_Mute_Button);
  Fader2_Lock_Button_Previous = digitalRead(Fader2_Lock_Button);
  Fader2_Solo_Button_Previous = digitalRead(Fader2_Solo_Button);
  Fader3_Mute_Button_Previous = digitalRead(Fader3_Mute_Button);
  Fader3_Lock_Button_Previous = digitalRead(Fader3_Lock_Button);
  Fader3_Solo_Button_Previous = digitalRead(Fader3_Solo_Button);
  Fader4_Mute_Button_Previous = digitalRead(Fader4_Mute_Button);
  Fader4_Lock_Button_Previous = digitalRead(Fader4_Lock_Button);
  Fader4_Solo_Button_Previous = digitalRead(Fader4_Solo_Button);
  MasterVolume_Mute_Button_Previous = digitalRead(MasterVolume_Mute_Button);

  Serial.begin(9600);
}
void loop()
{
  /* The Dataflow
RoRefrences to the DataStream Outputed by the Arduino

Rotary_Encoder;(1|-1)  Rotary_Encoder_Button;1
//RotaryEncoder -1 back +1 forward ; 1=on
Fader1_Mute_Button;1 Fader1_Lock_Button;1 Fader1_Solo_Button;1  Fader1_Fader;(0-100)
//Button 1=on//Fader: 0 =lowest 100= highest
Fader2_Mute_Button;1  Fader2_Lock_Button;1  Fader2_Solo_Button;1  Fader2_Fader;(0-100)
//*
Fader3_Mute_Button;1 Fader3_Lock_Button;1	Fader3_Solo_Button(0,1)	Fader3_Fader;(0-100)
//*
Fader4_Mute_Button;1	Fader4_Lock_Button;1	Fader4_Solo_Button;1	Fader4_Fader;(0-100)
//*
MasterVolume_Mute_Button;1		MasterVolume_Fader;(0-100)
//*

*/

  //RotaryEncoder
  Rotary_Encoder_Present = digitalRead(Rotary_Encoder_Out_A);
  if (Rotary_Encoder_Present != Rotary_Encoder_Previous)
  {
    if (gerade)
    {
      if (digitalRead(Rotary_Encoder_Out_B) != Rotary_Encoder_Present)
      {
        Serial.println("Rotary_Encoder;1");
      }
      else
      {
        Serial.println("Rotary_Encoder;-1");
      }
    }
  }

  //Fader1_Mute_Button
  if (Fader1_Mute_Button_Previous != Fader1_Mute_Button_Present && Fader1_Mute_Button_Present == 1)
  {
    Serial.println("Fader1_Mute_Button;1")
  }

  //Fader1_Lock_Button
  if (Fader1_Lock_Button_Previous != Fader1_Lock_Button_Present && Fader1_Lock_Button_Present == 1)
  {
    Serial.println("Fader1_Lock_Button;1")
  }

  //
  //Reset of variables
  //

  //Changing previous state to current state
  Rotary_Encoder_Previous = Rotary_Encoder_Present;
  Rotary_Encoder_Button_Previous = Rotary_Encoder_Button_Present;
  Fader1_Mute_Button_Previous = Fader1_Mute_Button_Present;
  Fader1_Lock_Button_Previous = Fader1_Lock_Button_Present;
  Fader1_Solo_Button_Previous = Fader1_Solo_Button_Present;
  Fader2_Mute_Button_Previous = Fader2_Mute_Button_Present;
  Fader2_Lock_Button_Previous = Fader2_Lock_Button_Present;
  Fader2_Solo_Button_Previous = Fader2_Solo_Button_Present;
  Fader3_Mute_Button_Previous = Fader3_Mute_Button_Present;
  Fader3_Lock_Button_Previous = Fader3_Lock_Button_Present;
  Fader3_Solo_Button_Previous = Fader3_Solo_Button_Present;
  Fader4_Mute_Button_Previous = Fader4_Mute_Button_Present;
  Fader4_Lock_Button_Previous = Fader4_Lock_Button_Present;
  Fader4_Solo_Button_Previous = Fader4_Solo_Button_Present;
  MasterVolume_Mute_Button_Previous = MasterVolume_Mute_Button_Present;

  //Reseting gerade to show if we are on an even or uneven cycle
   if (gerade == true {
    gerade = false;
        } else{
    gerade = true;
    )
}

   //
   //NotePad
   //
   /*
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;


  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}

//------------------------------------

class Button
{
private:
  byte low;
  byte high;
  int pinnumber;
  String name;

public:
  Button();
  boolean isLow();
  boolean isHigh();
  int get_pinnumber;
  String get_name;
};

Button(int pinnumber, String name)
{
  this->low = 0;
  this->high = 1;
  this->pinnumber = pinnumber;
  this->name = name;
}

boolean isLow(int pinnumber)
{
  return (digitalRead(pinumber) = low);
}

boolean isHigh(int pinnumber)
{
  return (digitalRead(pinumber) = high);
}

int get_pinnumber()
{
  return pinnumber;
}

//-------------------------------------------------------
[Starting] Verify sketch - GitHub\Ardiomixer\Arduino\serial_encoder_1.0.0\serial_encoder_1.0.0.ino
[Warning] Output path is not specified. Unable to reuse previously compiled files. Verify could be slow. See README.
Loading configuration...
Initializing packages...
Preparing boards...
Verifying...
d:\Desktop\Arduiomixer\GitHub\Ardiomixer\Arduino\serial_encoder_1.0.0\serial_encoder_1.0.0.ino: In function 'void setup()':

serial_encoder_1.0.0:128:11: error: 'Fader1_Mute_Button' was not declared in this scope

   pinMode(Fader1_Mute_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:129:11: error: 'Fader1_Mute_Button_LED' was not declared in this scope

   pinMode(Fader1_Mute_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:130:11: error: 'Fader1_Lock_Button' was not declared in this scope

   pinMode(Fader1_Lock_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:131:11: error: 'Fader1_Lock_Button_LED' was not declared in this scope

   pinMode(Fader1_Lock_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:132:11: error: 'Fader1_Solo_Button' was not declared in this scope

   pinMode(Fader1_Solo_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:133:11: error: 'Fader1_Solo_Button_LED' was not declared in this scope

   pinMode(Fader1_Solo_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:134:11: error: 'Fader1_Fader' was not declared in this scope

   pinMode(Fader1_Fader, INPUT);

           ^

serial_encoder_1.0.0:137:11: error: 'Fader2_Mute_Button' was not declared in this scope

   pinMode(Fader2_Mute_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:138:11: error: 'Fader2_Mute_Button_LED' was not declared in this scope

   pinMode(Fader2_Mute_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:139:11: error: 'Fader2_Lock_Button' was not declared in this scope

   pinMode(Fader2_Lock_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:140:11: error: 'Fader2_Lock_Button_LED' was not declared in this scope

   pinMode(Fader2_Lock_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:141:11: error: 'Fader2_Solo_Button' was not declared in this scope

   pinMode(Fader2_Solo_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:142:11: error: 'Fader2_Solo_Button_LED' was not declared in this scope

   pinMode(Fader2_Solo_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:143:11: error: 'Fader2_Fader' was not declared in this scope

   pinMode(Fader2_Fader, INPUT);

           ^

serial_encoder_1.0.0:146:11: error: 'Fader3_Mute_Button' was not declared in this scope

   pinMode(Fader3_Mute_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:147:11: error: 'Fader3_Mute_Button_LED' was not declared in this scope

   pinMode(Fader3_Mute_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:148:11: error: 'Fader3_Lock_Button' was not declared in this scope

   pinMode(Fader3_Lock_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:149:11: error: 'Fader3_Lock_Button_LED' was not declared in this scope

   pinMode(Fader3_Lock_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:150:11: error: 'Fader3_Solo_Button' was not declared in this scope

   pinMode(Fader3_Solo_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:151:11: error: 'Fader3_Solo_Button_LED' was not declared in this scope

   pinMode(Fader3_Solo_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:152:11: error: 'Fader3_Fader' was not declared in this scope

   pinMode(Fader3_Fader, INPUT);

           ^

serial_encoder_1.0.0:155:11: error: 'Fader4_Mute_Button' was not declared in this scope

   pinMode(Fader4_Mute_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:156:11: error: 'Fader4_Mute_Button_LED' was not declared in this scope

   pinMode(Fader4_Mute_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:157:11: error: 'Fader4_Lock_Button' was not declared in this scope

   pinMode(Fader4_Lock_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:158:11: error: 'Fader4_Lock_Button_LED' was not declared in this scope

   pinMode(Fader4_Lock_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:159:11: error: 'Fader4_Solo_Button' was not declared in this scope

   pinMode(Fader4_Solo_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:160:11: error: 'Fader4_Solo_Button_LED' was not declared in this scope

   pinMode(Fader4_Solo_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:161:11: error: 'Fader4_Fader' was not declared in this scope

   pinMode(Fader4_Fader, INPUT);

           ^

serial_encoder_1.0.0:164:11: error: 'MasterVolume_Button' was not declared in this scope

   pinMode(MasterVolume_Button, INPUT_PULLUP);

           ^

serial_encoder_1.0.0:165:11: error: 'MasterVolume_Button_LED' was not declared in this scope

   pinMode(MasterVolume_Button_LED, OUTPUT);

           ^

serial_encoder_1.0.0:166:11: error: 'MasterVolume_Fader' was not declared in this scope

   pinMode(MasterVolume_Fader, INPUT);

           ^

d:\Desktop\Arduiomixer\GitHub\Ardiomixer\Arduino\serial_encoder_1.0.0\serial_encoder_1.0.0.ino: In function 'void loop()':

serial_encoder_1.0.0:228:3: error: expected ';' before '}' token

   }

   ^

serial_encoder_1.0.0:234:3: error: expected ';' before '}' token

   }

   ^

serial_encoder_1.0.0:258:23: error: expected ')' before '{' token

    if (gerade == true {

                       ^

serial_encoder_1.0.0:263:1: error: expected statement at end of input

 }

 ^

serial_encoder_1.0.0:263:1: error: expected '}' at end of input

exit status 1
[Error] Exit with code=1

*/