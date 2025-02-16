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
data_kumamoto = []
data_aso = []
data_amakusa = []

while True:
    line = fobj.readline()
    
    if line:
        aline = line.rstrip()
        data = aline.split(",")
        data_date.append(data[0])
        data_hour.append(data[1])
        data_kumamoto.append(float(data[2]))
        data_aso.append(float(data[3]))
        data_amakusa.append(float(data[4]))
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

plt.plot(range(0,N), data_kumamoto, label = "Kumamoto")
plt.plot(range(0,N), data_aso, color = "orange", label = "Aso")
plt.plot(range(0,N), data_amakusa, color = "green", label = "Aamakusa")
plt.xticks(range(0,N), date, rotation = "vertical")
plt.legend(loc = "lower right")
plt.ylim(-10, 15)
plt.ylabel("Tempereture [Degree Cersius]")

plt.show()

fobj.close()