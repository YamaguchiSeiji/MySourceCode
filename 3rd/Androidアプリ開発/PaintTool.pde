import android.view.MotionEvent;
import ketai.ui.*;

KetaiGesture gesture;

public boolean surfaceTouchEvent(MotionEvent e) {
  super.surfaceTouchEvent(e);
  return gesture.surfaceTouchEvent(e);
}

PImage ImgPen;
PImage ImgEra;
PImage ImgGomi;
color black = color(0);
color red = color(255, 0, 0);
color green = color(0, 255, 0);
color blue = color(0, 0, 255);
color yellow = color(255, 255, 0);
color purple = color(255, 0, 255);
color cyan = color(0, 255, 255);
void setup() {
  gesture = new KetaiGesture(this);
  ImgPen = loadImage("pen.png");
  ImgEra = loadImage("eraser.png");
  ImgGomi = loadImage("gomi.png");
  imageMode(CENTER);
  background(255);
}

float ButtonPenX = 130, ButtonPenY = 130;
float ButtonEraX = 130, ButtonEraY = 300;
float ButtonResetX = 130, ButtonResetY = 470;
float colorX = 130;
float blackY = 600, redY = 700, greenY = 800, blueY = 900, yellowY = 1000, purpleY = 1100, cyanY = 1200;
color colormode = black;
int mode = 0; //mode: 0 = pen, 1 = eraser, 2 = reset

void draw() {
  fill(255);
  

  if (mode == 0) {
    stroke(colormode);
    strokeWeight(10);
    line(mouseX, mouseY, pmouseX, pmouseY);
    stroke(0);
    strokeWeight(2);
  } else if (mode == 1) {
    stroke(255);
    strokeWeight(20);
    line(mouseX, mouseY, pmouseX, pmouseY);
    strokeWeight(2);
    stroke(0);
  }
  strokeWeight(2);
  if (mode == 0) {
    fill(255, 255, 0);
  } else {
    fill(255);
  }
  ellipse(ButtonPenX, ButtonPenY, 150, 150);
  image(ImgPen, ButtonPenX, ButtonPenY, 75, 75);

  if (mode == 1) {
    fill(255, 255, 0);
  } else {
    fill(255);
  }
  ellipse(ButtonEraX, ButtonEraY, 150, 150);
  image(ImgEra, ButtonEraX, ButtonEraY, 75, 75);

  fill(255, 0, 0);
  ellipse(ButtonResetX, ButtonResetY, 150, 150);
  image(ImgGomi, ButtonResetX, ButtonResetY, 75, 75);

  fill(0);
  ellipse(colorX, blackY, 75, 75);
  fill(red);
  ellipse(colorX, redY, 75, 75);
  fill(green);
  ellipse(colorX, greenY, 75, 75);
  fill(blue);
  ellipse(colorX, blueY, 75, 75);
  fill(yellow);
  ellipse(colorX, yellowY, 75, 75);
  fill(purple);
  ellipse(colorX, purpleY, 75, 75);
  fill(cyan);
  ellipse(colorX, cyanY, 75, 75);
}


void onTap(float x, float y) {
  float ButtonPenD = dist(x, y, ButtonPenX, ButtonPenY);
  float ButtonEraD = dist(x, y, ButtonEraX, ButtonEraY);
  float blackD = dist(x, y, colorX, blackY);
  float redD = dist(x, y, colorX, redY);
  float greenD = dist(x, y, colorX, greenY);
  float blueD = dist(x, y, colorX, blueY);
  float yellowD = dist(x, y, colorX, yellowY);
  float purpleD = dist(x, y, colorX, purpleY);
  float cyanD = dist(x, y, colorX, cyanY);

  if (ButtonPenD <= 75) {
    mode = 0;
  }
  if (ButtonEraD <= 75) {
    mode = 1;
  }

  if (blackD <= 37.5) {
    colormode=black;
    mode = 0;
  }
  if (redD <= 37.5) {
    colormode=red;
    mode = 0;
  }
  if (greenD <= 37.5) {
    colormode=green;
    mode = 0;
  }
  if (blueD <= 37.5) {
    colormode=blue;
    mode = 0;
  }
  if (yellowD <= 37.5) {
    colormode=yellow;
    mode = 0;
  }
  if (purpleD <= 37.5) {
    colormode=purple;
    mode = 0;
  }
  if (cyanD <= 37.5) {
    colormode=cyan;
    mode = 0;
  }
}
void onLongPress(float x, float y) {
  float ButtonResetD = dist(x, y, ButtonResetX, ButtonResetY);
  if (ButtonResetD <= 100) {
    background(255);
  }
}
