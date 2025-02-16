import de.voidplus.leapmotion.*;

LeapMotion leap;
PImage curry, katsudon, udon;
PFont font;
int flag = 0;
float z = 0;
int mode = 0;

//--------------------------------------
void setup() {
  size(800, 500, P3D);
  leap = new LeapMotion(this);
  curry = loadImage("curry.png");
  katsudon = loadImage("katsudon.png");
  udon = loadImage("udon.png");
  imageMode(CENTER);
  textAlign(CENTER, CENTER);
  font = loadFont("CambriaMath-48.vlw");
  textFont(font);
}

//--------------------------------------
void draw() {
  switch(mode) {
  case 0:

    background(255);

    drawButton0();

    ArrayList<Hand> hands = leap.getHands();
    int handNum = hands.size();      // 現在認識している手の数を得る
    if (handNum <= 0) return;        // もし手を検知していなければここで終了

    Hand h = hands.get(0);           // 0番目の手の情報を得る
    h.draw();                        // 手を描く
    Finger f;
    f = h.getFinger(1);              // 手の0番目の指(親指)の情報を得る
    PVector pos1 = f.getPositionOfJointTip();  // つま先の座標を得る

    drawButton1(pos1);
    break;
  case 1:
    result();
    break;
  }
}

//--------------------------------------
void drawEllipse(PVector pos) {
  fill(0, 100);
  pushMatrix();
  translate(pos.x, pos.y, pos.z);
  ellipse(0, 0, 30, 30);
  popMatrix();
}

void drawButton0() {
  fill(0);
  textSize(50);
  text("Choose Someone", width/2, height/2+150);
  strokeWeight(5);
  pushMatrix();
  translate(width/2, height/2, 1);
  fill(255);
  ellipse(-250, 0, 200, 200);
  fill(255);
  image(curry, -250, 0, 100, 70);
  ellipse(0, 0, 200, 200);
  image(katsudon, 0, 0, 100, 100);
  ellipse(250, 0, 200, 200);
  image(udon, 250, 0, 100, 100);
  popMatrix();
  strokeWeight(1);
  textSize(10);
}

void drawButton1(PVector pos1) {
  if (flag == 0) {
    z = pos1.z;
  }
  textSize(50);
  pushMatrix();
  translate(width/2, height/2, 1);
  fill(255);
  strokeWeight(5);

  float curry_d = dist(pos1.x, pos1.y, width/2-250, height/2);
  if (curry_d <= 100) {
    judge(pos1);
  }
  ellipse(-250, 0, 200, 200);
  fill(255);
  image(curry, -250, 0, 100, 70);

  float katsudon_d = dist(pos1.x, pos1.y, width/2, height/2);
  if (katsudon_d <= 100) {
    judge(pos1);
  }
  ellipse(0, 0, 200, 200);
  fill(255);
  image(katsudon, 0, 0, 100, 100);

  float udon_d = dist(pos1.x, pos1.y, width/2+250, height/2);
  if (udon_d <= 100) {
    judge(pos1);
  }

  if (curry_d > 100 && katsudon_d > 100 && udon_d > 100) {
    flag = 0;
  }
  ellipse(250, 0, 200, 200);
  fill(255);
  image(udon, 250, 0, 100, 100);
  fill(0);
  popMatrix();
  strokeWeight(1);
}

void judge(PVector pos1) {
  if (flag == 0) {
    z = pos1.z;
    flag = 1;
  }
  if (flag == 1 && pos1.z - z >= 15) {
    mode = 1;
  }
  fill(0);
  text("Press to Buy", 0, -150);
  fill(255, 255, 0);
}

void result() {
  background(255);
  textSize(100);
  fill(0);
  text("Thank You!!", width/2, height/2);
}
