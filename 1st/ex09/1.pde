void setup() {
  size(400, 400);
  background(255);
}

void draw() {
  stroke(0);
  strokeWeight(2);
  line(200, 0, 200, 400);
  if (mousePressed==true) {
    if (mouseX<200) {
      background(255, 0, 0);
    } else {
      background(0, 0, 255);
    }
  }
}

