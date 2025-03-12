PImage bird;

void setup(){
  size(600,600);
  bird=loadImage("data/bird.png");
  if(bird==null) exit();
}

void draw(){
  background(255,0,0);
  imageMode(CENTER);
  image(bird,300,300);
}

