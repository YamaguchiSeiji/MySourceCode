x <- c(1,0,1,0,0,0,0,0)
x <- c(0,0,0,0,0,0,0,sqrt(2))

fft <- fft(x)

re <- Re(fft)
im <- Im(fft)

plot(0:(length(x)-1), re, ylim = c(-2, 2), xlab = ("x"), ylab = ("re(y)"), type = "h", main = "FFT waveform")
points(0:(length(x)-1), re, pch=16)
abline(h=0, lty=2)

plot(0:(length(x)-1), im, ylim = c(-2, 2), xlab = ("x"), ylab = ("im(y)"), type = "h", main = "FFT waveform")
points(0:(length(x)-1), im, pch=16)
abline(h=0, lty=2)