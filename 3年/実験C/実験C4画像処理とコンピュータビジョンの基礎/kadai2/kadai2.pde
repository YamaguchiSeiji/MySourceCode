PImage inImg; // 入力画像
PImage outImg0, outImg1, outImg2; // 出力画像

// 初期設定
void setup() {
  size (600, 600, P3D);
  // 元画像を読み込む
  inImg = loadImage("test.png");
  textFont(createFont("Century", 30));
  textAlign(LEFT, TOP);
}
// メインルーチン
void draw() {
  int x = 0, y = 0;
  int p1, p2;
  background(0);
  // 左右反転した画像 outImg を作る
  outImg0 = createImage(inImg.width, inImg.height, RGB);
  outImg1 = createImage(inImg.width, inImg.height, RGB);
  outImg2 = createImage(inImg.width, inImg.height, RGB);
  for (y = 0; y < inImg.height; y++) {
    for (x = 0; x < inImg.width; x++) {
      p1 = y * inImg.width + x;
      p2 = y * inImg.width + (inImg.width - 1 - x);
      outImg0.pixels[p1] = inImg.pixels[p2]; //入力画像の画素 p2 を出力画像の画素 p1 に配置
    }
  }

  for (y = 0; y < inImg.height; y++) {
    for (x = 0; x < inImg.width; x++) {
      p1 = y * inImg.width + x;
      p2 = (inImg.height - y - 1) * inImg.width + x;
      outImg1.pixels[p1] = inImg.pixels[p2]; //入力画像の画素 p2 を出力画像の画素 p1 に配置
    }
  }
  
  for (y = 0; y < inImg.height; y++) {
    for (x = 0; x < inImg.width; x++) {
      p1 = y * outImg1.width + x;
      p2 = y * outImg1.width + (outImg1.width - 1 - x);
      outImg2.pixels[p1] = outImg1.pixels[p2]; //入力画像の画素 p2 を出力画像の画素 p1 に配置
    }
  }

  // 画像を表示する
  image(inImg, 0, 0, 300, 300);
  image(outImg0, 300, 0, 300, 300);
  image(outImg1, 0, 300, 300, 300);
  image(outImg2, 300, 300, 300, 300);
}
