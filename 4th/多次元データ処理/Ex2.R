library(rTensor)
#EX2-1
A <- array(0, dim = c(3, 3, 3))
A[1, 1, 1] <- A[2, 2, 1] <- A[3, 3, 1] <- 1
A[2, 1, 2] <- A[3, 2, 2] <- A[1, 3, 2] <- 1
A[3, 1, 3] <- A[1, 2, 3] <- A[2, 3, 3] <- 1
A <- as.tensor((A))

#EX2-3
A_1sum <- modeSum(A, 1, drop=TRUE)
A_2sum <- modeSum(A, 2, drop=TRUE)
A_3sum <- modeSum(A, 3, drop=TRUE)
print(A_1sum)
print(A_2sum)
print(A_3sum)


#EX3-1
A1 <- unfold(A, row_idx = 1, col_idx = c(3, 2))
#EX3-2
A2 <- unfold(A, row_idx = 2, col_idx = c(1, 3))
#EX3-3
A3 <- unfold(A, row_idx = 3, col_idx = c(2, 1))

#4-1
A_1org <- fold(A1, row_idx = 1, col_idx = c(3, 2), modes = c(3, 3, 3))
#4-2
A_2org <- fold(A1, row_idx = 2, col_idx = c(1, 3), modes = c(3, 3, 3))
#4-3
A_3org <- fold(A1, row_idx = 3, col_idx = c(2, 1), modes = c(3, 3, 3))