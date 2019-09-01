void mode_00()
{
  neo_set_intensity(0.05);
  uint32_t color_1 = Blue;
  uint32_t color_2 = Black;
  neo_setled(99,0,color_2);
  neo_setled(0,0,color_1);
  neo_show();
}
int mode_01_count = 0;
int mode_01_mode = 0;
// modes for 01
// 0 = off
// 1 = on
#define MODE_01_ON 3
#define MODE_01_OFF 50
void mode_01()
{
  neo_set_intensity(1.0);
  uint32_t color_1 = Black;
  uint32_t color_2 = White;
  if (mode_01_mode == 0)
  {
    if (mode_01_count == 0)//start of off state
    {
      neo_setled(99,0,color_1);
    }
    mode_01_count += 1;
    if (mode_01_count > MODE_01_OFF)
    {
      mode_01_mode = 1;
      mode_01_count = 0;
    }
  }
  else if (mode_01_mode == 1)
  {
    if (mode_01_count == 0)//start of on state
    {
      neo_setled(99,0,color_2);
    }
    mode_01_count += 1;
    if (mode_01_count > MODE_01_ON)
    {
      mode_01_mode = 0;
      mode_01_count = 0;
    }
  }
  neo_show();
}
int mode_02_mode = 0;
// 0 = ramp up
// 1 = ramp down
int mode_02_counter1 = 0;
int mode_02_counter2 = 0;
#define MODE_02_delay 5
void mode_02()
{
  neo_set_intensity(0.7);
  uint32_t color_1 = White;
  mode_02_counter2++;
  if (mode_02_counter2 == MODE_02_delay)
  {
    mode_02_counter2 = 0;
    if (mode_02_mode == 0)
    {
      mode_02_counter1++;
      if (mode_02_counter1 > 14)
      {
        mode_02_counter1 = 14;
        mode_02_mode = 1;
      }
    }
    else if (mode_02_mode == 1)
    {
      mode_02_counter1--;
      if (mode_02_counter1 < 0)
      {
        mode_02_counter1 = 0;
        mode_02_mode = 0;
      }
    }
  }
  neo_setled(99,0,Black);
  for (int i = 0; i <= 14;i++)
  {
    if (i == mode_02_counter1)
    {
      neo_setled(0,i,color_1);
    }
  }
  Serial.println(mode_02_counter2);
  neo_show();
}
void mode_03()
{
  neo_set_intensity(0.7);
  uint32_t color_fill = Green;
  uint32_t color_delay = Red;
  uint32_t color_peak = Blue;
  for (int i = 0; i <= 14;i++)
  {
    if ((audio_average >= i))
    {
      neo_setled(0,i,color_fill);
    }
    else if ((audio_average < i)&&(audio_delay >=i))
    {
      neo_setled(0,i,color_delay);
    }
    else
    {
      neo_setled(0,i,Black);
    }
    if (audio_peak == i)
    {
      neo_setled(0,i,color_peak);
    }
  }
  if (audio_overpower == 1)
  {
    for (int i = 0; i <= 14;i++){
    neo_setled(0,i,Red);  
    }
  }
  neo_show();
}
#define mode_04_delay 50
int mode_4_counter = 0;
void mode_04()
{
  mode_4_counter++;
  if (mode_4_counter > mode_04_delay)
  {
    mode_4_counter = 0;
    neo_setled(99,0,Black);
    for (int i = 1; i <= 8;i++)
    {
      int rnd = random(0,15);
      neo_setled(i,rnd,White);
    }
    neo_show();
  }
}
int mode_05_mode = 0;
// 0 = ramp up
// 1 = ramp down
int mode_05_counter1 = 0;
int mode_05_counter2 = 0;
#define MODE_05_delay 5
void mode_05()
{
  neo_set_intensity(0.7);
  uint32_t color_1 = Yellow2;
  mode_05_counter2++;
  if (mode_05_counter2 == MODE_05_delay)
  {
    mode_05_counter2 = 0;
    if (mode_05_mode == 0)
    {
      mode_05_counter1++;
      if (mode_05_counter1 > 14)
      {
        mode_05_counter1 = 14;
        mode_05_mode = 1;
      }
    }
    else if (mode_05_mode == 1)
    {
      mode_05_counter1--;
      if (mode_05_counter1 < 0)
      {
        mode_05_counter1 = 0;
        mode_05_mode = 0;
      }
    }
  }
  neo_setled(99,0,Black);
  for (int i = 0; i <= 14;i++)
  {
    if (i == mode_05_counter1)
    {
      int ii = (14+(0-i));
      neo_setled(1,i,color_1);
      neo_setled(2,ii,color_1);
      neo_setled(3,i,color_1);
      neo_setled(4,ii,color_1);
      neo_setled(5,i,color_1);
      neo_setled(6,ii,color_1);
      neo_setled(7,i,color_1);
      neo_setled(8,ii,color_1);
    }
  }
  neo_show();
}
int mode_06_mode = 0;
// 0 = ramp up
// 1 = ramp down
int mode_06_counter1 = 0;
int mode_06_counter2 = 0;
#define MODE_06_delay 5
void mode_06()
{
  neo_set_intensity(0.7);
  uint32_t color_1 = Red;
  mode_06_counter2++;
  if (mode_06_counter2 == MODE_06_delay)
  {
    mode_06_counter2 = 0;
    if (mode_06_mode == 0)
    {
      mode_06_counter1++;
      if (mode_06_counter1 > 14)
      {
        mode_06_counter1 = 14;
        mode_06_mode = 1;
      }
    }
    else if (mode_06_mode == 1)
    {
      mode_06_counter1--;
      if (mode_06_counter1 < 0)
      {
        mode_06_counter1 = 0;
        mode_06_mode = 0;
      }
    }
  }
  neo_setled(99,0,Black);
  for (int i = 0; i <= 14;i++)
  {
    if (i == mode_06_counter1)
    {
      int ii = (14+(0-i));
      neo_setled(1,i,color_1);
      neo_setled(2,ii,color_1);
      neo_setled(3,i,color_1);
      neo_setled(4,ii,color_1);
      neo_setled(5,i,color_1);
      neo_setled(6,ii,color_1);
      neo_setled(7,i,color_1);
      neo_setled(8,ii,color_1);
    }
  }
  neo_show();
}
int mode_07_mode = 0;
// 0 = ramp up
// 1 = ramp down
int mode_07_counter1 = 0;
int mode_07_counter2 = 0;
#define MODE_07_delay 5
void mode_07()
{
  neo_set_intensity(0.7);
  uint32_t color_1 = Green;
  mode_07_counter2++;
  if (mode_07_counter2 == MODE_07_delay)
  {
    mode_07_counter2 = 0;
    if (mode_07_mode == 0)
    {
      mode_07_counter1++;
      if (mode_07_counter1 > 14)
      {
        mode_07_counter1 = 14;
        mode_07_mode = 1;
      }
    }
    else if (mode_07_mode == 1)
    {
      mode_07_counter1--;
      if (mode_07_counter1 < 0)
      {
        mode_07_counter1 = 0;
        mode_07_mode = 0;
      }
    }
  }
  neo_setled(99,0,Black);
  for (int i = 0; i <= 14;i++)
  {
    if (i == mode_07_counter1)
    {
      int ii = (14+(0-i));
      neo_setled(1,i,color_1);
      neo_setled(2,ii,color_1);
      neo_setled(3,i,color_1);
      neo_setled(4,ii,color_1);
      neo_setled(5,i,color_1);
      neo_setled(6,ii,color_1);
      neo_setled(7,i,color_1);
      neo_setled(8,ii,color_1);
    }
  }
  neo_show();
}
int mode_08_mode = 0;
// 0 = ramp up
// 1 = ramp down
int mode_08_counter1 = 0;
int mode_08_counter2 = 0;
#define MODE_08_delay 5
void mode_08()
{
  neo_set_intensity(0.7);
  uint32_t color_1 = Blue;
  mode_08_counter2++;
  if (mode_08_counter2 == MODE_08_delay)
  {
    mode_08_counter2 = 0;
    if (mode_08_mode == 0)
    {
      mode_08_counter1++;
      if (mode_08_counter1 > 14)
      {
        mode_08_counter1 = 14;
        mode_08_mode = 1;
      }
    }
    else if (mode_08_mode == 1)
    {
      mode_08_counter1--;
      if (mode_08_counter1 < 0)
      {
        mode_08_counter1 = 0;
        mode_08_mode = 0;
      }
    }
  }
  neo_setled(99,0,Black);
  for (int i = 0; i <= 14;i++)
  {
    if (i == mode_08_counter1)
    {
      int ii = (14+(0-i));
      neo_setled(1,i,color_1);
      neo_setled(2,ii,color_1);
      neo_setled(3,i,color_1);
      neo_setled(4,ii,color_1);
      neo_setled(5,i,color_1);
      neo_setled(6,ii,color_1);
      neo_setled(7,i,color_1);
      neo_setled(8,ii,color_1);
    }
  }
  neo_show();
}
void mode_09()
{
  neo_set_intensity(0.7);
  for (int i = 0; i <= 14;i++)
  {
    if ((audio_bass >= i))
    {
      neo_setled(0,i,Blue);
    }
    else
    {
      neo_setled(0,i,Black);
    }
  }
  Serial.println("poing - " + (String)audio_bass);
  neo_show();
}
void mode_10()
{
  
}
void mode_11()
{
  
}
void mode_12()
{
  
}
