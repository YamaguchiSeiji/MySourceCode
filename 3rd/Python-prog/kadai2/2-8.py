YEAR = 10000
y = 0

for i in range(1,YEAR+1):
    flag = False
    y = y + 365
    if i % 4 == 0:
        flag = True
        if i % 100 == 0:
            flag = False
            if i % 400 == 0:
                flag = True

    if flag == True:
        y = y + 1

print(y/YEAR)
