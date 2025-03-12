data <- read.csv("demodata.csv")

mdata <- data[data$sex == "m",]
fdata <- data[data$sex == "f",]

#hist
hist(mdata$ht)
hist(mdata$wt)

hist(fdata$ht)
hist(fdata$wt)


print(summary(mdata$ht))
print(sd(mdata$ht))
print(summary(mdata$wt))
print(sd(mdata$wt))
print('')
print(summary(fdata$ht))
print(sd(fdata$ht))
print(summary(fdata$wt))
print(sd(fdata$wt))
