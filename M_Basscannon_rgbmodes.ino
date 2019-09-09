#include "SoftPWM.h"
int mode_RGB_count = 0;
int mode_RGB_mode = 0;
int mode_RGB_mode2 = 0;
int mode_RGB_R = 0;
int mode_RGB_G = 0;
int mode_RGB_B = 0;
void mode_rgb_00()
{
  SoftPWMSetPercent(main_redpin,0);
  SoftPWMSetPercent(main_greenpin,00);
  SoftPWMSetPercent(main_bluepin,00);
}
void mode_rgb_01()
{
  mode_RGB_count += 1;
  if (mode_RGB_mode == true)
  {
    if (mode_RGB_count > 100)
    {
      mode_RGB_count = 0;
      mode_RGB_mode = false;
    }
    SoftPWMSetPercent(main_redpin,100);
    SoftPWMSetPercent(main_greenpin,100);
    SoftPWMSetPercent(main_bluepin,100);
  }
  else
  {
    if (mode_RGB_count > 100)
    {
      mode_RGB_count = 0;
      mode_RGB_mode = true;
    }
    SoftPWMSetPercent(main_redpin,0);
    SoftPWMSetPercent(main_greenpin,0);
    SoftPWMSetPercent(main_bluepin,0);
  }
}

void mode_rgb_02()
{
  mode_RGB_count += 1;
  if (mode_RGB_mode == true)
  {
    if (mode_RGB_count > 150)
    {
      mode_RGB_count = 100;
      mode_RGB_mode = false;
    }
    SoftPWMSetPercent(main_redpin,100);
    SoftPWMSetPercent(main_greenpin,100);
    SoftPWMSetPercent(main_bluepin,100);
  }
  else
  {
    if (mode_RGB_count > 150)
    {
      mode_RGB_count = 100;
      mode_RGB_mode = true;
    }
    SoftPWMSetPercent(main_redpin,0);
    SoftPWMSetPercent(main_greenpin,0);
    SoftPWMSetPercent(main_bluepin,0);
  }
}
void mode_rgb_03()
{
  mode_RGB_count += 1;
  if (mode_RGB_count > 25)
  {
    mode_RGB_count = 0;
    mode_RGB_mode += 1;
    if (mode_RGB_mode > 2)
    {
      mode_RGB_mode = 0;
    }
      SoftPWMSetPercent(main_redpin,0);
      SoftPWMSetPercent(main_greenpin,0);
      SoftPWMSetPercent(main_bluepin,0);
    switch(mode_RGB_mode){
      case 0:
      SoftPWMSetPercent(main_redpin,100);
      break;
      case 1:
      SoftPWMSetPercent(main_greenpin,100);
      break;
      case 2:
      SoftPWMSetPercent(main_bluepin,100);
      break;
    }
  }
}
void mode_rgb_04()
{
  //this is 400
  mode_RGB_mode += 1;
  if (mode_RGB_mode > 1)
  {
    mode_RGB_mode = 0;
    mode_RGB_mode2 += 1;
    if (mode_RGB_mode2 < 100)
    {
      SoftPWMSetPercent(main_bluepin,(100 - mode_RGB_mode2));
      SoftPWMSetPercent(main_redpin,mode_RGB_mode2);
    }
    else if (mode_RGB_mode2 < 200)
    {
      SoftPWMSetPercent(main_redpin,(100 - (mode_RGB_mode2 - 100)));
      SoftPWMSetPercent(main_greenpin,(mode_RGB_mode2 - 100));
    }
    else if (mode_RGB_mode2 < 300)
    {
      SoftPWMSetPercent(main_greenpin,(100 - (mode_RGB_mode2 - 200)));
      SoftPWMSetPercent(main_bluepin,(mode_RGB_mode2 - 200));
    }
    else
    {
      mode_RGB_mode2 = 0;
    }
  }
}
void mode_rgb_05()
{
  //this is 400
  mode_RGB_mode += 1;
  if (mode_RGB_mode > 1)
  {
    mode_RGB_mode = 0;
    mode_RGB_mode2 += 2;
    if (mode_RGB_mode2 < 100)
    {
      SoftPWMSetPercent(main_bluepin,(100 - mode_RGB_mode2));
      SoftPWMSetPercent(main_redpin,mode_RGB_mode2);
    }
    else if (mode_RGB_mode2 < 200)
    {
      SoftPWMSetPercent(main_redpin,(100 - (mode_RGB_mode2 - 100)));
      SoftPWMSetPercent(main_greenpin,(mode_RGB_mode2 - 100));
    }
    else if (mode_RGB_mode2 < 300)
    {
      SoftPWMSetPercent(main_greenpin,(100 - (mode_RGB_mode2 - 200)));
      SoftPWMSetPercent(main_bluepin,(mode_RGB_mode2 - 200));
    }
    else
    {
      mode_RGB_mode2 = 0;
    }
  }
}
void mode_rgb_06()
{
  int total = 0;
  total = map(audio_current, 0, audio_autogain, 0, 4);
  if (total == 2)
  {
    mode_RGB_R +=1;
    if (mode_RGB_R > 100){mode_RGB_R = 100;}
  }
  else
  {
    mode_RGB_R -=1;
    if (mode_RGB_R < 0){mode_RGB_R = 0;}
  }
  if (total == 3)
  {
    mode_RGB_G +=1;
    if (mode_RGB_G > 100){mode_RGB_G = 100;}
  }
  else
  {
    mode_RGB_G -=1;
    if (mode_RGB_G < 0){mode_RGB_G = 0;}
  }
  if (total == 4)
  {
    mode_RGB_B +=1;
    if (mode_RGB_B > 100){mode_RGB_B = 100;}
  }
  else
  {
    mode_RGB_B -=1;
    if (mode_RGB_B < 0){mode_RGB_B = 0;}
  }
  SoftPWMSetPercent(main_redpin,mode_RGB_R);
  SoftPWMSetPercent(main_greenpin,mode_RGB_G);
  SoftPWMSetPercent(main_bluepin,mode_RGB_B);
}
void mode_rgb_07()
{
}
void mode_rgb_08()
{
}
void mode_rgb_09()
{
}
void mode_rgb_10()
{
}
void mode_rgb_11()
{
}
