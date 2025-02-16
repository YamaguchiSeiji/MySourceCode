file = "./data_eng.csv"
fileobj = open(file, "r", encoding = "utf_8")

file2 = "./data_eng2.csv"
fileobj2 = open(file2, "w", encoding = "utf_8")

while True:
    line = fileobj.readline()
    
    if line:
        fileobj2.write(line)
    else:
        break
    
fileobj.close()
fileobj2.close()