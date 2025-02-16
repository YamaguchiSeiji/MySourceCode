file = "./data_eng.csv"
fileobj = open(file,"r",encoding="utf_8")
text = fileobj.read()
print(text)
fileobj.close()