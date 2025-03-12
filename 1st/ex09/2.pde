float x;

void setup(){
  size(500,500);
}

void draw(){
  background(255);
  stroke(0);
  fill(255,0,0);
  if(mousePressed==true){
    if(mouseButton==LEFT){
    x-=2;
    } else if(mouseButton==RIGHT){
    x+=2;
    }
  }
   rect(x+225,225,50,50); 
}

