PFont font;
int fontSize=24;
int showNum;
int head=0;

String str="テスト";

void setup(){
  size(600,200);
  textAlign(LEFT,TOP);
  showNum=height/fontSize;
}

void draw(){
  background(255);
  fill(0);
  
  for(int i=0;i<showNum; i++){
    if(head+i>=PFont.list().length) break;
    font=createFont(PFont.list()[head+i],fontSize);
    textFont(font);
    text(head+i,0,i*fontSize);
    text(str,100,i*fontSize);
    text(PFont.list()[head+i],200,i*fontSize);
  }
}

void keyPressed(){
  if(key=='x'&&head+showNum<PFont.list().length){
    head+=showNum;
  } else if(key=='z'&&head>=10){
    head-=showNum;
  }
}

