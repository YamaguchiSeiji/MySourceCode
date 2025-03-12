//
// 加速度センサを利用したプログラム例。
//
// 大域変数accX, accY, accZに随時加速度センサ値が代入されるので、
// draw()関数内でそれらの値に沿った直線を描く。
//
import ketai.sensors.*;

KetaiSensor sensor;
float accX, accY, accZ;   // 加速度センサ値3つをいれる変数
float sx, sy;
float mx, my, mxs, mys, md;
float nx, ny, nd, ns = 1;
float ox, oy, od, oxs, oys;
PImage iwa;
PImage mogura;
PImage numa;
PImage oni;
PImage onigashima;
PImage shiba;
float world_time, t;
int score = 0;


void setup() {
  orientation(PORTRAIT); //PORTRAIT=スマホを縦長に固定、LANDSCAPE=横長に固定;
  sensor = new KetaiSensor(this);
  sensor.start();
  strokeWeight(5);
  textSize(36);
  fill(0);
  sx = width/2;
  sy = height/2;
  iwa = loadImage("iwa.png");
  mogura = loadImage("mogura.png");
  numa = loadImage("numa.png");
  oni = loadImage("oni.png");
  onigashima = loadImage("onigashima.png");
  shiba = loadImage("shiba.png");
  imageMode(CENTER);
  textAlign(CENTER);
  textSize(100);
  moguraHit();
}

void draw() {
  image(shiba, width/2, height/2, width, height);
  world_time = millis();
  sx -= accX*4 * ns;
  sy += accY*4 * ns;

  if (sx-100 < 0) {
    sx = 100;
  }
  if (sx+100 > width) {
    sx = width-100;
  }
  if (sy-100 < 0) {
    sy = 100;
  }
  if (sy+100 > height) {
    sy = height-100;
  }

  if (score >= 10) {
    image(numa, nx, ny, 600, 700);
    nd = dist(sx, sy, nx, ny);
    if (nd <= 320) {
      ns = 0.3;
    } else {
      ns = 1;
    }
  }
  if (score >= 30) {
    image(onigashima, width/2, 300, 400, 400);
  }

  

  stroke(0);
  image(iwa, sx, sy, 200, 200);
  image(mogura, mx, my, 200, 200);
  md = dist(mx, my, sx, sy);
  if (md <= 160) {
    score++;
    moguraHit();
  }
  if (score >= 20) {
    mx += mxs;
    my += mys;
    if (mx-100 < 0 || mx+100 > width) {
      mxs = -mxs;
    }
    if (my-100 < 0 || my+100 > height) {
      mys = -mys;
    }
  }
  if (score >= 30) {
    if (world_time - t > 1000) {
      image(oni, ox, oy, 300, 300);
      od = dist(ox, oy, sx, sy);
      ox += oxs;
      oy += oys;
      if (ox-100 < 0 || ox+100 > width) {
        oxs = -oxs;
      }
      if (oy-100 < 0 || oy+100 > height) {
        oys = -oys;
      }
      if (od <= 250) {
        score--;
        moguraHit();
      }
    }
  }

  text("score = " + score, width/2, 100);
}

//--------------------------------
// 加速度センサ値が届いたら随時呼ばれる関数
//
void onAccelerometerEvent(float x, float y, float z) {
  accX = x;
  accY = y;
  accZ = z;
}

void moguraHit() {
  t = world_time;
  mx = random(100, width-100);
  my = random(100, height-100);
  if (score >= 10) {
    nx = random(300, width-300);
    ny = random(350, height-350);
  }
  if (score >= 20) {
    mxs = random(-15, 15);
    mys = random(-15, 15);
  }
  if (score >= 30) {
    oxs = random(-20, 20);
    oys = random(-20, 20);
    ox = width/2;
    oy = 300;
  }
}
