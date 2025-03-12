
float[] BallX, BallY;
float[] BallX_Speed, BallY_Speed;
int n=30;
float Ball_Speed=1.5;

void stage4() {
  background(255);
  fill(0);
  rect(100, 100, 700, 400);

  strokeWeight(30);
  strokeCap(PROJECT);
  stroke(255);
  line(140, 140, 140, 460);
  line(140, 140, 760, 140);
  line(760, 140, 760, 460);
  line(140, 460, 760, 460);

  fill(255);
  noStroke();
  for (int i=0; i<n; i++) {
    ellipse(BallX[i], BallY[i], 70, 70);
    BallX[i]+=BallX_Speed[i];
    BallY[i]+=BallY_Speed[i];
    if (BallX[i]>=756||BallX[i]<=158) {
      BallX_Speed[i]=-BallX_Speed[i];
    }
    if (BallY[i]>=456||BallY[i]<=158) {
      BallY_Speed[i]=-BallY_Speed[i];
    }
  }
}
