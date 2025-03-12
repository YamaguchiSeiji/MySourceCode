data <- read.csv("demodata.csv")
dbp <- data$dbp
sbp <- data$sbp
id <- data$id

bp1 <- id[(dbp < 80) & (sbp < 120)]
bp2 <- id[(dbp < 80) & (sbp < 130)]
bp3 <- id[(dbp < 90) & (sbp < 140)]
bp4 <- id[(dbp < 100) & (sbp < 160)]
bp5 <- id[(dbp < 110) & (sbp < 180)]
bp6 <- id[(110 <= dbp) | (180 <= sbp)]

bp5 <- setdiff(bp5, bp4)
bp4 <- setdiff(bp4, bp3)
bp3 <- setdiff(bp3, bp2)
bp2 <- setdiff(bp2, bp1)

print(length(dbp))
print(length(bp1))
print(length(bp2))
print(length(bp3))
print(length(bp4))
print(length(bp5))
print(length(bp6))
