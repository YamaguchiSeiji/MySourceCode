#Inverse Matrix
import numpy as np
import math
import copy

#逆行列による連立1次方程式の解法
def InverseMatrix(a, b, ans):
    n = len(a)
    a1 = copy.deepcopy(a)
    b1 = copy.deepcopy(b)
    C = a
    x = [0] * n

    unit = np.identity(n) #単位行列の作成

    for i in range(n): #拡大行列の作成
        for j in range(n):
            C[i].append(unit[i, j])
    print("計算前：",C)
    x1 = [1]
    x2 = [1]
    x3 = [1]
    count = 0

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
            x[i] = x[i] + C[i][n+j] * b[j]
    print("計算後：", C)
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
    a = [[1, 2, 1],[4, 5, 6], [7, 8, 9]]
    b = [4, 2, 2]
    ans = [-3, 4, -1]
    InverseMatrix(a, b, ans)

if __name__ == "__main__":
    main()