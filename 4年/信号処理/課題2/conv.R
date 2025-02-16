conv<-function(x,h){
  hr<-rev(h)
  m<-length(x); n<-length(h); p<-m+n-1
  y<-convolve(x,hr,type="o")
  ym<-max(y)+1
  par(mfrow=c(3,1))
  t<-0:(p-1)
  plot(t,append(x,rep(0,p-m)),type="h",col="blue",ylim=c(0,ym),lwd=3,ylab="x",xaxt="n")
  axis(side=1,at=c(seq(from=0,to=p-1,by=1)))
  abline(h=0)
  plot(t,append(h,rep(0,p-n)),type="h",lwd=3,col="red",ylim=c(0,ym),ylab="h",xaxt="n")
  axis(side=1,at=c(seq(from=0,to=p-1,by=1)))
  abline(h=0)
  plot(t,y,type="h",lwd=3,col="purple",ylim=c(0,ym),ylab="y",xaxt="n")
  axis(side=1,at=c(seq(from=0,to=p-1,by=1)))
  abline(h=0)
}