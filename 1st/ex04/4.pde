PImage vehicle001;
float x;

void setup(){
//background
size(1900,600);

//noStroke();

vehicle001=loadImage("data/vehicle001.png");
if(vehicle001==null) exit();
}
void draw(){
background(0,255,255);
//mountain
for(x=0;x<=2100;x+=600){
  fill(0,150,10);
  beginShape();
  vertex(x-mouseX/20,300);
  vertex(x+300-mouseX/20,200);
  vertex(x+600-mouseX/20,300);
  vertex(x+600-mouseX/20,600);
  vertex(x-1200-mouseX/20,600);
  endShape();
  }
//ground
fill(180,110,10);
rect(0,400,1900,200);
//sun
noStroke();
fill(255,210,0);
ellipse(650,125,100,100);
//cloud
fill(255);
for(x=0;x<=1900;x+=300){
  ellipse(x-80,150,50,50);
  ellipse(x-50,150,50,50);
  ellipse(x-20,150,50,50);
  ellipse(x+10,150,50,50);
}
stroke(0);
//tree2&&leaf2
for(x=0;x<=3800;x+=100){
  fill(180,110,10);
  rect(x-mouseX/2,334,20,66);
  fill(0,255,0);
  triangle(x+10-mouseX/2,230,x-15-mouseX/2,334,x+35-mouseX/2,334);
}
//car
imageMode(CENTER);
image(vehicle001,mouseX,365,150,150);
//tree&&leaf
for(x=0;x<=3800;x+=200){
  fill(180,110,10);
  rect(x-mouseX,300,30,100);
  fill(0,255,0);
  triangle(x+15-mouseX,150,x-35-mouseX,300,x+65-mouseX,300);
}
}

