data <- read.csv("minidata.csv")
ht <- data$ht
sex <- data$sex

print(data[ht < 150,])

print(data[ht >= 150 & ht < 170,])

print(data[ht >= 150 & ht < 170 & sex == 'f',])