#define MODE_MAX 8
int mode_current = 0;
int mode_old = 0;
//variables for the button to work
int modebtn_islow = false;
unsigned long modebtn_millis = 0;
//just a little extra check for floating button statuses
void mode_select()
{
  switch(mode_current){
    case 0:
    mode_00();
    break;
    case 1:
    mode_01();
    break;
    case 2:
    mode_02();
    break;
    case 3:
    mode_03();
    break;
    case 4:
    mode_04();
    break;
    case 5:
    mode_05();
    break;
    case 6:
    mode_06();
    break;
    case 7:
    mode_07();
    break;
    case 8:
    mode_08();
    break;
    case 9:
    mode_09();
    break;
    case 10:
    mode_10();
    break;
    case 11:
    mode_11();
    break;
    case 12:
    mode_12();
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
      Serial.println("buttonfail");
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
      mode_current += 1;
      if (mode_current > MODE_MAX)
      {
        mode_current = 0;
      }
      modebtn_islow = false;
      Serial.print("short press, mode = ");
      Serial.println(mode_current);
    }
  }
}
