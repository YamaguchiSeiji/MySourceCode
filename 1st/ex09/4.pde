float b=10;

void setup() {
  size(500, 500);
}

void draw() {
  background(255);
  if (mousePressed==true) {
    b+=1;
  }
  ellipse(250, 250, b, b);
}

