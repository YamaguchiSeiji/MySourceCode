import matplotlib.pyplot as plt

file = "./data_sincos.txt"
fileobj = open(file, "r", encoding = "utf-8")

num = int(input("Input a number (1 or 2): "))

line = fileobj.readline()
aline = line.rstrip()
subject = aline.split(",")

p_deg = []
p_sin = []
p_cos = []
p_x = [[],[]]

while True:
    line = fileobj.readline()
    
    if line:
        aline = line.rstrip()
        score = aline.split(",")
        p_deg.append(int(score[0]))
        p_sin.append(float(score[1]))
        p_cos.append(float(score[2]))
        p_x[num-1].append(float(score[num]))
    else:
        break
    

plt.plot(p_deg, p_x[num], label = subject[num])
plt.legend(loc = "upper right")

plt.xlabel(subject[0])

plt.show()

fileobj.close()