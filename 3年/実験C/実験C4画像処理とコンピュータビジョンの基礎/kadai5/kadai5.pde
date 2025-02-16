PImage inImg, outImg;

void setup() {
  size(1200, 600, P3D);
  inImg = loadImage("noise+5000.png"); 
  imageMode(CENTER);
}

void draw() {
  background(255);
  outImg = createImage(inImg.width, inImg.height, RGB);
  int x=0, y=0;
  for (y = 0; y < inImg.height; y++) {
    for (x = 0; x < inImg.width; x++) {
      float newR = 0, newG = 0, newB = 0;
      float N = 0;
      for (int b = -1; b <= 1; b++) {
        for (int a = -1; a <= 1; a++) {
          if (x+a > 0 && x+a < inImg.width && y+b > 0 && y+b < inImg.height) {
            newR += red(inImg.pixels[(y+b) * inImg.width + (x+a)]);
            newG += green(inImg.pixels[(y+b) * inImg.width + (x+a)]);
            newB += blue(inImg.pixels[(y+b) * inImg.width + (x+a)]);
            N++;
          }
        }
      }
      
      color c = color(newR/N, newG/N, newB/N);
      outImg.pixels[y * inImg.width + x] = c;
    }
  }
  image(inImg, width/2-300, height/2, 600, 400);
  image(outImg, width/2+300, height/2, 600, 400);
}
