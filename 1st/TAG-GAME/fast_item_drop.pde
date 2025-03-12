//fast item drop

int Fast_Item_Drop=0;
int Fast_Item_Base_Time=0;
float Fast_ItemX=-100, Fast_ItemY=-100;
int Hito_Fast_Item_Get, Oni_Fast_Item_Get;
float Hito_Fast_Item_Dist, Oni_Fast_Item_Dist;
int Fast_Item_Time;

void Fast_Item_Drop() {
  if (Time/1000<Time_Limit/2) {
    Fast_Item_Drop=1;
  }
  if (Time/1000>Time_Limit/2&&Fast_Item_Drop==1) {
    Fast_ItemX=random(130, 770);
    Fast_ItemY=random(130, 470);
    Fast_Item_Drop=0;
  }
  if (Time/1000>=Time_Limit/2) {
    fill(0, 255, 255);
    ellipse(Fast_ItemX, Fast_ItemY, 20, 20);
    color cFast_ItemYW=get(int(Fast_ItemX), int(Fast_ItemY-11));
    color cFast_ItemXA=get(int(Fast_ItemX-11), int(Fast_ItemY));
    color cFast_ItemYS=get(int(Fast_ItemX), int(Fast_ItemY+11));
    color cFast_ItemXD=get(int(Fast_ItemX+11), int(Fast_ItemY));
    if (cFast_ItemYW==color(0)||cFast_ItemXA==color(0)||cFast_ItemYS==color(0)||cFast_ItemXD==color(0)) {
      Fast_ItemX=random(130, 770);
      Fast_ItemY=random(130, 470);
    }
  }
  if (Hito_Fast_Item_Dist<=20) {
    Fast_Item_Base_Time=millis();
    Fast_ItemY=-100;
    Fast_ItemX=-100;
    Hito_Fast_Item_Get=1;
  }
  if (Hito_Fast_Item_Get==1&&Fast_Item_Time/1000<5) {
    Hito_Speed=6;
    Base_Hito_Speed=6;
  }

  if (Oni_Fast_Item_Dist<=20) {
    Fast_Item_Base_Time=millis();
    Fast_ItemY=-100;
    Fast_ItemX=-100;
    Oni_Fast_Item_Get=1;
  }
  if (Oni_Fast_Item_Get==1&&Fast_Item_Time/1000<5) {
    Oni_Speed=6;
    Base_Oni_Speed=6;
  }
}
