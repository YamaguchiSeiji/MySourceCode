data <- read.csv("demodata.csv")

tc <- data$tc
hdlc <- data$hdlc

ai <- (tc - hdlc) / hdlc

hist(ai)
boxplot(ai)