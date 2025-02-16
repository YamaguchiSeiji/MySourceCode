FileEng = "./data_eng.csv"
FileMath = "./data_math.csv"

FileEngObj = open(FileEng, "r", encoding = "utf_8")
FileMathObj = open(FileMath, "r", encoding = "utf_8")

while True:
    LineEng = FileEngObj.readline()
    LineMath = FileMathObj.readline()
    
    if LineEng:
        ALineEng = LineEng.rstrip()
        ALineMath = LineMath.rstrip()
        print(ALineEng, "," ,ALineMath)
    else:
        break

FileEngObj.close()
FileMathObj.close()