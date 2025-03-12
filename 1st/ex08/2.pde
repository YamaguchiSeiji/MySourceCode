float t;

void setup(){
  size(600,400);
}

void draw(){
  for(t=100; t<width; t+=100){
    fill(0,255,0);
    triangle(t-50,250,t,50,t+50,250);
    fill(160,90,0);
    rect(t-15,250,30,100);
  }
}

