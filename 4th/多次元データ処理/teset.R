library(rTensor)
A1 <- array(0, dim = c(4, 4, 4))
A2 <- array(0, dim = c(4, 4, 4))
A3 <- array(0, dim = c(4, 4, 4))
A4 <- array(0, dim = c(4, 4, 4))

x1 <- c(2,5,12,15,17,22,27,32,36,39,42,45,51,56,57,62)
x2 <- c(1,6,12,15,20,23,26,29,34,37,43,48,51,56,57,62)
x3 <- c(1,7,10,16,19,24,25,30,34,37,44,47,52,54,59,61)
x4 <- c(1,8,11,14,20,23,26,29,35,38,41,48,50,53,60,63)

for(i in 1:4){
  for(j in 1:4){
    for(k in 1:4){
      sum = k + (j-1)*4 + (i-1)*16
      if(sum %in% x1){
        A1[k, j, i] <- 1
      }
      if(sum %in% x2){
        A2[k, j, i] <- 1
      }
      if(sum %in% x3){
        A3[k, j, i] <- 1
      }
      if(sum %in% x4){
        A4[k, j, i] <- 1
      }
    }
  }
}

A1 <- as.tensor((A1))
A2 <- as.tensor((A2))
A3 <- as.tensor((A3))
A4 <- as.tensor((A4))

print("A1:")
print(modeSum(A1, 1, drop=TRUE))
print(modeSum(A1, 2, drop=TRUE))
print(modeSum(A1, 3, drop=TRUE))

print("A2:")
print(modeSum(A2, 1, drop=TRUE))
print(modeSum(A2, 2, drop=TRUE))
print(modeSum(A2, 3, drop=TRUE))

print("A3:")
print(modeSum(A3, 1, drop=TRUE))
print(modeSum(A3, 2, drop=TRUE))
print(modeSum(A3, 3, drop=TRUE))

print("A4:")
print(modeSum(A4, 1, drop=TRUE))
print(modeSum(A4, 2, drop=TRUE))
print(modeSum(A4, 3, drop=TRUE))