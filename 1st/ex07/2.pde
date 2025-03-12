void setup() {
  size(500, 500);
}

void draw() {
  background(255);
  if (mouseX<width/2) {
    fill(255, 0, 0);
    rect(mouseX-75, mouseY-50, 150, 100);
  } else {
    fill(0, 255, 0);
    triangle(mouseX, mouseY-50, mouseX-75, mouseY+50, mouseX+75, mouseY+50);
  }
}

