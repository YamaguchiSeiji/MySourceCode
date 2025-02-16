#4-1
import numpy as np
import math
import sympy as sym
import matplotlib.pyplot as plt
import copy

#逆行列による連立1次方程式の解法
def InverseMatrix(a, b, x):
    n = len(a)
    a1 = copy.deepcopy(a)
    C = a1

    unit = np.identity(n) #単位行列の作成

    for i in range(n): #拡大行列の作成
        for j in range(n):
            C[i].append(unit[i, j])

    for k in range(n):
        Ctmp = C[k][k]
        for j in range(2 * n):
            C[k][j] /= Ctmp #正規化
        for i in range(n):
            if i != k:
                Ctmp = C[i][k]
                for j in range(k, 2 * n):
                    C[i][j] = C[i][j] - C[k][j] * Ctmp

    for i in range(n):
        x[i] = 0
        for j in range(n):
            x[i] = round(x[i] + C[i][n+j] * b[j], 2)

#連立方程式に解析解を代入する関数
def assignment(a, x):
    n = len(a)
    ans = [0] * n
    for i in range(n):
        for j in range(n):
            ans[i] += a[i][j] * x[j]
    return(ans)

def main():
    a = [[-4, 1, 1],[1, -4, 0],[1, 0, -4]]
    b = [-80, -400, -400]
    x = [0] * len(a)
    InverseMatrix(a, b, x)

    print("解:", x)
    print("解を式に代入:", assignment(a, x))

if __name__ == "__main__":
    main()