void stage8() {
  background(255);
  fill(0);
  rect(100, 100, 700, 400);
  stroke(255);
  strokeCap(PROJECT);
  strokeWeight(30);

  line(140, 140, 140, 460);
  line(760, 140, 760, 460);

  line(140, 140, 760, 140);
  line(140, 460, 760, 460);

  fill(255);
  ellipse(385, 200, 70, 70);
  ellipse(515, 400, 70, 70);

  strokeCap(ROUND);
  line(140, 220, 220, 460);
  line(140, 300, 300, 460);
  line(140, 380, 380, 460);

  line(520, 140, 760, 220);
  line(600, 140, 760, 300);
  line(680, 140, 760, 380);

  line(140, 140, 460, 460);
  line(440, 140, 760, 460);
  line(140, 140, 760, 460);
  line(440, 140, 460, 460);
}
