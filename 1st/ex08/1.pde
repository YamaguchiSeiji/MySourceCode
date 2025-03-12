float t=100;

void setup(){
  size(600,400);
}

void draw(){
  while(t<width){
    fill(0,255,0);
    triangle(t-50,250,t,50,t+50,250);
    fill(160,90,0);
    rect(t-15,250,30,100);
    t+=100;
  }
}

