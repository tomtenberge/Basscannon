
void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  //get pin 2 to help me set modes
  pinMode(main_modepin,INPUT_PULLUP);
  pinMode(main_redpin, OUTPUT);
  pinMode(main_greenpin, OUTPUT);
  pinMode(main_bluepin,OUTPUT);
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
  SoftPWMBegin();
  SoftPWMSet(main_redpin,0);
  SoftPWMSet(main_greenpin,0);
  SoftPWMSet(main_bluepin,0);
}
void loop() {
  // check button for false readings
  mode_btn_check();
  //Read out analog pin 7 for audio volumes
  read_audio();
  //audio_serialize();// debug
  mode_select();

  //debug
  //Serial.println(audio_autogain);
  //audio_serialize();
}
