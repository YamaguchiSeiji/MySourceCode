x <-c(4, -5, 0, 6)
h<-rev(c(2, 4, 6))
conv<-convolve(x,h,type='o')
sprintf(conv,fmt="%.f")
