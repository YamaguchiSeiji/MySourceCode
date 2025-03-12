def insertion_sort(arr, a, b):
    for i in range(1, len(arr)):
        tmp = arr[i]
        j = i - 1

        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = tmp

    return arr

# 使用例
arr = [6, 5, 7, 3, 8, 2, 4, 9]
sorted_arr = insertion_sort(arr, a, b)
print("Sorted array is:", sorted_arr)

