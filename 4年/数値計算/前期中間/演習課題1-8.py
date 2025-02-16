#Approximating functions
import numpy as np
import math
import matplotlib.pyplot as plt
import japanize_matplotlib
import sympy as sym
from sympy.plotting import plot

#グラフの作成
def graph(x, y, n):
    y1 = math.e ** x #e^x
    plt.xlim(-5, 5)
    plt.ylim(-5, 5)
    plt.grid()
    plt.plot(x, y1, label = "e$^{x}$")
    for i in range(n):
        plt.plot(x, y[i], "--", label = str(i) + "次近似")
    plt.legend()
    plt.show()

#main関数
def main():
    a = sym.symbols("a") #aを変数を表す文字として扱う
    fa = math.e ** a #e^a
    x = np.linspace(-5, 5, 100)
    y = []
    S = 0
    n = 10

    for i in range(n):
        S = 0
        for k in range(i+1): #マクローリン展開
            S += ((x ** k) / math.factorial(k)) * sym.diff(fa, a, k).subs(a, 0) 
        y.append(S)

    graph(x, y, n)

if __name__ == "__main__":
    main()