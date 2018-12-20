void mode_01()
{
  uint32_t color_fill = Green;
  uint32_t color_delay = Red;
  uint32_t color_peak = Blue;
  for (int i = 0; i <= 13;i++)
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
    for (int i = 0; i <= 13;i++){
    neo_setled(0,i,Red);  
    }
  }
  neo_show();
}
