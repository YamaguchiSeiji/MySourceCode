x <-c(1, 2, 1)
h<-rev(c(2, 0, -2))
conv<-convolve(x,h,type='o')
sprintf(conv,fmt="%.f")
