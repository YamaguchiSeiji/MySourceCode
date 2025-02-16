import matplotlib.pyplot as plt

file = "./Temperature2022.txt"
fobj = open(file, "r", encoding = "utf-8")

data_name = []

line = fobj.readline()
aline = line.rstrip()
data_name = aline.split(",")

data = []
data_date = []
data_hour = []
data_place = [[], [], []] #Kumamoto Aso Amakusa
place = ["Kumamoto", "Aso", "Amakusa"]

while True:
    line = fobj.readline()
    
    if line:
        aline = line.rstrip()
        data = aline.split(",")
        data_date.append(data[0])
        data_hour.append(data[1])
        data_place[0].append(float(data[2]))
        data_place[1].append(float(data[3]))
        data_place[2].append(float(data[4]))
    else:
        break

N = len(data_date)

date = []
date.append(data_date[0])
for i in range(1, N):
    if data_date[i] == data_date[i-1]:
        date.append("")
    else:
        date.append(data_date[i])

num = int(input("地域を番号で入力："))
plt.plot(range(0,N), data_place[num], label = place[num])

plt.xticks(range(0,N), date, rotation = "vertical")
plt.legend(loc = "lower right")
plt.ylim(-10, 15)
plt.ylabel("Tempereture [Degree Cersius]")

plt.show()

fobj.close()