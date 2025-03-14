#Gauss-Jordan
import numpy as np
import math
import copy

#ガウス・ジョルダン法を用いた反復計算関数
def GaussJordan(a, b, ans):
    n = len(a)
    a1 = copy.deepcopy(a)
    b1 = copy.deepcopy(b)
    C = a
    x = []
    for i in range(n):
        C[i].append(b[i]) #a,bの拡大行列

    x1 = [1]
    x2 = [1]
    x3 = [1]
    count = 0

    pivot_selection(a, b)
    print(C)
    for k in range(n):
        Ctmp = C[k][k]
        for j in range(n+1):
            C[k][j] /= Ctmp #正規化
        for i in range(n):
            if i != k:
                Ctmp = C[i][k]
                for j in range(k, n+1):
                    C[i][j] = C[i][j] - C[k][j] * Ctmp

    for i in range(n):
        x.append(C[i][n])

    print("算出された解析解: ", x)
    print("解析解の推定値と実測値の誤差率[x1, x2, x3](%): [", end = '')
    for i in range(n):
        print(error(x[i], ans[i]), end = '')
        if i == n-1:
            print("]", sep = '')
        else:
            print(", ", end = '')
    assX = assignment(a1, x)
    print("算出した解析解を連立方程式に代入:", assX)
    print("問題の右辺と代入して求めた右辺の誤差率[b1, b2, b3](%): [", end = '')
    for i in range(n):
        print(error(assX[i], b1[i]), end = '')
        if i == n-1:
            print("]", sep = '')
        else:
            print(", ", end = '')

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

 #誤差率を求める関数
def error(est, act):
    return round(abs(100 * (est - act) / act), 3)

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
    a = [[2, 3, 4, 5, 6],[3, 4, 5, 6, 2], [4, 5, 6, 2, 3], [5, 6, 2, 3, 4], [6, 2, 3, 4, 5]]
    b = [70, 60, 55, 55, 60]
    ans = [1, 2, 3, 4, 5]
    GaussJordan(a, b, ans)

if __name__ == "__main__":
    main()