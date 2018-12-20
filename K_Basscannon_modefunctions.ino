#define MODE_MAX 1
int mode_current = 1;
int mode_old = 1;
//variables for the button to work
int modebtn_islow = false;
unsigned long modebtn_millis = 0;
//just a little extra check for floating button statuses
void mode_select()
{
  switch(mode_current){
    case 1:
    mode_01();
    break;
  }
}
void mode_btn_check()
{
  if (digitalRead(2) == HIGH && modebtn_islow == true) 
  {
    modebtn_islow = false;
    Serial.println("btn-cancel ");
  }
}
// interupt for the mode button :) for your convenience
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
