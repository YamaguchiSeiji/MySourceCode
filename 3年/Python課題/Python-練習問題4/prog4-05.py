file1 = "./data_eng.csv"
file2 = "./data_math.csv"


fileobj1 = open(file1, "r", encoding = "utf_8")
fileobj2 = open(file2, "r", encoding = "utf_8")

fileout = "./data_exam.csv"
fileout2 = open(fileout, "w", encoding = "utf_8")

while True:
    line1 = fileobj1.readline()
    line2 = fileobj2.readline()
    
    if line1:
        aline1 = line1.rstrip()
        aline2 = line2.rstrip()
        fileout2.write(aline1 + "," + aline2 + "\n")
    else:
        break

fileobj1.close()
fileobj2.close()
fileout2.close()