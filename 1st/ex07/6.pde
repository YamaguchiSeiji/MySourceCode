void setup(){
  size(500,500);
}

void draw(){
  background(255);
  if(mousePressed==true){
    rect(mouseX,mouseY,20,20);
  }
}

