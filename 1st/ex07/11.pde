float x,y;
float moveX,moveY;

void setup(){
  size(1500,800);
  x=20;y=20;
  moveX=10;moveY=10;
}

void draw(){
 background(255);
 ellipse(x,y,40,40);
 x+=moveX;
 y+=moveY;

 if(y>=height-20||y<=20){
   moveY=-moveY;
   fill(255,0,0);
 }
 if(x>=width-20||x<=20){
   moveX=-moveX;
   fill(0,0,255);
 }
}

