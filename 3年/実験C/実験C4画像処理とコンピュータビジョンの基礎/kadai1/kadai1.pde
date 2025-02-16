// 大域変数
PImage mountain, sea
  ; // 画像ファイルを扱う変数を作る
int mode = 1;

// 初期設定
void setup () {
  size (640, 480, P3D);
  mountain = loadImage("mountain.png"); // 「test.png」という画像ファイルを読み込む
  sea = loadImage("sea.png");
  imageMode(CENTER);
}
// メインルーチン
void draw() {

  background (160, 255, 255); // 背景を水色にする
  if (mode == 1) {
    image(mountain, mouseX, mouseY, 300, 300); // 画像を x=100, y=50 の位置に描く
  } else if (mode == 2) {
    image(sea, mouseX, mouseY, 300, 300);
  }
  fill(0);
}

void keyPressed() {
  if (key == '1') {
    mode = 1;
  } else if (key == '2') {
    mode = 2;
  }
}
