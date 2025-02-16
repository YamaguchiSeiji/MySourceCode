import processing.video.*; // カメラを表す変数
Capture cam;
float Rt = 255, Gt = 0, Bt = 0;
PImage egg, hiyoko, niwatori, chicken;
float size = 0;

void setup() {
  size(640, 480);
  String[] settings = Capture.list(); // 設定リストを取得
  if (settings.length == 0) {
    println("There are no cameras available for capture.");
    exit();
  }
  cam = new Capture(this, settings[1]); // 0 番目の設定を有効化
  cam.start(); // 撮影開始
  printArray(settings);
  
  egg = loadImage("egg.png");
  hiyoko = loadImage("hiyoko.png");
  niwatori = loadImage("niwatori.png");
  chicken = loadImage("chicken.png");
  
  imageMode(CENTER);
}

void draw() {
  if (cam.available() == true) cam.read(); // 現在のカメラ画像を取得
  image(cam, width/2, height/2);
  noFill();
  int x, y, p1;
  float xmin = width, xmax = 0, ymin =height, ymax = 0;
  for (y = 0; y<cam.height; y++) {
    for (x = 0; x<cam.width; x++) {
      p1 = y * cam.width + x; 
      float r = red(cam.pixels[p1]);
      float g = green(cam.pixels[p1]);
      float b = blue(cam.pixels[p1]);
      float diff = sqrt(pow(Rt-r, 2) + pow(Gt-g, 2) + pow(Bt-b, 2));
      if (diff <= 30) {
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
        size = xmax-xmin;
      }
    }
  }
  stroke(255, 255, 0);
  strokeWeight(5);
  float cx = (xmax+xmin)/2;
  float cy = (ymax+ymin)/2;

  if (size <= 100){
    image(egg, cx, cy, size, size);
  } else if(size <= 150){
    image(hiyoko, cx, cy, size*0.8, size);
  } else if(size <= 200){
    image(niwatori, cx, cy, size, size);
  } else {
    image(chicken, cx, cy, size, size);
  }
  size = 0;
}

void mousePressed() {
  loadPixels();
  int i = mouseY * width + mouseX;
  Rt = red(pixels[i]);
  Gt = green(pixels[i]);
  Bt = blue(pixels[i]);
}
