import matplotlib.pyplot as plt

file = "./Brainwave_14ch_128Hz_AU.txt"
f = open(file, "r", encoding = "utf-8")

line = f.readline()
aline = line.rstrip()
data_name = aline.split(",")

print(data_name)

data = []

n = int(input("Input a number(1~14): "))
data_n = []
data_t = []

while True:
    line = f.readline()
    if line:
        aline = line.rstrip()
        data = aline.split(",")
        data_t.append(float(data[0]))
        data_n.append(float(data[n]))
    else:
        break

plt.plot(data_t, data_n)
plt.xlabel("time")
plt.ylabel(data_name[n])
plt.show()

f.close()