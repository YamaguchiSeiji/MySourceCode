PImage vehicle001;

void setup(){
//background
size(900,600);
background(0,255,255);
noStroke();

vehicle001=loadImage("data/vehicle001.png");
if(vehicle001==null) exit();
}
void draw(){
//mountain
fill(0,150,10);
beginShape();
vertex(0,200);
vertex(300,300);
vertex(600,200);
vertex(900,300);
vertex(900,600);
vertex(0,600);
endShape();
//ground
fill(180,110,10);
rect(0,400,900,200);
//sun
fill(255,210,0);
ellipse(650,125,100,100);
//cloud
fill(255);
ellipse(-10,150,50,50);
ellipse(20,150,50,50);
ellipse(300,150,50,50);
ellipse(330,150,50,50);
ellipse(360,150,50,50);
ellipse(390,150,50,50);
ellipse(630,150,50,50);
ellipse(660,150,50,50);
ellipse(690,150,50,50);
ellipse(720,150,50,50);
//car
imageMode(CENTER);
image(vehicle001,mouseX,365,150,150);
imageMode(CORNERS);
//tree
fill(180,110,10);
rect(-9,300,30,100);
rect(350,300,30,100);
rect(700,300,30,100);
//leef
fill(0,255,0);
triangle(4,150,-36,300,54,300);
triangle(365,150,315,300,415,300);
triangle(715,150,665,300,765,300);
}

