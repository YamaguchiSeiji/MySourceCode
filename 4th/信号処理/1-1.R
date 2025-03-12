x <-c(2, 2, 1)
h<-rev(c(1, 2))
conv<-convolve(x,h,type='o')
sprintf(conv,fmt="%.f")
