x <-c(1, 0, 1, 0, 3)
h<-rev(c(0, 2, 3, 1))
conv<-convolve(x,h,type='o')
sprintf(conv,fmt="%.f")
D