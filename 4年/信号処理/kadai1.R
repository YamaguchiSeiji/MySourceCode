ck <- function(k, T){
  if(k == 0){
    return(2/T)
  } else {
    return((2/T) * (sin((2*pi*k)/T) / ((2*pi*k)/T)))
  }  
}

T <- 32
k <- c((-T-T/4) : (T+T/4))
y <- sapply(k, function(x) ck(x, T))
plot(k, y, type="o", pch=18, main=paste("矩形波の線スペクトル(T =", T, ")"), xlab="k", ylab="ck", col = "red")
abline(h = 0, col = "black")
abline(v = 0, col = "black")
segments(k, y, k, rep(0, length(k)), col = "blue", lty = 2)