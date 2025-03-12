def double_insertion_sort(data):
    print("-----ソート過程-----")
    changeCount = 0 #交換回数のカウント
    compareCount = 0 #比較回数のカウント
    count = 1
    n = len(data)
    m = int(n/2)
    print(count, ":", data)
    if data[m] < data[m-1]:
        data[m],data[m-1] = data[m-1],data[m]
        changeCount += 1
    count+=1
    print(count, ":", data)

    for i in range(1, m):
        if data[m+i] < data[m-i-1]:
            data[m+i],data[m-i-1] = data[m-i-1],data[m+i]
            changeCount += 1
        count+=1
        print(count, ":", data)

        insertion_sort(data, m-i, m+i, changeCount, compareCount)
        count+=1
        changeCount += 1
        print(count, ":", data)

        insertion_sort(data, m-i, m+i+1, changeCount, compareCount)
        count+=1
        changeCount += 1
        print(count, ":", data)

    print("--------------------")
    return data

def insertion_sort(data, a, b, changeCount, compareCount):
    for i in range(a, b):
        tmp = data[i]
        j = i - 1

        while j >= 0 and tmp < data[j]:
            data[j + 1] = data[j]
            j -= 1

        data[j + 1] = tmp

    return data

def main():
    data = [2,8,3,4,7,6,1,5]
    print("データ数:", len(data))
    print("ソート前:", data)
    print("ソート後:", double_insertion_sort(data))

if __name__ == "__main__":
    main()
