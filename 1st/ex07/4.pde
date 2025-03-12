void setup(){
  size(500,500);
}

void draw(){
  background(255);
  line(0,0,500,500);
  if(mouseX>mouseY){
    fill(120);
  } else {
    fill(255,150,0);
  }
  rect(mouseX-50,mouseY-50,100,100);

}

