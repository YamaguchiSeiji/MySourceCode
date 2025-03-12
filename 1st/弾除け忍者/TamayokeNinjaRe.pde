PImage background;
PImage Ninja_F;
PImage Ninja_L;
PImage Ninja_R;
PImage Ninja_syuriken;
PImage life_heart;
PFont font;
int s=0;
int base_time=0;
int life_time=0;
float NX=960, NY=height-150;
float ninjaSpeed=25;
float coinSpeed=5;
float syurikenSpeed=10, syurikenSpeedPlus=0.3;
float[] coinX, coinY, coinD;
int i, n;
float[] syurikenX, syurikenY, syurikenD;
int coinNumber=1, syurikenNumber=1;
int score=0;
int life=3;
float lifeX, lifeY, lifeD;
int resultScore=0, resultTime=0;
int r, l, f;

import ddf.minim.*;
Minim minim;
AudioPlayer menuBGM;
Minim minim2;
AudioPlayer gameBGM;
Minim se1;
AudioPlayer coinSE;
Minim se2;
AudioPlayer damageSE;
Minim se3;
AudioPlayer clickSE;
Minim se4;
AudioPlayer startSE;
Minim se5;
AudioPlayer healSE;

void setup() {
  size(1920, 1080);
  background=loadImage("data/takeyabu.png");
  Ninja_F=loadImage("data/ninja.png");
  Ninja_R=loadImage("data/ninja_right.png");
  Ninja_L=loadImage("data/ninja_left.png");
  Ninja_syuriken=loadImage("data/ninja_syuriken2.png");
  life_heart=loadImage("data/life.png");
  font=createFont("data/Font/aoyanagi.ttf", 1);
  coinX=new float[5];
  coinY=new float[5];
  coinD=new float[5];
  syurikenX=new float[5];
  syurikenY=new float[5];
  lifeX=random(50, 1870);
  for (i=0; i<3; i++) {
    coinX[i]=random(50, 1870);
    coinY[i]=0;
  }
  for (i=0; i<5; i++) {
    syurikenX[i]=random(50, 1870);
    syurikenY[i]=0;
  }
  minim=new Minim(this);
  menuBGM=minim.loadFile("data/BGM/menu/MusMus-BGM-027.mp3", 2048);
  if (menuBGM==null) exit();

  minim2=new Minim(this);
  gameBGM=minim.loadFile("data/BGM/game/轟天_.mp3", 2048);
  if (gameBGM==null) exit();

  se1=new Minim(this);
  coinSE=minim.loadFile("data/SE/coin05.mp3", 2048);
  if (coinSE==null) exit();

  se2=new Minim(this);
  damageSE=minim.loadFile("data/SE/damage7.mp3", 2048);
  if (damageSE==null) exit();

  se3=new Minim(this);
  clickSE=minim.loadFile("data/SE/button01a.mp3", 2048);
  if (clickSE==null) exit();

  se4=new Minim(this);
  startSE=minim.loadFile("data/SE/ホイッスル・単発.mp3", 2048);
  if (startSE==null) exit();

  se5=new Minim(this);
  healSE=minim.loadFile("data/SE/heal01.mp3", 2048);
  if (healSE==null) exit();
}

void draw() {
  int time=millis()-base_time;
  int lifeCool=millis()-life_time;
  lifeD=dist(NX, NY, lifeX, lifeY);
  image(background, width/2, height/2);
  textFont(font);
  //menu
  switch(s) {
    case(0):
    //BGM
    menuBGM.play();
    if (menuBGM.isPlaying()==false) {
      menuBGM.rewind();
      menuBGM.loop();
    }
    //title
    textAlign(CENTER, CENTER);
    imageMode(CENTER);
    stroke(0);
    strokeWeight(10);
    fill(255);
    textSize(200);
    text("弾避け忍者", width/2+20, height/6+20);
    textSize(200);
    fill(0);
    text("弾避け忍者", width/2, height/6);
    //start
    textSize(125);
    fill(0, 0, 0, 150);
    rect(width/2-300, 350, 600, 170, 50);
    //setting
    rect(width/2-300, 570, 600, 170, 50);
    //exit
    rect(width/2-300, 790, 600, 170, 50);
    fill(255);
    text("開始", width/2, 425);
    text("遊び方", width/2, 645);
    text("やめる", width/2, 865);
    //push start
    if (mouseX>=width/2-300&&mouseY>=350&&mouseX<=width/2+300&&mouseY<=520) {
      strokeWeight(10);
      stroke(255, 255, 0);
      fill(0, 0, 0, 0);
      rect(width/2-300, 350, 600, 170, 50);
      if (mousePressed==true) {
        s=1;
        clickSE.play();
        clickSE.rewind();
      }
    }
    if (mouseX>=width/2-300&&mouseY>=570&&mouseX<=width/2+300&&mouseY<=740) {
      strokeWeight(10);
      stroke(255, 255, 0);
      fill(0, 0, 0, 0);
      rect(width/2-300, 570, 600, 170, 50);
      if (mousePressed==true) {
        s=5;
        clickSE.play();
        clickSE.rewind();
      }
    }
    if (mouseX>=width/2-300&&mouseY>=790&&mouseX<=width/2+300&&mouseY<=950) {
      strokeWeight(10);
      stroke(255, 255, 0);
      fill(0, 0, 0, 0);
      rect(width/2-300, 790, 600, 170, 50);
      if (mousePressed==true) {
        s=6;
      }
    }
    break;
    //ready to start
    case(1):
    fill(0);
    textSize(150);
    text("スペースキーを押して開始", width/2, height/2);
    if (keyPressed==true) {
      if (key==' ') {
        base_time=millis();
        s+=1;
      }
    }
    menuBGM.pause();
    break;
    //gameready
    case(2):
    switch(time/1000) {
      case(0):
      textSize(500);
      fill(0);
      text("3", width/2, height/2-100);
      break;
      case(1):
      textSize(500);
      fill(0);
      text("2", width/2, height/2-100);
      break;
      case(2):
      textSize(500);
      fill(0);
      text("1", width/2, height/2-100);
      startSE.rewind();
      break;
      case(3):
      textSize(500);
      fill(0);
      text("開始!!", width/2, height/2-100);
      startSE.play();
      break;
      case(4):
      s=3;
      gameBGM.rewind();
      gameBGM.play();
      gameBGM.loop();
      base_time=millis();
      break;
    }
    break;
    //gamestart
    case(3):
    textAlign(LEFT, TOP);
    textSize(100);
    text("スコア="+score, 0, 0);
    for (i=1; i<life+1; i++) {
      image(life_heart, i*100, 160);
    }
    NY=height-150;

    if (r==1&&l!=1) {
      image(Ninja_R, NX, NY);
      NX+=ninjaSpeed;
    }
    if (l==1&&r!=1) {
      image(Ninja_L, NX, NY);
      NX-=ninjaSpeed;
    }
    if (r==0&&l==0||r==1&&l==1)image(Ninja_F, NX, NY);

    if (NX>=width-70) {
      NX=width-75;
    }
    if (NX<=70) {
      NX=75;
    }
    for (i=0; i<coinNumber; i++) {
      fill(0);
      coinD[i]=dist(NX, NY, coinX[i], coinY[i]);
      coinY[i]+=coinSpeed;
      ellipse(coinX[i], coinY[i], 50, 50);
      if (coinY[i]>=height) {
        coinY[i]=0;
        coinX[i]=random(50, 1870);
      }
      if (coinD[i]<=95) {
        score+=100;
        coinSE.play();
        coinSE.rewind();
        coinY[i]=0;
        coinX[i]=random(50, 1870);
        syurikenSpeed+=syurikenSpeedPlus;
      }
    }
    for (i=0; i<syurikenNumber; i++) {
      fill(0);
      syurikenY[i]+=syurikenSpeed;
      image(Ninja_syuriken, syurikenX[i], syurikenY[i]);
      if (syurikenY[i]>=height) {
        syurikenY[i]=0;
        syurikenX[i]=random(50, 1870);
      }
      if (NX>syurikenX[i]-150&&NY>syurikenY[i]-50&&NX<syurikenX[i]+150&&NY<syurikenY[i]+50||NX>syurikenX[i]-50&&NY>syurikenY[i]-150&&NX<syurikenX[i]+50&&NY<syurikenY[i]+150) {
        life-=1;
        damageSE.play();
        damageSE.rewind();
        syurikenY[i]=0;
        syurikenX[i]=random(50, 1870);
      }
    }
    if (lifeCool/1000==20) {
      lifeY=0;
      n=1;
      life_time=millis();
    }
    if (n==1) {
      image(life_heart, lifeX, lifeY);
      lifeY+=5;
      healSE.rewind();
      if (lifeD<=120) {
        life+=1;
        lifeX=random(50, 1870);
        healSE.play();
        n=0;
        if (life>=4) {
          life-=1;
        }
      }
      if (lifeY>=height) {
        n=0;
      }
    }

    switch(score) {
      case(1000):
      syurikenNumber=2;
      break;
      case(2000):
      syurikenNumber=3;
      break;
      case(3000):
      syurikenNumber=4;
      break;
      case(4000):
      syurikenNumber=5;
      break;
    }

    if (life==0) {
      resultScore=score;
      resultTime=time/1000;
      s=4;
      life_time=millis();
      textAlign(CENTER, CENTER);
      life=3;
      score=0;
      syurikenSpeed=10;
      syurikenSpeedPlus=0.3;
      gameBGM.pause();
      menuBGM.rewind();
      syurikenNumber=1;
      for (i=0; i<syurikenNumber; i++) {
        syurikenY[i]=0;
        syurikenX[i]=random(50, 1870);
      }
      for (i=0; i<coinNumber; i++) {
        coinY[i]=0;
        coinX[i]=random(50, 1870);
      }
    }
    break;
    case(4):
    menuBGM.play();
    fill(0, 0, 0, 150);
    stroke(0);
    rect(width/2-600, height/2-475, 1200, 900, 50);
    textAlign(CENTER, CENTER);
    textSize(200);
    fill(255);
    text("結果", width/2, 150);
    textAlign(LEFT);
    textSize(100);
    text("スコア:"+resultScore, width/2-500, 400);
    text("生存時間(秒):"+resultTime, width/2-500, 600);
    fill(0, 0, 0, 150);
    strokeWeight(10);
    stroke(0);
    if (mouseX>=width/2-500&&mouseY>=750&&mouseX<=width/2-50&&mouseY<=850&&s==4) {
      stroke(255, 255, 0);
    }
    rect(width/2-500, 750, 450, 100, 25);
    stroke(0);
    if (mouseX>=width/2+50&&mouseY>=750&&mouseX<=width/2+500&&mouseY<=850&&s==4) {
      stroke(255, 255, 0);
    }
    rect(width/2+50, 750, 450, 100, 25);
    textSize(60);
    textAlign(CENTER, CENTER);
    fill(255);
    text("タイトルへ戻る", width/2-275, 800);
    text("再開", width/2+275, 800);
    break;
    case(5):
    fill(0, 0, 0, 150);
    stroke(0);
    rect(width/2-600, height/2-475, 1200, 900, 50);
    fill(255);
    textSize(125);
    textAlign(CENTER, CENTER);
    strokeWeight(1);
    text("遊び方", width/2, 150);
    textSize(100);
    fill(255);
    rect(width/2-550, 250, 75, 75);
    rect(width/2-550, 370, 75, 75);
    rect(width/2-550, 610, 75, 75);
    strokeWeight(10);
    stroke(255, 255, 0);
    fill(0);
    ellipse(width/2-512.5, 287.5, 50, 50);
    textAlign(LEFT, CENTER);
    fill(255);
    textSize(50);
    text("・コインに触れるとスコア+100", width/2-450, 287.5);
    image(Ninja_syuriken, width/2-512.5, 407.5, Ninja_syuriken.width/4, Ninja_syuriken.height/4);
    text("・手裏剣に触れるとライフ-1", width/2-450, 407.5);
    text("・コインを取ると手裏剣の速度UP", width/2-450, 472.5);
    text("・スコア1000毎に手裏剣の数UP(最大5つ)", width/2-450, 542.5);
    image(life_heart, width/2-512.5, 647.5, life_heart.width/1.5, life_heart.height/1.5);
    text("・ゲーム開始時はライフ３", width/2-450, 647.5);
    textSize(60);
    text("ゲーム説明:", width/2-550, 757.5);
    fill(255, 0, 0);
    text("←→でとにかく避けろ！！", width/2-200, 757.5);
    fill(0, 0, 0, 150);
    stroke(0);
    if (mouseX>=width/2-150&&mouseY>=850&&mouseX<=width/2+150&&mouseY<=950) {
      stroke(255, 255, 0);
    }
    rect(width/2-150, 850, 300, 100, 25);
    textAlign(CENTER, CENTER);
    fill(255);
    text("戻る", width/2, 900);
    break;
    case(6):
    exit();
  }
}

void mouseClicked() {
  if (mouseX>=width/2-150&&mouseY>=850&&mouseX<=width/2+150&&mouseY<=950&&s==5) {
    s=0;
    clickSE.play();
    clickSE.rewind();
  }
  if (mouseX>=width/2-500&&mouseY>=750&&mouseX<=width/2-50&&mouseY<=850&&s==4) {
    s=0;
    clickSE.play();
    clickSE.rewind();
  }
  if (mouseX>=width/2+50&&mouseY>=750&&mouseX<=width/2+500&&mouseY<=850&&s==4) {
    s=1;
    clickSE.play();
    clickSE.rewind();
  }
}


void keyPressed() {
  if (keyPressed==true) {
    if (key==CODED) {
      if (keyCode==RIGHT) r=1;
      if (keyCode==LEFT) l=1;
    }
  }
}

void keyReleased() {
  if (key==CODED) {
    if (keyCode==RIGHT) r=0;
    if (keyCode==LEFT)l=0;
  }
}
