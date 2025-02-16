def isLeap(y):
    flag = False
    if y % 4 == 0:
        flag = True
        if y % 100 == 0:
            flag = False
            if y % 400 == 0:
                flag = True
    if flag == True:
        return True
    else:
        return False
                
def AverageYear(y):
    sum = 0
    for i in range(1,y):
        if isLeap(i):
            sum += 366
        else:
            sum += 365
            
    return sum/i
    

def main():
    y = input("西暦y年を入力してください: ")
    y = int(y)
    
    print(isLeap(y))
    print("西暦", y ,"年までの1年の平均日数は",round(AverageYear(y), 3))
    

if __name__ == "__main__":
    main()