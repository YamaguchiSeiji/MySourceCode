#Gauss-Seidel
import numpy as np
import math
import matplotlib.pyplot as plt
import japanize_matplotlib

#ガウス・ザイデル法を用いた反復計算関数
def GaussSeidel(a, b, ans):
    n = len(a)
    x = [1] * n
    e = 1.0E-5
    M = 0
    x1 = [1]
    x2 = [1]
    count = 0
    print("初期値:",x)

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
        x1.append(x[0])
        x2.append(x[1])
        count += 1
        print(count,": ", x, sep = '')

    print("反復回数:", count)
    print("解析解の推定値と実測値の誤差率[x1, x2](%): [", end = '')
    for i in range(n):
        print(error(x[i], ans[i]), end = '')
        if i == n - 1:
            print("]", sep = '')
        else:
            print(", ", end = '')
    assX = assignment(a, x)
    print("算出した解析解を連立方程式に代入:", assX)
    print("問題の右辺と代入して求めた右辺の誤差率[b1, b2](%): [", end = '')
    for i in range(n):
        print(error(assX[i], b[i]), end = '')
        if i == n - 1:
            print("]", sep = '')
        else:
            print(", ", end = '')

    graph(x1, x2, ans)

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

#グラフの作図
def graph(x1, x2, ans):
    x = np.linspace(-5, 5, 100)
    y = -(2 - 3 * x)
    plt.plot(x, y,label="3x$_{1}$ - x$_{2}$ = 2")
    y = (1 - 2 * x) / 4
    plt.plot(x, y, label="2x$_{1}$ + 4x$_{2}$ = 1")

    plt.scatter(x1[1:], x2[1:])
    plt.scatter(x1[0], x2[0], c = "magenta", label = "初期値")
    plt.scatter(ans[0], ans[1], c = "cyan", label = "与えられた解析解")

    plt.title("演習課題1-1")
    plt.xlabel("x$_{1}$")
    plt.ylabel("x$_{2}$")
    plt.legend()
    plt.grid()
    plt.xlim(0, 1.5)
    plt.ylim(-1, 1.5)
    plt.show()

#main関数
def main():
    a = [[3, -1], [2, 4]]
    b = [2, 1]
    ans = [0.643, -0.071]
    GaussSeidel(a, b, ans)

if __name__ == "__main__":
    main()