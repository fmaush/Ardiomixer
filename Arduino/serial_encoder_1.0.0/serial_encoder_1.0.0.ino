//define RotaryEncoderPins

#define Rotary_Encoder_Out_A 2
#define Rotary_Encoder_Out_B 3
#define Rotary_Encoder_Button 4

//define FaderPins

#define Fader1_Mute_Button 9
#define Fader1_Mute_Button_LED 9
#define Fader1_Lock_Button 9
#define Fader1_Lock_Button_LED 9
#define Fader1_Solo_Button 9
#define Fader1_Solo_Button_LED 9
#define Fader1_Fader 9

#define Fader2_Mute_Button 9
#define Fader2_Mute_Button_LED 9
#define Fader2_Lock_Button 9
#define Fader2_Lock_Button_LED 9
#define Fader2_Solo_Button 9
#define Fader2_Solo_Button_LED 9
#define Fader2_Fader 9

#define Fader3_Mute_Button 9
#define Fader3_Mute_Button_LED 9
#define Fader3_Lock_Button 9
#define Fader3_Lock_Button_LED 9
#define Fader3_Solo_Button 9
#define Fader3_Solo_Button_LED 9
#define Fader3_Fader 9

#define Fader4_Mute_Button 9
#define Fader4_Mute_Button_LED 9
#define Fader4_Lock_Button 9
#define Fader4_Lock_Button_LED 9
#define Fader4_Solo_Button 9
#define Fader4_Solo_Button_LED 9
#define Fader4_Fader 9

#define MastervolumeMuteButton 9
#define MasterVolume_Mute_Button 9

#define MasterVolume_Mute_Button_LED 9
#define MasterVolume_Fader 9

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
  pinMode(MasterVolume_Mute_Button, INPUT_PULLUP);
  pinMode(MasterVolume_Mute_Button_LED, OUTPUT);
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
  Refrences to the DataStream Outputed by the Arduino

Rotary_Encoder;(1|-1)  Rotary_Encoder_Button;1
//RotaryEncoder -1 back +1 forward ; 1=on
Fader1_Mute_Button;1 Fader1_Lock_Button;1 Fader1_Solo_Button;1  Fader1_Fader;(0-100)
//Button 1=on//Fader: 0 =lowest 100= highest
Fader2_Mute_Button;1  Fader2_Lock_Button;1  Fader2_Solo_Button;1  Fader2_Fader;(0-100)
//*
Fader3_Mute_Button;1 Fader3_Lock_Button;1  Fader3_Solo_Button(0,1) Fader3_Fader;(0-100)
//*
Fader4_Mute_Button;1  Fader4_Lock_Button;1  Fader4_Solo_Button;1  Fader4_Fader;(0-100)
//*
MasterVolume_Mute_Button;1    MasterVolume_Fader;(0-100)
//*

*/

  //Updating variables
  Rotary_Encoder_Present = digitalRead(Rotary_Encoder_Out_A);
  Rotary_Encoder_Button_Present = digitalRead(Rotary_Encoder_Button);

  Fader1_Mute_Button_Present = digitalRead(Fader1_Mute_Button);
  Fader1_Lock_Button_Present = digitalRead(Fader1_Lock_Button);
  Fader1_Solo_Button_Present = digitalRead(Fader1_Solo_Button);

  Fader2_Mute_Button_Present = digitalRead(Fader2_Mute_Button);
  Fader2_Lock_Button_Present = digitalRead(Fader2_Lock_Button);
  Fader2_Solo_Button_Present = digitalRead(Fader2_Solo_Button);

  Fader3_Mute_Button_Present = digitalRead(Fader3_Mute_Button);
  Fader3_Lock_Button_Present = digitalRead(Fader3_Lock_Button);
  Fader3_Solo_Button_Present = digitalRead(Fader3_Solo_Button);

  Fader4_Mute_Button_Present = digitalRead(Fader4_Mute_Button);
  Fader4_Lock_Button_Present = digitalRead(Fader4_Lock_Button);
  Fader4_Solo_Button_Present = digitalRead(Fader4_Solo_Button);

  MasterVolume_Mute_Button_Present = digitalRead(MasterVolume_Mute_Button);

  //RotaryEncoder
  if (Rotary_Encoder_Present != Rotary_Encoder_Present)
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

  //Rotary_Encoder_Button
  if (Rotary_Encoder_Button_Previous != Rotary_Encoder_Button_Present && Rotary_Encoder_Button_Present == 1)
  {
    Serial.println("Rotary_Encoder_Button;1");
  }
  //Fader1_Mute_Button

  if (Fader1_Mute_Button_Previous != Fader1_Mute_Button_Present && Fader1_Mute_Button_Present == 1)
  {
    Serial.println("Fader1_Mute_Button;1");
  }
  //Fader1_Lock_Button

  if (Fader1_Lock_Button_Previous != Fader1_Lock_Button_Present && Fader1_Lock_Button_Present == 1)
  {
    Serial.println("Fader1_Lock_Button;1");
  }
  //Fader1_Solo_Button

  if (Fader1_Solo_Button_Previous != Fader1_Solo_Button_Present && Fader1_Solo_Button_Present == 1)
  {
    Serial.println("Fader1_Solo_Button;1");
  }
  //Fader2_Mute_Button

  if (Fader2_Mute_Button_Previous != Fader2_Mute_Button_Present && Fader2_Mute_Button_Present == 1)
  {
    Serial.println("Fader2_Mute_Button;1");
  }
  //Fader2_Lock_Button

  if (Fader2_Lock_Button_Previous != Fader2_Lock_Button_Present && Fader2_Lock_Button_Present == 1)
  {
    Serial.println("Fader2_Lock_Button;1");
  }
  //Fader2_Solo_Button

  if (Fader2_Solo_Button_Previous != Fader2_Solo_Button_Present && Fader2_Solo_Button_Present == 1)
  {
    Serial.println("Fader2_Solo_Button;1");
  }
  //Fader3_Mute_Button

  if (Fader3_Mute_Button_Previous != Fader3_Mute_Button_Present && Fader3_Mute_Button_Present == 1)
  {
    Serial.println("Fader3_Mute_Button;1");
  }
  //Fader3_Lock_Button

  if (Fader3_Lock_Button_Previous != Fader3_Lock_Button_Present && Fader3_Lock_Button_Present == 1)
  {
    Serial.println("Fader3_Lock_Button;1");
  }
  //Fader3_Solo_Button

  if (Fader3_Solo_Button_Previous != Fader3_Solo_Button_Present && Fader3_Solo_Button_Present == 1)
  {
    Serial.println("Fader3_Solo_Button;1");
  }
  //Fader4_Mute_Button

  if (Fader4_Mute_Button_Previous != Fader4_Mute_Button_Present && Fader4_Mute_Button_Present == 1)
  {
    Serial.println("Fader4_Mute_Button;1");
  }
  //Fader4_Lock_Button

  if (Fader4_Lock_Button_Previous != Fader4_Lock_Button_Present && Fader4_Lock_Button_Present == 1)
  {
    Serial.println("Fader4_Lock_Button;1");
  }
  //Fader4_Solo_Button

  if (Fader4_Solo_Button_Previous != Fader4_Solo_Button_Present && Fader4_Solo_Button_Present == 1)
  {
    Serial.println("Fader4_Solo_Button;1");
  }
  //MasterVolume_Mute_Button
  if (MasterVolume_Mute_Button_Previous != MasterVolume_Mute_Button_Present && MasterVolume_Mute_Button_Present == 1)
  {
    Serial.println("MasterVolume_Mute_Button;1");
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
  if (gerade == true)
  {
    gerade = false;
  }
  else
  {
    gerade = true;
  }
}

//
//NotePad
//