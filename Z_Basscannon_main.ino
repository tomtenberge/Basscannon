int modebtn_islow = false;
unsigned long modebtn_millis = 0;
void setup() {
  Serial.begin(115200);
  Serial.println("Starting...");
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),interupting, CHANGE);
}
void loop() {
  if (digitalRead(2) == HIGH && modebtn_islow == true) 
  {
    modebtn_islow = false;
    Serial.println("btn-cancel ");
  }
  //Read out analog pin 7 for audio volumes
  read_audio();
  //audio_serialize();// debug
  delay(10);        // delay in between reads for stability
}
void interupting()
{
  unsigned long tmpmillis = millis();
  int modebtn_curval = digitalRead(2);
  if (modebtn_curval == LOW)
  {
    if (modebtn_islow == false)
    {
      modebtn_islow = true;
      modebtn_millis = tmpmillis;
    }
    else
    {
      // wanna do something when the button skips skips skips a beat? (https://www.youtube.com/watch?v=j5dFe-WKuPs)
    }
  }
  if ((modebtn_curval == HIGH && modebtn_islow == true))
  {
    if (tmpmillis > (modebtn_millis + 6000))//very long push (reset)
    {
      modebtn_islow = false;
      
    }
    else if (tmpmillis > (modebtn_millis + 500))//Long press
    {
      modebtn_islow = false;
    }
    else if (tmpmillis > (modebtn_millis + 50))//Short press
    {
      modebtn_islow = false;
    }
  }
}
