
void setup() {
  Serial.begin(115200);
  Serial.println("Starting...");
  //get pin 2 to help me set modes
  pinMode(main_modepin,INPUT_PULLUP);
  randomSeed(analogRead(0));
  attachInterrupt(digitalPinToInterrupt(main_modepin),interupting, CHANGE);
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

  //debug
  Serial.println(audio_autogain);
}
