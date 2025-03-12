#3-4
import numpy as np
import math
import sympy as sym
import matplotlib.pyplot as plt
import japanize_matplotlib

#オイラー法
def EulerMethod(x_val, y_val, h, x_max, f, x, y):
    i = 0
    while(True):
        if(x_val[i] >= x_max):
            break

        y_val.append(y_val[i] + h * f.subs([(x, x_val[i]), (y, y_val[i])]))
        x_val.append(x_val[i] + h)
        
        i += 1

#2次ルンゲクッタ
def RungeKuttaMethod2(x_val, y_val, h, x_max, f, x, y):
    i = 0
    while(True):
        k1 = h * f.subs([(x, x_val[i]), (y, y_val[i])])
        k2 = h * f.subs([(x, x_val[i] + h/2), (y, y_val[i] + k1/2)])

        if(x_val[i] >= x_max):
            break

        y_val.append(y_val[i] + k2)
        x_val.append(x_val[i] + h)

        i += 1

#3次ルンゲクッタ
def RungeKuttaMethod3(x_val, y_val, h, x_max, f, x, y):
    i = 0
    while(True):
        k1 = h * f.subs([(x, x_val[i]), (y, y_val[i])])
        k2 = h * f.subs([(x, x_val[i] + h/2), (y, y_val[i] + k1/2)])
        k3 = h * f.subs([(x, x_val[i] + h), (y, y_val[i] + 2*k2 - k1)])

        if(x_val[i] >= x_max):
            break

        y_val.append(y_val[i] + (k1 + 4*k2 + k3)/6)
        x_val.append(x_val[i] + h)

        i += 1

#4次ルンゲクッタ
def RungeKuttaMethod4(x_val, y_val, h, x_max, f, x, y):
    i = 0
    while(True):
        k1 = h * f.subs([(x, x_val[i]), (y, y_val[i])])
        k2 = h * f.subs([(x, x_val[i] + h/2), (y, y_val[i] + k1/2)])
        k3 = h * f.subs([(x, x_val[i] + h/2), (y, y_val[i] + k2/2)])
        k4 = h * f.subs([(x, x_val[i] + h), (y, y_val[i] + k3)])

        if(x_val[i] >= x_max):
            break

        y_val.append(y_val[i] + (k1 + 2*k2 + 2*k3 + k4)/6)
        x_val.append(x_val[i] + h)

        i += 1

def error(est, act): #誤差率を求める関数
    return abs(100 * (est - act) / act)

def main():
    x_val = [[1], [1], [1], [1]]
    y_val = [[1], [1], [1], [1]]
    h = 0.5
    x_max = 20
    x_min = 1
    x = sym.symbols("x")
    y = sym.symbols("y")
    f = 2 * (y / x)
    EulerMethod(x_val[0], y_val[0], h, x_max, f, x, y)
    RungeKuttaMethod2(x_val[1], y_val[1], h, x_max, f, x, y)
    RungeKuttaMethod3(x_val[2], y_val[2], h, x_max, f, x, y)
    RungeKuttaMethod4(x_val[3], y_val[3], h, x_max, f, x, y)

    #グラフ
    x = sym.symbols('x')
    expr = x**2
    expr_func = sym.lambdify(x, expr, "numpy")
    px = np.linspace(x_min, x_max, 100)
    py = expr_func(px)

    plt.plot(px, py, color = "blue", label = '与えられた解析解')
    plt.plot(x_val[0], y_val[0], label = 'オイラー法')
    plt.plot(x_val[1], y_val[1], label = '2次ルンゲクッタ')
    plt.plot(x_val[2], y_val[2], label = '3次ルンゲクッタ')
    plt.plot(x_val[3], y_val[3], label = '4次ルンゲクッタ')

    plt.xlim(x_min, x_max)    
    plt.xlabel("x")
    plt.ylabel("y")
    
    plt.legend()
    plt.show()

    #局所誤差
    px = np.linspace(x_min, x_max, int(x_max/h-1))
    py = expr_func(px)
    print("解析解と各アルゴリズムとの局所誤差: ")
    print("  x   |    オイラー法   | 2次ルンゲクッタ | 3次ルンゲクッタ | 4次ルンゲクッタ |")
    print("-------------------------------------------------------------------------------")
    for i in range(len(py)):
        print(f"{px[i]: <5.1f}", end = " | ")
        for j in range(len(y_val)):
            print(f"{error(py[i], y_val[j][i]):<14.6f}", end = "% | ")
        print()

if __name__ == "__main__":
    main()