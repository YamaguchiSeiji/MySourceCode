#6-2
x <- c(1, 1, 2, 2, 2, -1, 0, -1)
B <- array(x, dim=c(4, 2))
z <- svd(B)
sigma <- z$d
U <- z$u
V <- z$v
sigma
V
U

#6-4
B1 <- U %*% diag(sigma) %*% t(V)
B1