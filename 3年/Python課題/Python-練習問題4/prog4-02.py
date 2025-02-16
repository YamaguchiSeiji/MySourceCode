file = "./data_eng.csv"
fileobj = open(file, "r", encoding = "utf_8")

while True:
    line = fileobj.readline()
    
    if line:
        aline = line.rstrip()
        print(aline)
    else:
        break
    
fileobj.close()