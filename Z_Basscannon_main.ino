
void setup() {
  Serial.begin(115200);
  Serial.println("Starting...");
  //get pin 2 to help me set modes
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),interupting, CHANGE);
  //load up the strips
  neo_strip1.begin();
  neo_strip2.begin();
  neo_strip3.begin();
  neo_strip4.begin();
  neo_strip5.begin();
  neo_strip6.begin();
  neo_strip7.begin();
  neo_strip8.begin();
  neo_show();
}
void loop() {
  // check button for false readings
  mode_btn_check();
  //Read out analog pin 7 for audio volumes
  read_audio();
  //audio_serialize();// debug
  mode_select();
  delay(10);        // delay in between reads for stability

  //debug
  Serial.println(audio_autogain);
}
