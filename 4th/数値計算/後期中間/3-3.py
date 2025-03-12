#3-3
import numpy as np
import math
import sympy as sym
import matplotlib.pyplot as plt
import japanize_matplotlib

def error(est, act): #誤差率を求める関数
    return abs(100 * (est - act) / act)

def main():
    y_min = 0
    x_min = 0
    x_max = 1
    y_max = 0.25

    x_val = np.linspace(0, 1, 11)
    y_val = [y_min]

    n = 9
    h = (x_max - x_min) / (n+1) * 2

    y = np.array([1]*n, dtype = 'float')

    C = np.zeros((n, n))
    for i in range(0, n):
        for j in range(0, n):
            if i == j:
                C[j, i] = -2.04
            elif i == j - 1:
                C[j, i] = 1
            elif i == j + 1:
                C[j, i] = 1

    unit = np.identity(n)
    b=np.array([0, 0, 0, 0, 0, 0, 0, 0, -0.25])

    C = np.hstack([C, unit])

    #逆行列法
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
        y[i] = 0
        for j in range(n):
            y[i] = y[i] + C[i][n+j] * b[j]
        y_val.append(y[i])

    y_val.append(y_max)

    x = sym.symbols('x')
    expr = (1/4)*( (sym.exp(2*x)-sym.exp(-2*x)) / (sym.exp(2)-sym.exp(-2)) )
    expr_func = sym.lambdify(x, expr, "numpy")
    px=np.linspace(0, 1, 100)
    py=expr_func(px)
    plt.plot(px, py, color = "blue", label = '与えられた解析解')
    plt.plot(x_val, y_val, 'ro--', label = r'得られた結果')

    plt.xlim(x_min, x_max)
    plt.xlabel("x")
    plt.ylabel("y")

    plt.legend()
    plt.show()

    #誤差率
    py = expr_func(x_val)
    print("  x | 誤差率 ")
    print("-------------")
    for i in range(len(py)):
        print(f"{x_val[i]:.1f}", f"{round(error(py[i], y_val[i]), 3):6.3f}", end = "% \n", sep = " | ")

if __name__ == "__main__":
    main()