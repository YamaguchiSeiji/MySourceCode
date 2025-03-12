PImage bird,bird2;

void setup(){
  size(600,600);
  bird=loadImage("data/bird.png");
  if(bird==null) exit();
  bird2=loadImage("data/bird2.png");
  if(bird2==null) exit();
}

void draw(){
  background(255);
  imageMode(CENTER);
  image(bird,200,200,200,200);
  image(bird2,400,400,20
0,200);
}

