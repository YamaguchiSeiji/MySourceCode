
import android.view.MotionEvent;
import ketai.ui.*;

// Ke:tai機能を使うための大域変数
KetaiGesture gesture;

//---------------------------------------
// ke:taiライブラリの所定の関数に操作イベントを引き渡すための"おまじない"
public boolean surfaceTouchEvent(MotionEvent e) {
  super.surfaceTouchEvent(e);
  return gesture.surfaceTouchEvent(e);
}

//---------------------------------------
// (動作確認用) 画面に文字列sを表示する関数
//
void drawString(String s, float x, float y) {
  background(255);
  fill(0);
  textSize(50);
  text(s, x, y);
}

//---------------------------------------
// アプリ実行開始時に一度だけ実行される初期化用関数
float mx;
float my;
PImage img;
PFont font;

void setup() {
  gesture = new KetaiGesture(this);
  background(255);
  mx = random(width);
  my = random(height);
  img = loadImage("mogura.png");
  imageMode(CENTER);
  image(img, mx, my, 200, 200);
}
int score = 0;
//---------------------------------------
// アプリ実行時に何度も繰り返し実行されるmain関数
void draw() {
  text("score="+score, 100, 100);
}

void onTap(float x, float y) {
  float dis = dist(x, y, mx, my);
  if (dis <= 200) {
    drawString("Hit", mx, my);
    score++;
    setup();
  }
}
