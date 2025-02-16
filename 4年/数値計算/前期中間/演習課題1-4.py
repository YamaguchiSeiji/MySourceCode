#Gauss-Jordan
import numpy as np
import math
import matplotlib.pyplot as plt
import copy

#ガウス・ジョルダン法を用いた反復計算関数
def GaussJordan(a, b, ans):
    n = len(a)
    a1 = copy.deepcopy(a)
    C = a
    x = []
    for i in range(n):
        C[i].append(b[i]) #a,bの拡大係数行列
    x1 = [1]
    x2 = [1]
    x3 = [1]
    count = 0

    for k in range(n):
        for i in range(n):
            if i != k:
                Ctmp = C[i][k] / C[k][k]
                for j in range(k, n+1):
                    C[i][j] = C[i][j] - C[k][j] * Ctmp

    for i in range(n):
        x.append(C[i][n]/C[i][i])

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
    GaussJordan(a, b, ans)

if __name__ == "__main__":
    main()