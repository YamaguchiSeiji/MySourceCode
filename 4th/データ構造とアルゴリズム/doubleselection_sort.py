data = [8, 4, 3, 9, 6, 5]
n = int(len(data)/2)
m = int(len(data))
print("ソート前：", data)
changeCount = 0
compareCount = 0
for i in range(n):
    for j in range(i, n):
        compareCount += 1
        if data[j] > data[n + j - i]:
            data[j], data[n + j - i] = data[n + j -i], data[j]
            changeCount += 1

    min = i
    max = m - i - 1
    for j in range(i, n):
        compareCount += 1
        if data[j] < data[min]:
            min = j
            data[min] = data[j]
        if data[n + j - i] > data[max]:
            max = n + j -i
            data[max] = data[n + j - i]

    if i != min:
        data[i], data[min] = data[min], data[i]
        changeCount += 1
    if (m-i-1) != max:
        data[m-i-1], data[max] = data[max], data[m-i-1]
        changeCount += 1

print("ソート後：", data)
print("比較回数：", compareCount)
print("交換回数：", changeCount)
