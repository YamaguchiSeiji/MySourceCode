int mode=0;

void setup() {
  size(500, 500);
}

void mouseClicked() {
  mode+=1;
}

void draw() {
  background(255);
  switch(mode) {
  case 0:
    ellipse(250, 250, 100, 100);
    break;
  case 1:
    triangle(200, 300, 250, 200, 300, 300);
    break;
  case 2:
    rect(200, 200, 100, 100);
    break;
  default:
    mode=0;
  }
}

