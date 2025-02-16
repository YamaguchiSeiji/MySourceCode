#include <Wire.h>
#include <AGTimerR4.h>

#define SW_reset 2 //D2
#define SW_stop 3 //D3

#define q_start 0
#define q_count 1
#define q_stop 2

const uint8_t LCD_I2C_ADR = 0x3F;   // 液晶LCDのI2Cアドレス

volatile int state;

volatile int count = 0;
volatile int hour = 0;
volatile int minute = 0;
volatile int sec = 0;
volatile int dec = 0;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  AGTimer.init(100000, timerCallback);

  pinMode(SW_reset, INPUT);
  pinMode(SW_stop, INPUT);

  state = q_start;
  attachInterrupt(0, resetTimer, RISING);
  attachInterrupt(1, stopTimer, RISING);

  // LCD初期設定
  putCMD(0x38); //Function Set
  delay(20);
  clear_display();
  cursor_home();
  cursor_disp_on();
}

void timerCallback(void) {
  char timer[30];

  hour = count / 36000;
  minute = (count / 600) % 60;
  sec = (count / 10) % 60;
  dec = count % 10;

  interrupts();

  clear_display();

  cursor(0,0);
  disp_string("KUMAMOTO KOSEN");

  //sprintf(timer,sizeof(timer), "%02d", count);
  sprintf(timer, "%02d:%02d%:%02d.%d", hour, minute, sec, dec);

  cursor(1,0);
  disp_string(timer);

  if(state == q_count){
    count++;
  } else if(state == q_start){
    count = 0;
  }

}

void cursor(int line, int col) {
  uint8_t pos = 0;

  if (line==1)
    pos += 40;
  else if (line==2)
    pos += 20;
  else if (line==3)
    pos += 84;
  
  pos += col;

  putCMD((0x80) | pos); //set cursor position
}

void disp_string(char str[]) {
  for (int i=0; str[i]!=NULL; i++)
    putDAT(str[i]);
}

void disp_char(char c) {
  putDAT(c);
}

void clear_display(void) {
  putCMD(0x01);
  delay(20);
}

void cursor_home(void) {
  putCMD(0x02);
  delay(20);
}

void cursor_disp_on(void) {
  putCMD(0x0C);
  delay(20);
}

void putCMD(uint8_t dat) {
  //コマンド用関数
  Wire.beginTransmission(LCD_I2C_ADR);
  Wire.write(0x00);
  Wire.write(dat);
  Wire.endTransmission();
}

void putDAT(uint8_t dat) {
  //データ用関数
  Wire.beginTransmission(LCD_I2C_ADR);
  Wire.write(0x40);
  Wire.write(dat);
  Wire.endTransmission();
}

void resetTimer(){
  state = q_start;
}

void stopTimer(){
  if(state == q_start || state == q_stop){
    state = q_count;
  } else if(state == q_count){
    state = q_stop;
  }
}

void loop() {

}
