import processing.video.*; // カメラを表す変数
Capture cam;
PImage cam1, cam2, cam3;

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
  
  int x = 0, y = 0;
  int p1, p2;
  
  cam1 = createImage(cam.width, cam.height, RGB);
  cam2 = createImage(cam.width, cam.height, RGB);
  cam3 = createImage(cam.width, cam.height, RGB);
  
  for (y = 0; y < cam.height; y++) {
    for (x = 0; x < cam.width; x++) {
      p1 = y * cam.width + x;
      p2 = y * cam.width + (cam.width - 1 - x);
      cam1.pixels[p1] = cam.pixels[p2];
    }
  }

  for (y = 0; y < cam.height; y++) {
    for (x = 0; x < cam.width; x++) {
      p1 = y * cam.width + x;
      p2 = (cam.height - y - 1) * cam.width + x;
      cam2.pixels[p1] = cam.pixels[p2];
    }
  }

  for (y = 0; y < cam2.height; y++) {
    for (x = 0; x < cam2.width; x++) {
      p1 = y * cam2.width + x;
      p2 = y * cam2.width + (cam2.width - 1 - x);
      cam3.pixels[p1] = cam2.pixels[p2];
    }
  }

  // 画像を表示する
  image(cam,0, 0, width/2, height/2);
  image(cam1, width/2, 0, width/2, height/2);
  image(cam2, 0, height/2, width/2, height/2);
  image(cam3, width/2, height/2, width/2, height/2);
}
