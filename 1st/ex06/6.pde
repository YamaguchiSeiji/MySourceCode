float redX,redY=200;
float blueX,blueY=200;
float purpleX,purpleY=200;
float greenX,greenY;
float yellowX=200,yellowY;
float skyX=400,skyY=200;

void setup(){
  size(400,400);
}

void draw(){
  background(255);
  fill(255,0,0);
  ellipse(redX,redY,20,20);
  redX+=1;
  fill(0,0,255);
  ellipse(blueX,blueY,20,20);
  blueX+=2;
  fill(255,0,255);
  ellipse(purpleX,purpleY,20,20);
  purpleX+=3;
  fill(0,255,0);
  ellipse(greenX,greenY,20,20);
  greenX+=1;
  greenY+=1;
  fill(255,255,0);
  ellipse(yellowX,yellowY,20,20);
  yellowY+=1;
  fill(0,255,255);
  ellipse(skyX,skyY,20,20);
  skyX-=1;
}

