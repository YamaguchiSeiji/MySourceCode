float x;

void setup(){
  size(600,400);
  background(0);
}

void draw(){
  noStroke();
  for(x=0;x<width;x+=40){
    fill(255);
    rect(x,0,20,frameCount);
    fill(255,0,0);
    rect(x+20,0,20,frameCount);
  }
}

