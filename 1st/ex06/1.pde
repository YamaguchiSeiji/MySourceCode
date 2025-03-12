float redX,redY=200;

void setup(){
  size(400,400);
}

void draw(){
  background(255);
  fill(255,0,0);
  ellipse(redX,redY,20,20);
  redX+=1;
}

