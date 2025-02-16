import de.voidplus.leapmotion.*;

LeapMotion leap;

PImage handle, car;

//--------------------------------------
void setup() {
  size(1600, 900, P3D);
  leap = new LeapMotion(this);
  handle = loadImage("handle.png");
  car = loadImage("car.png");
  imageMode(CENTER);
}

float speed = 2;
float s = 0;
float y = height;
float car_x = width/2;
//--------------------------------------
void draw() {
  background(167, 211, 152);
  ArrayList<Hand> hands = leap.getHands();
  int handNum = hands.size();      // 現在認識している手の数を得る
  
  drawRoad();
  image(handle, width/2, height/2+200);
  image(car, width/2, height/2, 84, 120);
  
  if (handNum <= 1){
    return;        // もし手を検知していなければここで終了
  }
  background(167, 211, 152);
  Hand h0 = hands.get(0);  // 0番目の手の情報を得る
  Hand h1 = hands.get(1);
  h0.draw();  // 手を描く
  h1.draw();
  Finger f0;
  Finger f1;
  f0 = h0.getFinger(0);              // 手の0番目の指(親指)の情報を得る
  PVector pos0_1 = f0.getPositionOfJointTip();  // つま先の座標を得る
  PVector pos0_2 = f0.getPositionOfJointDip();  // 第1関節の座標を得る
  PVector pos0_3 = f0.getPositionOfJointPip();  // 第2関節の座標を得る
  PVector pos0_4 = f0.getPositionOfJointMcp();  // 第3関節の座標を得る
  
  f1 = h1.getFinger(0);              // 手の0番目の指(親指)の情報を得る
  PVector pos1_1 = f1.getPositionOfJointTip();  // つま先の座標を得る
  PVector pos1_2 = f1.getPositionOfJointDip();  // 第1関節の座標を得る
  PVector pos1_3 = f1.getPositionOfJointPip();  // 第2関節の座標を得る
  PVector pos1_4 = f1.getPositionOfJointMcp();  // 第3関節の座標を得る
  
  drawEllipse(pos0_1);  // つま先の位置に円を描く
  drawEllipse(pos0_2);  // 第1関節の位置に円を描く
  drawEllipse(pos0_3);  // 第2関節の位置に円を描く
  drawEllipse(pos0_4);  // 第3関節の位置に円を描く
  
  drawEllipse(pos1_1);  // つま先の位置に円を描く
  drawEllipse(pos1_2);  // 第1関節の位置に円を描く
  drawEllipse(pos1_3);  // 第2関節の位置に円を描く
  drawEllipse(pos1_4);  // 第3関節の位置に円を描く
  
  Finger naka_0 = h0.getFinger(2);
  PVector v3_0 = naka_0.getPositionOfJointMcp();
  Finger naka_1 = h1.getFinger(2);
  PVector v3_1 = naka_1.getPositionOfJointMcp();
  if(v3_0.x <= width/2 && v3_1.x >= width/2){
    s = v3_1.y - height/2 - 200;
    car_x -= (height/2+200 - v3_1.y)/75;
  } else if(v3_0.x >= width/2 && v3_1.x <= width/2){
    s = v3_0.y - height/2 - 200;
    car_x += (height/2+200 - v3_1.y)/75;
  }
  
  
  
  drawRoad();
  pushMatrix();
  translate(width/2, height/2, 0);
  image(car, car_x, 0, 84, 120);
  popMatrix();
  pushMatrix();
  translate(width/2, height/2+200, 1);
  rotateZ(s/100);
  image(handle, 0, 0);
  popMatrix();
  

}

//--------------------------------------
void drawEllipse(PVector pos){
  fill(0, 100);
  pushMatrix();
  translate(pos.x, pos.y, pos.z);
  ellipse(0, 0, 30, 30);
  popMatrix();
}

void drawRoad(){
  fill(150);
  noStroke();
  rect(width/2-200, 0, 400, height);
  y += speed;
  for(int i = 0; i<10000; i++){
    fill(255);
    rect(width/2-7, y-100*i, 14, 30);
  }
}
