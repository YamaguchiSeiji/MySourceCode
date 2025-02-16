data <- read.csv("demodata.csv")

sbpclass=cut(data$sbp, breaks=c(120,130,140,160,180), right=F)
dbpclass=cut(data$dbp,breaks=c(0,80,85,90,100,110,Inf),right=F)

print(table(sbpclass, dbpclass))
print(table(data$sex, sbpclass))
print(table(data$sex, dbpclass))