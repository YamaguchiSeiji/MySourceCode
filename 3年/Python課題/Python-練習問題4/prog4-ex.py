import matplotlib.pyplot as plt

file = "data_exam_title.csv"

fileobj = open(file, "r", encoding = "utf-8")

line = fileobj.readline()
num = []
num = line.split(",")

label_x = num[0]
label_y = num[1]

data_x = []
data_y = []

while True:
    line = fileobj.readline()
    
    if line:
        num = line.split(",")
        data_x.append(int(num[0]))
        data_y.append(int(num[1]))
    else:
        break   

data_x.sort()
data_y.sort()
plt.scatter(data_x, data_y)
plt.xlabel(label_x)
plt.ylabel(label_y)
plt.show()

print(label_x, label_y, end = "")
i = 0
N = len(data_x)
while True:
    print(data_x[i], data_y[i], sep = ", ")
    i += 1
    if(i == N):
        break