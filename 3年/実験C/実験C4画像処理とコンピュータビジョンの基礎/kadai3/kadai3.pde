PImage inImg, outImg;

void setup() {
  size(1000, 600);
  inImg = loadImage("fukei.png"); 
  imageMode(CENTER);
}

void draw() {
  background(255);
  outImg = createImage(inImg.width, inImg.height, RGB);
  float r = 0, g = 0, b = 0;
  int x=0, y=0;
  for (y = 0; y < inImg.height; y++) {
    for (x = 0; x < inImg.width; x++) {
      r = red(inImg.pixels[y * inImg.width + x]);
      g = green(inImg.pixels[y * inImg.width + x]);
      b = blue(inImg.pixels[y * inImg.width + x]);
      color c = color(r, g-mouseX*255/width, b);
      outImg.pixels[y * inImg.width + x] = c;
    }
  }
  
  

  image(outImg, width/2, height/2, 600, 400);
}
