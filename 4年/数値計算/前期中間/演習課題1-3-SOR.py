#SOR
import numpy as np
import math
import matplotlib.pyplot as plt

#SOR法を用いた反復計算関数
def SOR(a, b, ans, o):
    n = len(a)
    x = [1] * n
    e = 1.0E-4
    M = 0
    x1 = [1]
    x2 = [1]
    x3 = [1]
    count = 0
    print("初期値:", x)

    while(M != n): #終了条件
        M = 0
        for i in range(n): #行について
            S = 0;
            for j in range(n): #列について
                S += a[i][j] * x[j]
            X = (b[i] - S + a[i][i] * x[i]) / a[i][i]
            X = x[i] + o * (X - x[i])
            if X != 0:
                if abs((X - x[i]) / X) < e:
                    M += 1 #収束判定
            x[i] = X
        x1.append(x[0])
        x2.append(x[1])
        x3.append(x[2])
        count += 1
        print(count,": ", x, sep = '')

    print("反復回数:", count)
    print("解析解の推定値と実測値の誤差率[x1, x2, x3](%): [", end = '')
    for i in range(n):
        print(error(x[i], ans[i]), end = '')
        if i == n-1:
            print("]", sep = '')
        else:
            print(", ", end = '')
    assX = assignment(a, x)
    print("算出した解析解を連立方程式に代入:", assX)
    print("問題の右辺と代入して求めた右辺の誤差率[b1, b2, b3](%): [", end = '')
    for i in range(n):
        print(error(assX[i], b[i]), end = '')
        if i == n-1:
            print("]", sep = '')
        else:
            print(", ", end = '')

#誤差率を求める関数
def error(est, act):
    return round(abs(100 * (est-act) / act), 3)

#連立方程式に解析解を代入する関数
def assignment(a, x):
    n = len(a)
    ans = [0] * n
    for i in range(n):
        for j in range(n):
            ans[i] += a[i][j] * x[j]
    return(ans)

#main関数
def main():
    a = [[2, 1, 1], [0, 2, 1], [1, 1, 1]]
    b = [1, 2, 2]
    ans = [-1, -1, 4]
    SOR(a, b, ans, 1.04)

if __name__ == "__main__":
    main()