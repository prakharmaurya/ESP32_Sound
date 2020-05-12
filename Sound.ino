void setup(){
  dacWrite(26, 128); // for middle 1.65V Ground supply speaker offset for no DC
  Serial.begin(112500);
}

void loop() {
  // Making an array of fn
  void (*fun_ptr_arr[])(int) = {
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
    NOTE_E5,
    NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
    NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
    NOTE_D5, NOTE_G5
  }; 
  int repeat[] = {
    40, 40, 20,
    40, 40, 20,
    40, 40, 40, 40,
    10,
    40, 40, 40, 40,
    40, 40, 40, 80, 80,
    40, 40, 40, 40,
    20, 20
    };
  int delayTime[] = {
    100, 100, 100,
    100, 100, 100,
    100, 100, 100, 100,
    100,
    100, 100, 100, 100,
    100, 100, 100, 100, 100,
    100, 100, 100, 100,
    100, 100
    };
  int len = *(&repeat + 1) - repeat;
  CallNotes(fun_ptr_arr, repeat, delayTime, len);
}

void CallNotes(void (*fun_ptr_arr[])(int), int repeat[], int delayTime[], int len){
  for(int i=0; i<len; i++){
    (*fun_ptr_arr[i])(repeat[i]);
    NOTE_DELAY(delayTime[i]);
  }
}

void NOTE_DELAY(int x){
  dacWrite(25, 128);
  delay(x);
}

void NOTE_C5(int x){
  for(int i=0 ; i<x; i++){
    FrequencyGenerator(3, 44);
  }
}
void NOTE_C6(int x){
  for(int i=0 ; i<x; i++){
    FrequencyGenerator(3, 40);
  }
}
void NOTE_D5(int x){
  for(int i=0 ; i<x; i++){
    FrequencyGenerator(3, 37);
  }
}
void NOTE_D6(int x){
  for(int i=0 ; i<x; i++){
    FrequencyGenerator(3, 33);
  }
}
void NOTE_E5(int x){
  for(int i=0 ; i<x; i++){
    FrequencyGenerator(3, 30);
  }
}
void NOTE_F5(int x){
  for(int i=0 ; i<x; i++){
    FrequencyGenerator(3, 27);
  }
}
void NOTE_F6(int x){
  for(int i=0 ; i<x; i++){
    FrequencyGenerator(3, 25);
  }
}
void NOTE_G5(int x){
  for(int i=0 ; i<x; i++){
    FrequencyGenerator(3, 22);
  }
}
void NOTE_G6(int x){
  for(int i=0 ; i<x; i++){
    FrequencyGenerator(3, 20);
  }
}
void NOTE_A5(int x){
  for(int i=0 ; i<x; i++){
    FrequencyGenerator(3, 17);
  }
}
void NOTE_A6(int x){
  for(int i=0 ; i<x; i++){
    FrequencyGenerator(3, 16);
  }
}
void NOTE_B5(int x){
  for(int i=0 ; i<x; i++){
    FrequencyGenerator(3, 13);
  }
}

void  FrequencyGenerator(int step,int fineTune){
    for(int i=0; i<= 360 ; i=i+step){
      dacWrite(25, 126 * (sin(i*PI/180)+1));
      delayMicroseconds(fineTune);
  }
}
