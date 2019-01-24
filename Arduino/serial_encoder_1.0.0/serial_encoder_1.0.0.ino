#define Rotary_Encoder_Out_A 1  // CLK pin of Rotary Enocoder
#define Rotary_Encoder_Out_B 2  // DT pin of Rotary Enocoder
#define Rotary_Encoder_Button 3 // Button Press
boolean gerade = true;
int Rotary_Encoder_Present_State;
int Rotary_Encoder_Previous_State;
int RotaryEncoder_Button_Previous

    void
    setup()
{
  pinMode(Rotary_Encoder_Out_A, INPUT);
  pinMode(Rotary_Encoder_Out_B, INPUT);
  pinMode(Rotary_Encoder_Button, INPUT_PULLUP);

  Serial.begin(9600);
  Rotary_Encoder_Previous_State = digitalRead(Rotary_Encoder_Out_A); // Get current state of the Rotary_Encoder_Out_A
}
void loop()
{
  int button = digitalRead(Rotary_Encoder_Button); //auslesen von Button press
  Rotary_Encoder_Present_State = digitalRead(Rotary_Encoder_Out_A);
  if (Rotary_Encoder_Present_State != Rotary_Encoder_Previous_State)
  {
    if (gerade)
    {
      if (digitalRead(Rotary_Encoder_Out_B) != Rotary_Encoder_Present_State)
      {
        Serial.println("+1");
        gerade = false;
      }
      else
      {
        Serial.println("-1");
        gerade = false;
      }
    }
    else
    {
      gerade = true;
    }
  }
  Rotary_Encoder_Previous_State = Rotary_Encoder_Present_State; // Replace previous state of the Rotary_Encoder_Out_A with the current state

  if (button == LOW && Rotary_Encoder_ButtonTimingCheck >= Rotary_Encoder_ButtonDelay)
  {
    Serial.println("Button");
    Rotary_Encoder_ButtonTimingCheck = 0;
  }
  else if (Rotary_Encoder_ButtonTimingCheck < Rotary_Encoder_ButtonDelay)
  {
    Rotary_Encoder_ButtonTimingCheck++;
  }
}
