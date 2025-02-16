#3-6
import numpy as np
import math
import sympy as sym
import matplotlib.pyplot as plt
import japanize_matplotlib

#2次ルンゲクッタ
def RungeKuttaMethod2(x_val, y_val, z_val, h, x_max, f1, f2, x, y, z):
    i = 0
    while(True):
        ky1 = h * f1.subs([(x, x_val[i]), (y, y_val[i]), (z, z_val[i])])
        kz1 = h * f2.subs([(x, x_val[i]), (y, y_val[i]), (z, z_val[i])])
        ky2 = h * f1.subs([(x, x_val[i] + h/2), (y, y_val[i] + ky1/2), (z, z_val[i] + kz1/2)])
        kz2 = h * f2.subs([(x, x_val[i] + h/2), (y, y_val[i] + ky1/2), (z, z_val[i] + kz1/2)])

        if(x_val[i] >= x_max):
            break

        x_val.append(x_val[i] + h)
        y_val.append(y_val[i] + ky2)
        z_val.append(z_val[i] + kz2)

        i += 1

#4次ルンゲクッタ
def RungeKuttaMethod4(x_val, y_val, z_val, h, x_max, f1, f2, x, y, z):
    i = 0
    while(True):
        ky1 = h * f1.subs([(x, x_val[i]), (y, y_val[i]), (z, z_val[i])])
        kz1 = h * f2.subs([(x, x_val[i]), (y, y_val[i]), (z, z_val[i])])
        ky2 = h * f1.subs([(x, x_val[i] + h/2), (y, y_val[i] + ky1/2), (z, z_val[i] + kz1/2)])
        kz2 = h * f2.subs([(x, x_val[i] + h/2), (y, y_val[i] + ky1/2), (z, z_val[i] + kz1/2)])
        ky3 = h * f1.subs([(x, x_val[i] + h/2), (y, y_val[i] + ky2/2), (z, z_val[i] + kz2/2)])
        kz3 = h * f2.subs([(x, x_val[i] + h/2), (y, y_val[i] + ky2/2), (z, z_val[i] + kz2/2)])
        ky4 = h * f1.subs([(x, x_val[i] + h), (y, y_val[i] + ky2), (z, z_val[i] + kz3)])
        kz4 = h * f2.subs([(x, x_val[i] + h), (y, y_val[i] + ky3), (z, z_val[i] + kz3)])
        
        if(x_val[i] >= x_max):
            break

        x_val.append(x_val[i] + h)
        y_val.append(y_val[i] + (1/6) * (ky1 + 2*ky2 + 2*ky3 + ky4))
        z_val.append(z_val[i] + (1/6) * (kz1 + 2*kz2 + 2*kz3 + kz4))
        
        i += 1

def error(est, act): #誤差率を求める関数
    return abs(100 * (est - act) / act)

def main():
    x_val = [[0], [0]]
    y_val = [[1], [1]]
    z_val = [[1], [1]]
    h = 0.5
    x_max = 5
    x_min = 0
    x = sym.symbols("x")
    y = sym.symbols("y")
    z = sym.symbols("z")
    f1 = z
    f2 = sym.exp(x) - y - z
    RungeKuttaMethod2(x_val[0], y_val[0], z_val[0], h, x_max, f1, f2, x, y, z)
    RungeKuttaMethod4(x_val[1], y_val[1], z_val[0], h, x_max, f1, f2, x, y, z)

    #グラフ
    x=sym.symbols('x')
    expr=(2/3) * (sym.exp(-x/2)) * ( sym.cos((sym.sqrt(3)*x)/2) + sym.sqrt(3)*sym.sin((sym.sqrt(3)*x)/2) ) + sym.exp(x)/3
    expr_func=sym.lambdify(x,expr,"numpy")
    px=np.linspace(0,5,100)
    py=expr_func(px)

    plt.plot(px, py, color = "blue", label = '与えられた解析解')
    plt.plot(x_val[0], y_val[0], label = '2次ルンゲクッタ')
    plt.plot(x_val[1], y_val[1], label = '4次ルンゲクッタ')

    plt.xlim(0, 5)
    plt.xlabel("x")
    plt.ylabel("y")
    
    #近似曲線
    plt.legend()
    plt.show()

    #局所誤差
    px = np.linspace(x_min, x_max, int(x_max/h+1))
    py = expr_func(px)
    print("解析解と各アルゴリズムとの局所誤差: ")
    print("  x   | 2次ルンゲクッタ | 4次ルンゲクッタ |")
    print("-------------------------------------------")
    for i in range(len(py)):
        print(f"{px[i]: <5.1f}", end = " | ")
        for j in range(len(y_val)):
            print(f"{error(py[i], y_val[j][i]):<14.6f}", end = "% | ")
        print()

if __name__ == "__main__":
    main()