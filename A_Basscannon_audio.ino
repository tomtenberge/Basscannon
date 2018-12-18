#define AUDIO_BUFFER_SIZE 5
#define AUDIO_AUTOGAIN_COUNTER_MAX 50
#define AUDIO_DELAY_COUNT 5
int audio_average = 0;
int audio_peak = 0;
int audio_delay = 0;
int audio_delay_counter = 0;
int audio_buffer_size = AUDIO_BUFFER_SIZE;
int audio_buffer[AUDIO_BUFFER_SIZE];
int audio_buffer_pointer = 0;
int audio_autogain = 26;
int audio_autogain_counter = 0;
int audio_overpower = 0;

void read_audio()// get audio level and put it in the buffer
{
  int sensorValue = analogRead(A7);
  while (sensorValue < 512)
  {
    sensorValue = 1023 - sensorValue;
  }
  sensorValue = sensorValue - 512;
  //Serial.println(sensorValue);
  audio_buffer[audio_buffer_pointer] = sensorValue;
  audio_buffer_pointer += 1;
  if (audio_buffer_pointer >= AUDIO_BUFFER_SIZE){audio_buffer_pointer = 0;}
  if (sensorValue > audio_autogain)
  {
    audio_autogain = sensorValue;
    audio_autogain_counter = 0;
  }
  else
  {
    audio_autogain_counter++;
    if (audio_autogain_counter > AUDIO_AUTOGAIN_COUNTER_MAX)
    {
      audio_autogain_counter = 0;
      audio_autogain--;
      if (audio_autogain < 26)
      {
        audio_autogain = 26;
      }
    }
  }
  // get audio peak
  int max = 0;
  for (int i=0; i <= (AUDIO_BUFFER_SIZE-1); i++){
    if (audio_buffer[i] > max)
    {
      max = audio_buffer[i];
    }
  }
  max = map(max, 0, audio_autogain, 0, 13);
  audio_peak = max;
  // get delayed peak
  if (audio_peak > audio_delay)
  {
    audio_delay = audio_peak;
    audio_delay_counter = 0;
  }
  else
  {
    audio_delay_counter++;
    if (audio_delay_counter > AUDIO_DELAY_COUNT)
    {
      audio_delay_counter = 0;
      audio_delay--;
    }
  }
  //get audio average
  int total = 0;
  for (int i=0; i <= (AUDIO_BUFFER_SIZE-1); i++){
    total = total + audio_buffer[i];
  }
  total = total / AUDIO_BUFFER_SIZE;
  total = map(total, 0, audio_autogain, 0, 13);
  audio_average = total;
  if (audio_autogain > 510)
  {
    audio_overpower = 1;
    digitalWrite(13,HIGH);
  }
  else
  {
    audio_overpower = 0;
    digitalWrite(13,LOW);
  }
}
void audio_serialize()
{
  Serial.print("(");
  for (int i = 0; i <= 13;i++)
  {
    if ((audio_average == i)&&(audio_peak == i))
    {
      Serial.print("*");
    }
    else if (audio_average == i)
    {
      Serial.print("|");
    }
    else if (audio_delay == i)
    {
      Serial.print("*");
    }
    else
    {
      Serial.print("-");
    }
  }
  if (audio_overpower == 1)
  {
    Serial.print(")*");
  }
  else
  {
    Serial.print(")");
  }
  Serial.print(audio_autogain);
  Serial.println();
}
