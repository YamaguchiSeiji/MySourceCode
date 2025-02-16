library(imager)
img <- load.image("parrots.png")
plot(img)
A <- t(img[ , , 1, 1])

plot(as.cimg(t(A)))
svdA <- svd(A)
sigma <- svdA$d
U <- svdA$u
V <- svdA$v
recA <- U %*% diag(sigma) %*% t(V)
plot(as.cimg(t(recA)))