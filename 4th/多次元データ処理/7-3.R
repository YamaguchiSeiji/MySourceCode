library(imager)
library(rTensor)

img <- load.image("mogusi2.png")
plot(img)
A <- t(img[ , , 1, 2])

#num_sv <- 65 #25dB
num_sv <- 130 #30dB
#num_sv <- 240 #40dB
svdA <- svd(A, nu=num_sv, nv=num_sv)
sigma <- svdA$d
U <- svdA$u
V <- svdA$v
recA <- U %*% diag(sigma[1:num_sv]) %*% t(V)
plot(as.cimg(t(recA)))

w <- width(img); h <- height(img); MAX <- 1.0
MSE_G <- fnorm(as.tensor(A-recA))^2 / (h*w)
PSNR_G <- 10*log10(MAX^2/MSE_G)
n <- h; p <- w; r <- num_sv; c_ratio <- 1-(n*r+r*r+p*r) / (n*p)

print(num_sv)
print(PSNR_G)
print(c_ratio)
