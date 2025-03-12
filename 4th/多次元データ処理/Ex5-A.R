library(rTensor)

A <- array(1:24, dim=c(2, 3, 4))
A <- as.tensor(A)
(A@data)

U1 <- array(1:4, dim=c(2, 2))
U2 <- array(1:9, dim=c(3, 3))
U3 <- array(1:16, dim=c(4, 4))

A1 <- unfold(A, row_idx=1, col_idx=c(2, 3))
A2 <- unfold(A, row_idx=2, col_idx=c(1, 3))
A3 <- unfold(A, row_idx=3, col_idx=c(1, 2))

idx1 <- U1 %*% A1@data
idx2 <- U2 %*% A2@data
idx3 <- U3 %*% A3@data

myA1 <- fold(idx1, row_idx=1, col_idx=c(2, 3), modes=c(2, 3, 4))
myA2 <- fold(idx2, row_idx=2, col_idx=c(1, 3), modes=c(2, 3, 4))
myA3 <- fold(idx3, row_idx=3, col_idx=c(1, 2), modes=c(2, 3, 4))

ansA1 <- ttm(A, U1, m=1)
ansA2 <- ttm(A, U2, m=2)
ansA3 <- ttm(A, U3, m=3)
ansA1
ansA2
ansA3

myA1
myA2
myA3