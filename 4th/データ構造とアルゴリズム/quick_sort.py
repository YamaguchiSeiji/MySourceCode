import random
import time
import matplotlib.pyplot as plt
import statistics
import sys

# 従来のクイックソート
def quicksort(A):
    if len(A) < 2:
        return A
    p = A[0]
    X, Y = divide(p, A[1:])
    return quicksort(X) + [p] + quicksort(Y)

# 乱択法を用いたクイックソート
def randomized_quicksort(A):
    if len(A) < 2:
        return A
    pivot_index = random.randint(0, len(A) - 1)
    p = A[pivot_index]
    A[0], A[pivot_index] = A[pivot_index], A[0]
    X, Y = divide(p, A[1:])
    return randomized_quicksort(X) + [p] + randomized_quicksort(Y)

# 分割関数
def divide(p, A):
    if len(A) < 1:
        return ([], [])
    X, Y = divide(p, A[1:])
    a = A[0]
    if a < p:
        return ([a] + X, Y)
    else:
        return (X, [a] + Y)

# メイン関数
def main():
    sys.setrecursionlimit(50000)
    quicksort_data = []
    randomized_quicksort_data = []

    data_quick = []
    data_quick_imp = []


    for j in range(10):
        for i in range(100):
            data = [random.randint(0, 50000) for _ in range(50000)]  # 大きなデータセット

            start_time = time.time()
            quicksort(data.copy())
            end_time = time.time()
            exe_time = end_time - start_time

            quicksort_data.append(exe_time)

            start_time = time.time()
            randomized_quicksort(data.copy())
            end_time = time.time()
            exe_time = end_time - start_time
            randomized_quicksort_data.append(exe_time)
            print(j, i)

        data_quick.append(statistics.pvariance(quicksort_data))
        data_quick_imp.append(statistics.pvariance(randomized_quicksort_data))

    print(data_quick)
    print(data_quick_imp)

    l = len(data_quick)

    plt.plot(range(0,l), data_quick, color = "orange", label="Before")
    plt.plot(range(0,l), data_quick_imp, color = "blue", label="After")
    plt.xlabel("Run Count")
    plt.ylabel("Variance of Run Time")
    plt.legend()

    plt.show()

if __name__ == "__main__":
    main()

