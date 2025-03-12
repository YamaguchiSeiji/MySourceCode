#6-1
x <- c(1, 0, 0, 0, 3, -1, 0, -1, 3)
A <- array(x, dim=c(3, 3))
z <- eigen(A)
lambda <- z$values
T <- z$vectors
lambda
T

#6-3

A1 <- T %*% diag(lambda) %*% t(T)
A1