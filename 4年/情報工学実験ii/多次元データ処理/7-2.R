num_sv <- 10
svdA2 <- svd(A, nu=num_sv, nv=num_sv)
sigma2 <- svdA2$d
U2 <- svdA2$u
V2 <- svdA2$v
recA2 <- U2 %*% diag(sigma2[1:num_sv]) %*% t(V2)
plot(as.cimg(t(recA2)))

library(rTensor)
w <- width(img); h <- height(img); MAX <- 1.0
MSE_R <- fnorm(as.tensor(A-recA2))^2 / (h*w)
PSNR_R <- 10*log10(MAX^2/MSE_R)
n <- h; p <- w; r <- 10; c_raito <- 1-(n*r+r*r+p*r) / (n*p)