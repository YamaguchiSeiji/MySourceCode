float x,y;
float moveY;

void setup(){
  size(400,200);
  x=width/2;
  y=0;
  moveY=1;
}

void draw(){
  background(255);
  ellipse(x,y,20,20);
  y+=moveY;
  
  if(y>=height||y<=0){
    moveY=-moveY;
  }
}

