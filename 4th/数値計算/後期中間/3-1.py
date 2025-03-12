#3-1
import numpy as np
import math
import sympy as sym
import matplotlib.pyplot as plt
import japanize_matplotlib

def EulerMethod(x_val, y_val, h, x_max, f, x, y):
    i = 0
    while(True):
        y_val.append(y_val[i] + h * f.subs([(x, x_val[i]), (y, y_val[i])]))
        x_val.append(x_val[i] + h)
        if(x_val[i+1] > x_max):
            break;
        i += 1

def error(est, act): #誤差率を求める関数
    return abs(100 * (est - act) / act)

def main():
    x_val = [0]
    y_val = [1]
    h = 0.1
    x_max = 2.5
    x = sym.symbols("x")
    y = sym.symbols("y")
    f = x * y
    EulerMethod(x_val, y_val, h, x_max, f, x, y)

    expr = sym.exp(x**2 / 2)
    expr_func = sym.lambdify(x, expr, "numpy")
    px = np.linspace(0, x_max, 100)
    py = expr_func(px)
    plt.plot(px, py, color = "blue", label = '与えられた解析解')

    #近似曲線
    plt.plot(x_val, y_val, 'r--', label = '得られた結果')
    plt.xlim(0, x_max)
    plt.ylim(0, 25)
    plt.legend(loc = "upper left")

    plt.xlabel("x")
    plt.ylabel("y")

    plt.show()

    #誤差率
    px = np.linspace(0, x_max, int(x_max/h+1))
    py = expr_func(px)
    print("  x | 誤差率 ")
    print("-------------")
    for i in range(len(py)):
        print(f"{px[i]:.1f}", f"{round(error(py[i], y_val[i]), 3):6.3f}", end = "% \n", sep = " | ")
    
    
if __name__ == "__main__":
    main()