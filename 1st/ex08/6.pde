float x;
float y;

void setup() {
  size(600, 600);
}

void draw() {
  background(255);
  for (y=100; y<height; y+=75) {
    for (x=100; x<width; x+=100) {
      fill(0, 255, 0);
      triangle(x-50, y, x, y-200, x+50, y);
      fill(160, 90, 0);
      rect(x-15, y, 30, 100);
    }
  }
}

