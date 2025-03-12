void setup(){
  size(500,500);
}

void draw(){
  background(255);
  if(mouseX<width/2){
    fill(255,0,0);
  } else {
    fill(0,255,0);
  }
  rect(0,0,width,mouseY);
}

