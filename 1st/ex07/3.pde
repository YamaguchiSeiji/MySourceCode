void setup(){
  size(600,600);
}

void draw(){
  background(255);
  if(mouseY>height-200){
    fill(255,0,0);
    ellipse(mouseX,mouseY,40,40);
  } else {
    if(mouseY<height-200 && mouseY>height-400){
      fill(255,0,255);
      ellipse(mouseX,mouseY,40,40);
    } else {
      fill(0,0,255);
      ellipse(mouseX,mouseY,40,40);
    }
  }
}

