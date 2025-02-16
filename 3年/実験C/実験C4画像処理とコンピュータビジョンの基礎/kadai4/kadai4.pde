PImage inImg, outImg;

void setup() {
  size(1200, 600);
  inImg = loadImage("fukei.png"); 
  imageMode(CENTER);
}

void draw() {
  background(255);
  outImg = createImage(inImg.width, inImg.height, RGB);
  float r = 0, g = 0, b = 0;
  float l = 0;
  int x=0, y=0;
  for (y = 0; y < inImg.height; y++) {
    for (x = 0; x < inImg.width; x++) {
      r = red(inImg.pixels[y * inImg.width + x]);
      g = green(inImg.pixels[y * inImg.width + x]);
      b = blue(inImg.pixels[y * inImg.width + x]);
      l = 0.2126 * r + 0.7152 * g + 0.0722 * b;
      if(l > mouseX*255/width){
        outImg.pixels[y * inImg.width + x] = color(255);
      } else {
        outImg.pixels[y * inImg.width + x] = color(0);
      }
    }
  }
  image(inImg, width/2-300, height/2, 600, 400);
  image(outImg, width/2+300, height/2, 600, 400);
}
