import math

file1 = "./degree_data.txt"
fileIn = open(file1, "r", encoding = "utf-8")

file2 = "./sin_data.txt"
fileOut = open(file2, "w", encoding = "utf-8")

while True:
    line = fileIn.readline()
    if line:
        d = float(line)
        r = math.radians(d)
        s = math.sin(r)
        aline = line.rstrip()
        fileOut.write(str(d) + "," + str(s) + "\n")
    else:
        break

fileIn.close()
fileOut.close()