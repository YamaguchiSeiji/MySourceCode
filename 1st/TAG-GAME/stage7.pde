void stage7() {

  background(255);
  fill(0);
  rect(100, 100, 700, 400);

  fill(255);
  ellipse(width/2, height/2, 390, 390);
  fill(0);
  ellipse(width/2, height/2, 320, 320);

  strokeWeight(30);
  stroke(255);
  line(width/2, 140, width/2, 460);
  line(290, height/2, 610, height/2);

  strokeWeight(1);
  fill(255);
  ellipse(width/2, height/2, 240, 240);
  fill(0);
  ellipse(width/2, height/2, 160, 160);
}
