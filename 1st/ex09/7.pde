float moguraX, moguraY;
float d;
float rx, ry;
int score;

void setup() {
  size(500, 500);
  moguraX=random(50, 50);
  moguraY=random(50, 50);
  rx=random(2);
  ry=random(2);
}

void draw() {
  background(255);
  fill(255);
  textSize(18);
  ellipse(moguraX, moguraY, 50, 50);
  moguraX+=rx;
  moguraY+=ry;
  if (moguraX<=25||moguraX>=width-25) {
    rx=-rx;
  }
  if (moguraY<=25||moguraY>=height-25) {
    ry=-ry;
  }
  fill(0);
  text("SCORE="+score, 50, 50);
}

void mouseClicked() {
  d=dist(mouseX, mouseY, moguraX, moguraY);
  if (d<=25) {
    moguraX=random(50, 450);
    moguraY=random(50, 450);
    rx=random(2);
    ry=random(2);
    score+=1;
    textSize(25);
    fill(255, 0, 0);
    text("HIT", mouseX, mouseY);
  } else {
    score-=1;
    textSize(25);
    fill(0, 0, 255);
    text("MISS", mouseX, mouseY);
  }
}

