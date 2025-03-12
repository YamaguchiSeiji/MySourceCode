def double_bubble_sort(data):
    n = len(data)
    changeCount = 0
    compareCount = 0
    for i in range(n):
        for j in range(i, n-i-1):
            if data[j] > data[j+1]:
                data[j], data[j+1] = data[j+1], data[j]
                changeCount += 1
            compareCount += 1
        for j in range(n-i-2, i, -1):
            if data[j-1] > data[j]:
                data[j], data[j-1] = data[j-1], data[j]
                changeCount += 1
            compareCount += 1

    print("比較回数：", compareCount)
    print("交換回数：", changeCount)
    return data

data = [5, 1, 3, 2]
print("ソート前：", data)
data = double_bubble_sort(data)
#data = bubble_sort(data)
print("ソート後:", data)
