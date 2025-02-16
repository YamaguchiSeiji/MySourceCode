import processing.video.*; // カメラを表す変数
Capture cam;
float Rt = 255, Gt = 0, Bt = 0;

void setup() {
  size(640, 480);
  String[] settings = Capture.list(); // 設定リストを取得
  if (settings.length == 0) {
    println("There are no cameras available for capture.");
    exit();
  }
  cam = new Capture(this, settings[0]); // 0 番目の設定を有効化
  cam.start(); // 撮影開始
  printArray(settings);
}

void draw() {
  if (cam.available() == true) cam.read(); // 現在のカメラ画像を取得
  image(cam, 0, 0);
  noFill();
  color t;
  t = color(Rt, Gt, Bt);
  int x, y, p1;
  float xmin = width, xmax = 0, ymin =height, ymax = 0;
  for (y = 0; y<cam.height; y++) {
    for (x = 0; x<cam.width; x++) {
      p1 = y * cam.width + x; 
      float r = red(cam.pixels[p1]);
      float g = green(cam.pixels[p1]);
      float b = blue(cam.pixels[p1]);
      float diff = sqrt(pow(Rt-r, 2) + pow(Gt-g, 2) + pow(Bt-b, 2));
      if (diff <= 25) {
        if (x < xmin) {
          xmin = x;
        }
        if (x > xmax) {
          xmax = x;
        }
        if (y < ymin) {
          ymin = y;
        }
        if (y > ymax) {
          ymax = y;
        }
      }
    }
  }
  stroke(255, 255, 0);
  strokeWeight(5);
  rect(xmin, ymin, xmax-xmin, ymax-ymin);
}

void mousePressed() {
  loadPixels();
  int i = mouseY * width + mouseX;
  Rt = red(pixels[i]);
  Gt = green(pixels[i]);
  Bt = blue(pixels[i]);
}
