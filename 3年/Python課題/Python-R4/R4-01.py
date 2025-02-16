import matplotlib.pyplot as plt

file = "./Brainwave_14ch_128Hz_AU.txt"
f = open(file, "r", encoding = "utf-8")

line = f.readline()
aline = line.rstrip()
data_name = aline.split(",")

print(data_name[1:])

data = []

n = int(input("Input a number(1~14): "))
name = n
data_n = []
data_t = []

print(data_name[name])

while True:
    line = f.readline()
    if line:
        aline = line.rstrip()
        data = aline.split(",")
        data_t.append(float(data[0]))
        data_n.append(float(data[n]))
    else:
        break

y = []
x = 0
n = 5
N = len(data_n)
for i in range(0, N):
    for j in range(-n, n+1):
        if((i + j) < 0) | ((i + j) > N-1):
            flag = True
            break
        else:
            flag = False
    
        x += data_n[i + j]
    
    if flag == True:
        y.append(data_n[i])
    else:
        y.append(x/(2*n+1))
    x = 0
    


plt.plot(data_t, data_n, label = "Original Wave")
plt.plot(data_t, y, color = "orange", label = "Moving Average")
plt.xlabel("time")
plt.ylabel(data_name[name])
plt.legend(loc = "upper right")
plt.show()

f.close()