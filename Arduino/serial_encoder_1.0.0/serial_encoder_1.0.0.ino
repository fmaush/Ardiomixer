
/*
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
*/

//start

//define RotaryEncoderPins

#define Rotary_Encoder_Out_A 2
#define Rotary_Encoder_Out_B 3
#define Rotary_Encoder_Button 4

//define FaderPins

#define Fader1_Mute_Button
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

//define MastervolumeMuteButton Pin
#define MasterVolume_Mute_Button
#define MasterVolume_Mute_Button_LED
#define MasterVolume_Fader

//Rotary Encoder
int Rotary_Encoder_Present_State;
int Rotary_Encoder_Previous_State;

int RotaryEncoder_Button_Previous;
int RotaryEncoder_Button_Present;

//Fader 1
int Fader1_Mute_Button_Previous;
int Fader1_Mute_Button_Present;

int Fader1_Solo_Button_Previous;
int Fader1_Solo_Button_Present;

int Fader1_Lock_Button_Previous;
int Fader1_Lock_Button_Present;

int Fader1_Fader;

//Fader 2
int Fader2_Mute_Button_Previous;
int Fader2_Mute_Button_Present;

int Fader2_Solo_Button_Previous;
int Fader2_Solo_Button_Present;

int Fader2_Lock_Button_Previous;
int Fader2_Lock_Button_Present;

int Fader2_Fader;

//Fader 3
int Fader3_Mute_Button_Previous;
int Fader3_Mute_Button_Present;

int Fader3_Solo_Button_Previous;
int Fader3_Solo_Button_Present;

int Fader3_Lock_Button_Previous;
int Fader3_Lock_Button_Present;

int Fader3_Fader;

//Fader 4
int Fader4_Mute_Button_Previous;
int Fader4_Mute_Button_Present;

int Fader4_Solo_Button_Previous;
int Fader4_Solo_Button_Present;

int Fader4_Lock_Button_Previous;
int Fader4_Lock_Button_Present;

int Fader4_Fader;

//Mastervolume Buttons
int MasterVolume_Mute_Button_Previous;
int MasterVolume_Mute_Button_Present;
int MasterVolume_Fade;

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

  Serial.begin(9600);
  Rotary_Encoder_Present_State = digitalRead(Rotary_Encoder_Out_A);
}
void loop()
{
  /*

Rotary_Encoder(0,1,-1);Rotary_Encoder_Button(0,1);
Fader1_Mute_Button(0,1);Fader1_Lock_Button(0,1);Fader1_Solo_Button(0,1);Fader1_Fader(0-100)
Fader2_Mute_Button(0,1);Fader2_Lock_Button(0,1);Fader2_Solo_Button(0,1);Fader2_Fader(0-100)
Fader3_Mute_Button(0,1);Fader3_Lock_Button(0,1);Fader3_Solo_Button(0,1);Fader3_Fader(0-100)
Fader4_Mute_Button(0,1);Fader4_Lock_Button(0,1);Fader4_Solo_Button(0,1);Fader4_Fader(0-100)
MasterVolume_Button(0,1);MasterVolume_Fader(0-100);

*/
  //RotaryEncoder
  Rotary_Encoder_Present_State = digitalRead(Rotary_Encoder_Out_A);
  if (Rotary_Encoder_Present_State != Rotary_Encoder_Previous_State)
  {
    if (gerade)
    {
      if (digitalRead(Rotary_Encoder_Out_B) != Rotary_Encoder_Present_State)
      {
        Serial.print("1;");
      }
      else
      {
        Serial.print("-1;");
      }
    }
    else
    {
      Serial.print("0;");
    }

    if (gerade == true {
      gerade = false;
        } else{
      gerade = true;
    )
  }
  Rotary_Encoder_Previous_State = Rotary_Encoder_Present_State;
  }
