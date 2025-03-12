void setup(){
  size(600,600);
}
 
void draw(){
  beginShape();
  vertex(50,350);
  vertex(150,250);
  vertex(400,250);
  vertex(450,200);
  vertex(550,200);
  vertex(500,350);
  endShape(CLOSE);
  
  rect(250,315,150,30);
  
  triangle(150,250,100,300,150,300);
  
  rect(200,290,15,15,5);
  rect(220,290,15,15,5);
  rect(240,290,15,15,5);
  rect(260,290,15,15,5);
  rect(280,290,15,15,5);
  rect(300,290,15,15,5);
  rect(320,290,15,15,5);
  rect(340,290,15,15,5);
  rect(360,290,15,15,5);
  rect(380,290,15,15,5);
}

