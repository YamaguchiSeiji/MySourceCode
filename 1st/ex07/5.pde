void setup(){
  size(500,300);
}

void draw(){
  background(255);
  line(500,0,0,300);
  if(-mouseX*0.6+300>mouseY){
    fill(120);
  } else {
    fill(255,150,0);
  }
    rect(mouseX-20,mouseY-20,40,40);
}

