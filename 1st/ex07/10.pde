float x,y;
float moveX;

void setup(){
  size(200,400);
  x=10;
  y=height/2;
  moveX=1;
}

void draw(){
  background(255);
  ellipse(x,y,20,20);
  x+=moveX;
  
  if(x>=width-10||x<=10){
    moveX=-moveX;
  }
}

