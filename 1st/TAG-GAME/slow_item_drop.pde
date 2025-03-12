//slow item drop

int Slow_Item_Drop=0;
int Slow_Item_Base_Time=0;
float Slow_ItemX=-100, Slow_ItemY=-100;
int Hito_Slow_Item_Get, Oni_Slow_Item_Get;
float Hito_Slow_Item_Dist, Oni_Slow_Item_Dist;
int Slow_Item_Time;

void Slow_Item_Drop() {
  if (Time/1000<Time_Limit/2) {
    Slow_Item_Drop=1;
  }
  if (Time/1000>Time_Limit/2&&Slow_Item_Drop==1) {
    Slow_ItemX=random(130, 770);
    Slow_ItemY=random(130, 470);
    Slow_Item_Drop=0;
  }
  if (Time/1000>=Time_Limit/2) {
    fill(255, 0, 255);
    ellipse(Slow_ItemX, Slow_ItemY, 20, 20);
    color cSlow_ItemYW=get(int(Slow_ItemX), int(Slow_ItemY-11));
    color cSlow_ItemXA=get(int(Slow_ItemX-11), int(Slow_ItemY));
    color cSlow_ItemYS=get(int(Slow_ItemX), int(Slow_ItemY+11));
    color cSlow_ItemXD=get(int(Slow_ItemX+11), int(Slow_ItemY));
    if (cSlow_ItemYW==color(0)||cSlow_ItemXA==color(0)||cSlow_ItemYS==color(0)||cSlow_ItemXD==color(0)) {
      Slow_ItemX=random(130, 770);
      Slow_ItemY=random(130, 470);
    }
  }
  if (Hito_Slow_Item_Dist<=20) {
    Slow_Item_Base_Time=millis();
    Slow_ItemY=-100;
    Slow_ItemX=-100;
    Hito_Slow_Item_Get=1;
  }
  if (Hito_Slow_Item_Get==1&&Slow_Item_Time/1000<5) {
    Hito_Speed=2;
    Base_Hito_Speed=2;
  }

  if (Oni_Slow_Item_Dist<=20) {
    Slow_Item_Base_Time=millis();
    Slow_ItemY=-100;
    Slow_ItemX=-100;
    Oni_Slow_Item_Get=1;
  }
  if (Oni_Slow_Item_Get==1&&Slow_Item_Time/1000<5) {
    Oni_Speed=2;
    Base_Oni_Speed=2;
  }
}
