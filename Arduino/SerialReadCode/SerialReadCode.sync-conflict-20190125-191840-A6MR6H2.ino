#define INPUT_SIZE 4

// (FaderNummer;Welche LED des Faders; An oder Aus)

String SerialInputVar;
int Fader1_Mute_Button_LED;
int LED_Signal;
char Dividor = ":";
int LED_Id;
int LED_Status;

void setup()
{
  Serial.begin(9600);
  //pinMode(LED_BUILTIN, OUTPUT);
  delay(5000);
  Serial.println("Serial Start");
  LED_Signal = 0;
}

void loop()
{
  if (Serial.available() > 0)
  {
    char input[INPUT_SIZE];
    byte size = Serial.readBytes(input, INPUT_SIZE);
    char *pch;
    printf("Splitting string \" % s\" into tokens:\n", input);
    pch = strtok(input, ";");
    while (pch != NULL)
    {
      *pch = 0;
      LED_Id = atoi(pch);
      ++pch;
      LED_Status = atoi(pch);
    }
    Serial.println(LED_Id);

    Serial.println(LED_Status);
  }
}
