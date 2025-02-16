import matplotlib.pyplot as plt

file = "./sin_data.txt"
fileobj = open(file, "r", encoding = "utf-8")

x = []
y = []
linedata = []

while True:
    line = fileobj.readline()
    
    if line:
        linedata = line.split(",")
        x.append(float(linedata[0]))
        y.append(float(linedata[1]))
    else:
        break

N = len(y)
plt.plot(x, y)
plt.show()