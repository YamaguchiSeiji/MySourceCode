import random
import time
import matplotlib.pyplot as plt
import numpy as np

# 従来のクイックソート
def quicksort(A):
    if len(A) < 2:
        return A
    p = A[0]
    X, Y = divide(p, A[1:])
    return np.concatenate([quicksort(X), [p], quicksort(Y)])

# 乱択法を用いたクイックソート
def randomized_quicksort(A):
    if len(A) < 2:
        return A
    
    pivot_index = random.randint(0, len(A) - 1)
    
    p = A[pivot_index]
    A[0], A[pivot_index] = A[pivot_index], A[0]
    X, Y = divide(p, A[1:])
    return np.concatenate([randomized_quicksort(X), [p], randomized_quicksort(Y)])

# 分割関数
def divide(p, A):
    A = np.array(A)
    X = A[A < p]
    Y = A[A >= p]
    return X, Y

# main関数
def main():
    
    #実行時間と分散を入れるリスト
    data_num = [[], []] #ave var
    data_num_rand = [[], []] #ave var
    
    
    
    for j in range(1):
        data_time = []
        data_time_rand = []
        for i in range(1):
            random.seed()
            data = np.random.randint(0, 10000, 10000)  #配列の作成
            
            start_time = time.time()
            test = random.randint(0, 99)
            end_time = time.time()
            random_time = end_time - start_time
            
            start_time = time.time()
            quicksort(data.copy())
            end_time = time.time()
            data_time.append(end_time - start_time)
            #print(end_time - start_time)
            
            start_time = time.time()
            randomized_quicksort(data.copy())
            end_time = time.time()
            data_time_rand.append(end_time - start_time - random_time)
            #print(end_time - start_time)
            print(j, i)

        data_num[0].append(np.average(data_time))
        data_num_rand[0].append(np.average(data_time_rand))
        data_num[1].append(np.var(data_time))
        data_num_rand[1].append(np.var(data_time_rand))

    print(data_num[0])
    print(data_num_rand[0])
    print(data_num[1])
    print(data_num_rand[1])
    
    print("改良前平均実行時間: ", np.average(data_num[0]))
    print("改良後平均実行時間: ",np.average(data_num_rand[0]))
    print("改良前実行時間の分散平均: ",np.average(data_num[1]))    
    print("改良後実行時間の分散平均: ",np.average(data_num_rand[1]))
    
    l = len(data_num[0])
    
    #グラフ
    plt.scatter(range(0, l), data_num[1], color="orange", label="Before", s = 10)
    plt.scatter(range(0, l), data_num_rand[1], color="blue", label="After", s = 10)
    plt.xlabel("Run Count")
    plt.ylabel("Variance of Runtime")
    y_max = np.average(data_num[1])*3
    plt.ylim(0, y_max)
    plt.legend()
    plt.show()

if __name__ == "__main__":
    main()
