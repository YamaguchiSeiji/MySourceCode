library(rTensor)

A <- array(0, dim=c(3, 3, 3))
A <- as.tensor(A)
(A@data)

A[2, 2, 1] <- 3
A[1, 2, 2] <- 1
A[2, 3, 2] <- 2
A[2, 1, 2] <- 4
A[3, 2, 2] <- 6
A[2, 2, 3] <- 5

U <- array(0, dim=c(3, 3))
U[3, 1] <- U[2, 2] <- U[1, 3] <- 1

ansA1 <- ttm(A, U, m=1)
ansA2 <- ttm(A, U, m=2)
ansA3 <- ttm(A, U, m=3)
ansA1
ansA2
ansA3

A1 <- unfold(A, row_idx=1, col_idx=c(2, 3))
A2 <- unfold(A, row_idx=2, col_idx=c(1, 3))
A3 <- unfold(A, row_idx=3, col_idx=c(1, 2))

idx1 <- U %*% A1@data
idx2 <- U %*% A2@data
idx3 <- U %*% A3@data

myA1 <- fold(idx1, row_idx=1, col_idx=c(2, 3), modes=c(3, 3, 3))
myA2 <- fold(idx2, row_idx=2, col_idx=c(1, 3), modes=c(3, 3, 3))
myA3 <- fold(idx3, row_idx=3, col_idx=c(1, 2), modes=c(3, 3, 3))
myA1
myA2
myA3
