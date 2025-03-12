float x;
float y;

void setup() {
  size(600, 600);
}

void draw() {
  background(255);
  for (y=5; y<165; y+=20) {
    ellipse(mouseX+y, mouseY-y, 10, 10);
  }
}

