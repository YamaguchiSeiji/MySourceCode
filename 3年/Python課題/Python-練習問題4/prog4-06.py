file = "./data_exam.csv"
fileobj = open(file, "r", encoding = "utf_8")

SumMath = 0
SumEng = 0
i = 0

while True:
    line = fileobj.readline()
    num = []
    if line:
        num = line.split(",")
        SumMath += int(num[0])
        SumEng += int(num[1])
        i += 1
    else:
        break
    
print(round(SumMath/i,2))
print(round(SumEng/i,2))