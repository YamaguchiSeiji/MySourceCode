#3-7
import numpy as np
import math
import sympy as sym
import matplotlib.pyplot as plt
import japanize_matplotlib

#オイラー法
def EulerMethod(t_val, i_val, h, t_max, f, t, i):
    j = 0
    while(True):
        if(t_val[j] >= t_max):
            break
        i_val.append(i_val[j] + h * f.subs([(t, t_val[j]), (i, i_val[j])]))
        t_val.append(t_val[j] + h)
        j += 1

#4次ルンゲクッタ
def RungeKuttaMethod4(t_val, i_val, h, t_max, f, t, i):
    j = 0
    while(True):
        k1 = h * f.subs([(t, t_val[j]), (i, i_val[j])])
        k2 = h * f.subs([(t, t_val[j] + h/2), (i, i_val[j] + k1/2)])
        k3 = h * f.subs([(t, t_val[j] + h/2), (i, i_val[j] + k2/2)])
        k4 = h * f.subs([(t, t_val[j] + h), (i, i_val[j] + k3)])

        if(t_val[j] >= t_max):
            break

        i_val.append(i_val[j] + (k1 + 2*k2 + 2*k3 + k4)/6)
        t_val.append(t_val[j] + h)

        j += 1

def error(est, act): #誤差率を求める関数
    return abs(100 * (est - act) / act)

def main():
    E = 100
    R = 15
    r = 10
    L = 500e-3
    t_val = [[0], [0]]
    i_val = [[E/r], [E/r]]
    h = 0.01
    t_max = 0.3
    t_min = 0
    t = sym.symbols("t")
    i = sym.symbols("i")
    f = (E - (R * i)) / L
    EulerMethod(t_val[0], i_val[0], h, t_max, f, t, i)
    RungeKuttaMethod4(t_val[1], i_val[1], h, t_max, f, t, i)

    #グラフ
    at=sym.symbols('at')
    expr=E/R + (E/r - E/R) * sym.exp(-R*at/L)
    expr_func=sym.lambdify(at,expr,"numpy")
    px=np.linspace(t_min,t_max, 100)
    py=expr_func(px)

    plt.plot(px,py,color="blue",label=r'解析解')
    plt.plot(t_val[0],i_val[0],label=r'オイラー法')
    plt.plot(t_val[1],i_val[1],"--",label=r'4次ルンゲクッタ')

    plt.xlabel("t")
    plt.ylabel("i")

    plt.xlim(t_min, t_max)

    plt.legend()
    plt.show()

    #局所誤差
    px = np.linspace(t_min, t_max, int(t_max/h+1))
    py = expr_func(px)
    print("解析解と各アルゴリズムとの局所誤差: ")
    print("  t   |   オイラー法    | 4次ルンゲクッタ |")
    print("-------------------------------------------")
    for i in range(len(py)):
        print(f"{px[i]: <5.2f}", end = " | ")
        for j in range(len(i_val)):
            print(f"{error(py[i], i_val[j][i]):<14.6f}", end = "% | ")
        print()

if __name__ == "__main__":
    main()