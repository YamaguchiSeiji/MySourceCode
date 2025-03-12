#Gauss-Seidel
import numpy as np
import math
import matplotlib.pyplot as plt
import japanize_matplotlib

#ガウス・ザイデル法を用いた反復計算関数
def gauss_seidel(a, b, ans):
    n = len(a)
    x = [1] * n
    e = 1.0E-4
    M = 0
    a1 = a.copy()
    b1 = b.copy()

    count = 0

    while(M != n): #終了条件
        M = 0
        for i in range(n): #行について
            S = 0;
            for j in range(n): #列について
                S += a[i][j] * x[j]
            X = (b[i] - S + a[i][i] * x[i]) / a[i][i]
            if X != 0:
                if abs((X - x[i]) / X) < e:
                    M += 1 #収束判定
            x[i] = X
        print(x)
        count += 1

    print("反復回数:", count)
    for i in range(n):
        print("V", str(i+1), ": ", x[i], sep = '')

    print("解析解の推定値と実測値の誤差率[V1～V12](%): [", end = '')
    for i in range(n):
        print(error(x[i], ans[i]), end = '')
        if i == n - 1:
            print("]", sep = '')
        else:
            print(", ", end = '')
    assX = assignment(a1, x)
    print("算出した解析解を連立方程式に代入:", assX)
    print("問題の右辺と代入して求めた右辺の誤差率[V1～V12](%): [", end = '')
    for i in range(n):
        print(error(assX[i], b1[i]), end = '')
        if i == n - 1:
            print("]", sep = '')
        else:
            print(", ", end = '')

#誤差率を求める関数
def error(est, act):
    return round(abs(100 * (est - act) / (act + 1)), 3)

#連立方程式に解析解を代入する関数
def assignment(a, x):
    n = len(a)
    ans = [0] * n
    for i in range(n):
        for j in range(n):
            ans[i] += a[i][j] * x[j]
    return(ans)

#ピボット選択
def pivot_selection(a, b):
    n = len(a)
    for i in range(n):
        for j in range(n):
            if a[j][i] > a[i][i] and i != j:
                tmp = a[i]
                a[i] = a[j]
                a[j] = tmp
                tmp = b[i]
                b[i] = b[j]
                b[j] = tmp

#main関数
def main():
    a = [[-4, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
         [1, -4, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0],
         [0, 1, -4, 0, 0, 1, 0, 0, 0, 0, 0, 0],
         [1, 0, 0, -4, 1, 0, 1, 0, 0, 0, 0, 0],
         [0, 1, 0, 1, -4, 1, 0, 1, 0, 0, 0, 0],
         [0, 0, 1, 0, 1, -4, 0, 0, 1, 0, 0, 0],
         [0, 0, 0, 1, 0, 0, -4, 1, 0, 1, 0, 0],
         [0, 0, 0, 0, 1, 0, 1, -4, 1, 0, 1, 0],
         [0, 0, 0, 0, 0, 1, 0, 1, -4, 0, 0, 1],
         [0, 0, 0, 0, 0, 0, 1, 0, 0, -4, 1, 0],
         [0, 0, 0, 0, 0, 0, 0, 1, 0, 1, -4, 1],
         [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, -4]]
    b = [-100, -100, -100, 0, 0, 0, 0, 0, 0, 100, 100, 100]
    ans = [39.785, 48.387, 39.785, 10.753, 13.978, 10.753, -10.753, -13.978, -10.753, -39.785, -48.387, -39.785]

    gauss_seidel(a, b ,ans)

if __name__ == "__main__":
    main()