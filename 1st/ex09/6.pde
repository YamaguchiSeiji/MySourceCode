float startX, startY;
float endX, endY;
float a;

void setup() {
  size(500, 500);
}

void mousePressed() {
  startX=mouseX;
  startY=mouseY;
}

void mouseReleased() {
  endX=mouseX;
  endY=mouseY;
}

void draw() {
  background(255);
  if (mousePressed==false) {
    startY-=1;
    endY-=1;
  }
  line(startX, startY, endX, endY);
}

