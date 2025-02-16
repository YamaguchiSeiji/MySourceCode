data_kabuka <- read.csv("meiji.csv")

h <- rep(1/3, 3)

#平滑化1~3回
data_conv <- convolve(data_kabuka$owarine, h, type = 'f')
data_conv2 <- convolve(data_conv, h, type = "f")
data_conv3 <- convolve(data_conv2, h, type = "f")

#原波形滑らかさ
len <- length(data_kabuka$owarine)
sum <- 0
for (i in 1:(len-1)) {
  sum <- sum + (data_kabuka$owarine[i] - data_kabuka$owarine[i+1]) ** 2
}
s <- round(sqrt((1/n) * sum))

#平滑波形滑らかさ
len <- length(data_conv)
sum <- 0
for (i in 1:(len-1)) {
  sum <- sum + (data_conv[i] - data_conv[i+1]) ** 2
}
s_conv <- round(sqrt((1/n) * sum))

#グラフ描画
x_limit = c(0, 250)
y_limit = c(3200, 3800)
plot(data_kabuka$owarine, type = 'l', xlim = x_limit, ylim = y_limit, col = 1, xlab = "日数", ylab = "株価(円)")
par(new=T)
plot(data_conv, type = 'l', xlim = x_limit, ylim = y_limit, ann=F, col = 2)
par(new=T)
plot(data_conv2, type = 'l', xlim = x_limit, ylim = y_limit, ann=F, col = 3)
par(new=T)
plot(data_conv3, type = 'l', xlim = x_limit, ylim = y_limit, ann=F, col = 4)
legend("bottomright", legend = c("原波形", "平滑化1回目波形", "平滑化2回目波形", "平滑化3回目波形"), lty=1, col = c(1:5))
title("明治ホールディングス平均株価終値(3点移動平均)")
mtext(text=paste("原波形=", s),line=-1)
mtext(text=paste("平滑波形=", s_conv),line=-2)