void setup(){
  size(500,500);
}

void draw(){
  background(255);
  if(mousePressed==true){
    fill(0,255,255);
    rect(200,325,100,100);
  } else {
    fill(255,0,0);
    rect(200,75,100,100);
  }
}

