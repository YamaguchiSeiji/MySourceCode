flag = True
for i in range(1,100):
    for j in range(2,i):
        if i % j == 0:
            flag = False
            break
        else:
            flag = True
    if flag == True:
        print(i)
