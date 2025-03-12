float x;
float y;
float a;

void setup() {
  size(1000, 600);
}

void draw() {
  background(255);
  for (a=0; a<width; a+=100) {
    for (x=100+a/3, y=100+a*1.5; x<width+100; x+=90) {
      fill(0, 255, 0);
      triangle(x-50, y, x, y-200, x+50, y);
      fill(160, 90, 0);
      rect(x-10, y, 20, 100);
    }
  }
}

