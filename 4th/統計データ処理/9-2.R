data <- read.csv("demodata.csv")

bmi <- data$wt / (data$ht/100)^2 

plot(bmi, data$fat)
print(cor(bmi, data$fat))

plot(data$fat, data$tc)
print(cor(data$fat, data$tc))

plot(data$fat, data$ggt)
print(cor(data$fat, data$ggt))