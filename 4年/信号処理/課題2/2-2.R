x <-c(4, 8, 0, -2, 1)
h<-rev(c(0, 5, -2, 3))
conv<-convolve(x,h,type='o')
sprintf(conv,fmt="%.f")
