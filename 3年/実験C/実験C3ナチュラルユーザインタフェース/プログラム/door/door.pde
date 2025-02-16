import de.voidplus.leapmotion.*;

LeapMotion leap;

//--------------------------------------
void setup() {
  size(800, 500, P3D);
  leap = new LeapMotion(this);
}

//--------------------------------------
void draw() {
  background(255);
  ArrayList<Hand> hands = leap.getHands();
  int handNum = hands.size();      // 現在認識している手の数を得る
  
  pushMatrix();
  translate(width/2, height/2);
  fill(100);
  ellipse(0, 0, 100, 100);
  fill(200);
  translate(0, 0, 1);
  rect(-25, -25, 300, 50, 20);
  popMatrix();
  
  if (handNum <= 0) return;        // もし手を検知していなければここで終了
  
  background(255);
  Hand h = hands.get(0);           // 0番目の手の情報を得る
  h.draw();                        // 手を描く
  Finger f;
  f = h.getFinger(0);              // 手の0番目の指(親指)の情報を得る
  PVector pos1 = f.getPositionOfJointTip();  // つま先の座標を得る
  PVector pos2 = f.getPositionOfJointDip();  // 第1関節の座標を得る
  PVector pos3 = f.getPositionOfJointPip();  // 第2関節の座標を得る
  PVector pos4 = f.getPositionOfJointMcp();  // 第3関節の座標を得る
  
  drawEllipse(pos1);  // つま先の位置に円を描く
  drawEllipse(pos2);  // 第1関節の位置に円を描く
  drawEllipse(pos3);  // 第2関節の位置に円を描く
  drawEllipse(pos4);  // 第3関節の位置に円を描く
  
  Finger hitosashi = h.getFinger(1);
  PVector v1 = hitosashi.getPositionOfJointMcp();
  Finger koyubi = h.getFinger(4);
  PVector v4 = koyubi.getPositionOfJointMcp();
  float theta = atan2(v4.y - v1.y, v4.x - v1.x);
  
  pushMatrix();
  translate(width/2, height/2);
  fill(100);
  ellipse(0, 0, 100, 100);
  fill(200);
  translate(0, 0, 1);
  rotateZ(theta);
  rect(-25, -25, 300, 50, 20);
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
