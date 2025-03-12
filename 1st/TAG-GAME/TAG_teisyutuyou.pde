float w, a, s, d;
float x, y;
float Hito_Speed=4;
float Base_Hito_Speed=4;

float up, left, down, right;
float x2, y2;
float Oni_Speed=4.3;
float Base_Oni_Speed=4.3;

int Base_Time=0;
int Time;

int Screen=0;
int Time_Limit=30;
int Stage_Select;

void setup() {
  size(900, 600);
  x=130;
  y=130;
  x2=770;
  y2=470;
  textAlign(CENTER, CENTER);

  BallX=new float[n];
  BallY=new float[n];
  BallX_Speed=new float[n];
  BallY_Speed=new float[n];

  PFont font;
  font =createFont("Century", 32);
  textFont(font);
}


void draw() {
  //Timer reset
  Slow_Item_Time=millis()-Slow_Item_Base_Time;
  Fast_Item_Time=millis()-Fast_Item_Base_Time;
  Time=millis()-Base_Time;

  switch(Screen) {
    case(0):
    //start ready
    background(255);
    fill(0);
    noStroke();
    textSize(40);
    text("PRESS 'SPACE' KEY TO START", width/2, height/2-120);
    fill(0, 0, 255);
    textSize(20);
    ellipse(250, height/2-30, 20, 20);
    text("BLUE BALL IS 'HITO'", width/2, height/2-30);
    fill(255, 0, 0);
    ellipse(250, height/2+20, 20, 20);
    text("RED BALL IS 'ONI'", width/2, height/2+20);
    fill(255, 0, 255);
    ellipse(250, height/2+70, 20, 20);
    text("PURPLE BALL IS 'SLOW ITEM'", width/2, height/2+70);
    fill(0, 255, 255);
    ellipse(250, height/2+120, 20, 20);
    text("SKY BLUE BALL IS 'FAST ITEM'", width/2, height/2+120);

    if (keyPressed==true) {
      if (key==' ') {
        Screen=1;
        Base_Time=millis();
        Stage_Select=int(random(1, 11));
        
        Hito_Slow_Item_Get=0;
        Oni_Slow_Item_Get=0;
        Hito_Fast_Item_Get=0;
        Oni_Fast_Item_Get=0;
        
        x=130;
        y=130;
        x2=770;
        y2=470;
      }
    }

    //stage4 setup
    for (int i=0; i<n; i++) {
      BallX[i]=random(180, 720);
      BallY[i]=random(180, 420);
      BallX_Speed[i]=random(-Ball_Speed, Ball_Speed);
      BallY_Speed[i]=random(-Ball_Speed, Ball_Speed);
    }

    break;

    //game start
    case(1):
    float dist=dist(x, y, x2, y2);
    Hito_Slow_Item_Dist=dist(x, y, Slow_ItemX, Slow_ItemY);
    Oni_Slow_Item_Dist=dist(x2, y2, Slow_ItemX, Slow_ItemY);
    Hito_Fast_Item_Dist=dist(x, y, Fast_ItemX, Fast_ItemY);
    Oni_Fast_Item_Dist=dist(x2, y2, Fast_ItemX, Fast_ItemY);
    background(255);

    //stage setup
    if (Stage_Select==1)stage1();
    if (Stage_Select==2)stage2();
    if (Stage_Select==3)stage3();
    if (Stage_Select==4)stage4();
    if (Stage_Select==5)stage5();
    if (Stage_Select==6)stage6();
    if (Stage_Select==7) {
      stage7();
      if (Time<100) {
        x=450;
        y=125;
        x2=450;
        y2=475;
      }
    }
    if (Stage_Select==8)stage8();
    if (Stage_Select==9)stage9();
    if (Stage_Select==10)stage10();

    fill(0);
    text("TIME LIMIT =", 80, 50);
    text(Time_Limit-Time/1000, 165, 50);

    //Hito moving
    fill(0, 0, 255);
    noStroke();
    ellipse(x, y, 20, 20);

    if (w==1)y-=Hito_Speed;
    if (a==1)x-=Hito_Speed;
    if (s==1)y+=Hito_Speed;
    if (d==1)x+=Hito_Speed;

    color cw=get(int(x), int(y-11));    
    color ca=get(int(x-11), int(y));    
    color cs=get(int(x), int(y+11));    
    color cd=get(int(x+11), int(y));
    color cwA=get(int(x-11), int(y-11));
    color caS=get(int(x-11), int(y+11));
    color csD=get(int(x+11), int(y+11));
    color cdW=get(int(x+11), int(y-11));

    if (cw==color(0))y+=Hito_Speed;
    if (ca==color(0))x+=Hito_Speed;
    if (cs==color(0))y-=Hito_Speed;
    if (cd==color(0))x-=Hito_Speed;
    if (cw==color(0)&&ca==color(0)&&cs==color(255)&&cd==color(0))y+=10;
    if (cw==color(0)&&ca==color(0)&&cs==color(0)&&cd==color(255))x+=10;
    if (cw==color(255)&&ca==color(0)&&cs==color(0)&&cd==color(0))y-=10;
    if (cw==color(0)&&ca==color(255)&&cs==color(0)&&cd==color(0))x-=10;
    if (cwA==color(0)&&caS==color(0)&&csD==color(255)&&cdW==color(0))x+=10; y+=10;          
    if (cwA==color(0)&&caS==color(0)&&csD==color(0)&&cdW==color(255))x+=10; y-=10;    
    if (cwA==color(255)&&caS==color(0)&&csD==color(0)&&cdW==color(0))x-=10; y-=10;    
    if (cwA==color(0)&&caS==color(255)&&csD==color(0)&&cdW==color(0))x-=10; y+=10;
    
    if (w==1&&a==1||a==1&&s==1||s==1&&d==1||d==1&&w==1) {
      Hito_Speed=Base_Hito_Speed/sqrt(2);
    } else {
      Hito_Speed=4;
      Base_Hito_Speed=4;
    }

    if (x<100)x=120;
    if (x>800)x=780;
    if (y<100)y=120;
    if (y>500)y=480;

    //Oni moving
    fill(255, 0, 0);
    noStroke();
    ellipse(x2, y2, 20, 20);

    if (up==1)y2-=Oni_Speed;
    if (left==1)x2-=Oni_Speed;
    if (down==1)y2+=Oni_Speed;
    if (right==1)x2+=Oni_Speed;

    color cUP=get(int(x2), int(y2-11));    
    color cLEFT=get(int(x2-11), int(y2));    
    color cDOWN=get(int(x2), int(y2+11));
    color cRIGHT=get(int(x2+11), int(y2));    
    color cUP_LEFT=get(int(x2-11), int(y2-11));
    color cLEFT_DOWN=get(int(x2-11), int(y2+11));
    color cdOWN_RIGHT=get(int(x2+11), int(y2+11));
    color cdOWN_UP=get(int(x2+11), int(y2-11));

    if (cUP==color(0))y2+=Oni_Speed;
    if (cLEFT==color(0))x2+=Oni_Speed;
    if (cDOWN==color(0))y2-=Oni_Speed;
    if (cRIGHT==color(0))x2-=Oni_Speed;
    if (cUP==color(0)&&cLEFT==color(0)&&cDOWN==color(255)&&cRIGHT==color(0))y2+=10;
    if (cUP==color(0)&&cLEFT==color(0)&&cDOWN==color(0)&&cRIGHT==color(255))x2+=10;
    if (cUP==color(255)&&cLEFT==color(0)&&cDOWN==color(0)&&cRIGHT==color(0))y2-=10;
    if (cUP==color(0)&&cLEFT==color(255)&&cDOWN==color(0)&&cRIGHT==color(0))x2-=10;
    if (cUP_LEFT==color(0)&&cLEFT_DOWN==color(0)&&cdOWN_RIGHT==color(255)&&cdOWN_UP==color(0))x2+=10; y2+=10;          
    if (cUP_LEFT==color(0)&&cLEFT_DOWN==color(0)&&cdOWN_RIGHT==color(0)&&cdOWN_UP==color(255))x2+=10; y2-=10;    
    if (cUP_LEFT==color(255)&&cLEFT_DOWN==color(0)&&cdOWN_RIGHT==color(0)&&cdOWN_UP==color(0))x2-=10; y2-=10;        
    if (cUP_LEFT==color(0)&&cLEFT_DOWN==color(255)&&cdOWN_RIGHT==color(0)&&cdOWN_UP==color(0))x2-=10; y2+=10;   

    if (up==1&&left==1||left==1&&down==1||down==1&&right==1||right==1&&up==1) {
      Oni_Speed=Base_Oni_Speed/sqrt(2);
    } else {
      Oni_Speed=4.3;
      Base_Oni_Speed=4.3;
    }

    if (x2<100)x2=120;
    if (x2>800)x2=780;
    if (y2<100)y2=120;
    if (y2>500)y2=480;

    //item drop
    Slow_Item_Drop();
    Fast_Item_Drop();

    //Hito lose 
    if (dist<20) {
      Screen=2;
    }

    //Oni lose
    if (Time/1000>=Time_Limit) {
      Screen=3;
    }   
    break;

    //game finish
    case(2):
    background(255);
    fill(255, 0, 0);
    text("ONI WIN!!", width/2, height/2-10);
    text("PRESS 'R' KEY TO RESTART", width/2, height/2+10);
    if (keyPressed==true) {
      if (key=='r') {
        Screen=0;
      }
    }
    break;

    case(3):
    background(255);
    fill(0, 0, 255);
    text("HITO WIN!!", width/2, height/2-10);
    text("PRESS 'R' KEY TO RESTART", width/2, height/2+10);
    if (keyPressed==true) {
      if (key=='r') {
        Screen=0;
      }
    }
    break;
  }
}


void keyPressed() {
  if (key=='w')w=1;
  if (key=='a')a=1;
  if (key=='s')s=1;
  if (key=='d')d=1;

  if (key==CODED) {
    if (keyCode==UP)up=1;
    if (keyCode==LEFT)left=1;
    if (keyCode==DOWN)down=1;
    if (keyCode==RIGHT)right=1;
  }
}


void keyReleased() {
  if (key=='w')w=0;
  if (key=='a')a=0;
  if (key=='s')s=0;
  if (key=='d')d=0;

  if (key==CODED) {
    if (keyCode==UP)up=0;
    if (keyCode==LEFT)left=0;
    if (keyCode==DOWN)down=0;
    if (keyCode==RIGHT)right=0;
  }
}
