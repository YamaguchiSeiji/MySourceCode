import matplotlib.pyplot as plt

file = "./population.txt"
f = open(file, "r", encoding = "utf-8")

line = f.readline()
aline = line.rstrip()
data_p = aline.split(",")
N= len(data_p)

for i in range(0,N):
    if data_p[i] == "熊本市":
        data_kuma = i
    if data_p[i] == "八代市":
        data_yatu = i
    if data_p[i] == "合志市":
        data_kosi = i

y = []
kuma_p = []
yatu_p = []
kosi_p = []

while True:
    line = f.readline()
    if line:
        aline = line.rstrip()
        data_p = aline.split(",")
        y.append(data_p[0])
        kuma_p.append(int(data_p[data_kuma]))
        yatu_p.append(int(data_p[data_yatu]))
        kosi_p.append(int(data_p[data_kosi]))
    else:
        break

plt.plot(y, kuma_p, label = "Kumamoto", marker = "o")
plt.plot(y, yatu_p, label = "Yatsushiro", marker = "^")
plt.plot(y, kosi_p, label = "Koshi", marker = "s")
plt.xlabel("Year")
plt.ylabel("Population")
plt.legend()
plt.show()

kuma_ud = []
yatu_ud = []
kosi_ud = []

n = len(y)

for i in range(0,n):
    kuma_ud.append(kuma_p[i]/kuma_p[0] * 100)
    yatu_ud.append(yatu_p[i]/yatu_p[0] * 100)
    kosi_ud.append(kosi_p[i]/kosi_p[0] * 100)

plt.plot(y, kuma_ud, label = "Kumamoto", marker = "o")
plt.plot(y, yatu_ud, label = "Yatsushiro", marker = "^")
plt.plot(y, kosi_ud, label = "Koshi", marker = "s")
plt.ylim(90,120)
plt.xlabel("Year")
plt.ylabel("Changes of Population [%]")
plt.legend()
plt.show()

f.close()
    