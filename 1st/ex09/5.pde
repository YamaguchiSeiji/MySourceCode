float b=250;

void setup() {
  size(500, 500);
}

void draw() {
  background(255);
  if (mousePressed==true) {
    b+=1;
  } else if (mousePressed==false) {
    b-=1;
  }
  ellipse(250, b, 100, 100);
}

