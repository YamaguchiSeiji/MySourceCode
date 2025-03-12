#Approximating functions
import numpy as np
import math
import matplotlib.pyplot as plt
import japanize_matplotlib
import sympy as sym
from sympy.plotting import plot

def graph(x, y, n):
    y1 = np.log(x + 1)
    plt.xlim(-2, 3)
    plt.ylim(-3, 3)
    plt.grid()
    plt.plot(x, y1, label = "log$_{e}$(1+x)")
    for i in range(0, n):
        plt.plot(x, y[i], "--", label = str(i) + "次近似")
    plt.legend()
    plt.show()

#main関数
def main():
    a = sym.symbols("a") #aを変数を表す文字として扱う
    x = np.linspace(-5, 5, 100)
    y = []
    fx = sym.log(a + 1)
    S = 0
    n = 6

    for i in range(n):
        S = 0
        for k in range(i+1):
            S += ((x ** k) / math.factorial(k)) * sym.diff(fx, a, k).subs(a, 0)
        y.append(S)

    graph(x, y, n)

if __name__ == "__main__":
    main()