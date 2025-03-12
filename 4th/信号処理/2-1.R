x <-c(1,-2,0,3)
h<-rev(c(0,2,4,-3))
conv<-convolve(x,h,type='o')
sprintf(conv,fmt="%.f")
