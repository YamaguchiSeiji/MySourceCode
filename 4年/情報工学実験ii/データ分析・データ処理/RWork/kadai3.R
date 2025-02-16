kadai3 <- function(){
library(imager)

img1 <- load.image("imgs/53.png")
img1 <- mirror(img1, "y")
dev.new()
plot(img1)

img2 <- load.image("imgs/36.png")
dev.new()
img2 <- isoblur(img2, 30) %>% plot(main="Isotropic blur, sigma=")

img3 <- load.image("imgs/37.png")
img3 <- deriche(img3, 10, order=0, axis="x")
dev.new()
plot(img3)
}