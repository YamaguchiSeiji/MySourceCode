#3-2
import numpy as np
import math
import sympy as sym
import matplotlib.pyplot as plt
import japanize_matplotlib

#オイラー法
def EulerMethod(x_val, y_val, z_val, h, x_max, f1, f2, x, y, z):
    i = 0
    while(True):
        y_val.append(y_val[i] + h * f1.subs([(x, x_val[i]), (y, y_val[i]), (z, z_val[i])]))
        z_val.append(z_val[i] + h * f2.subs([(x, x_val[i]), (y, y_val[i]), (z, z_val[i])]))
        x_val.append(x_val[i] + h)
        if(x_val[i+1] > x_max):
            break;
        i += 1

def error(est, act): #誤差率を求める関数
    return abs(100 * (est - act) / act)

def main():
    x_val = [0]
    y_val = [1]
    z_val = [1]
    h = 0.4
    x_max = 6
    x = sym.symbols("x")
    y = sym.symbols("y")
    z = sym.symbols("z")
    f1 = z
    f2 = math.e ** x - y - z
    EulerMethod(x_val, y_val, z_val, h, x_max, f1, f2, x, y, z)

    x2 = np.linspace(0, 7, 100)
    fx = (2/3)*np.exp(-x2/2) * (np.cos(np.sqrt(3)/2*x2) + np.sqrt(3)*np.sin(np.sqrt(3)/2*x2)) + (1/3)*np.exp(x2)

    plt.plot(x2, fx, label = "与えられた解析解")
    plt.xlim(0, 6)
    plt.ylim(0, 120)
    #近似曲線
    plt.plot(x_val, y_val, 'r--', label = '得られた結果')

    plt.xlabel("x")
    plt.ylabel("y")

    plt.legend()
    plt.show()
    
    #誤差率
    px = np.linspace(0, x_max, int(x_max/h+1))
    py = (2/3)*np.exp(-px/2) * (np.cos(np.sqrt(3)/2*px) + np.sqrt(3)*np.sin(np.sqrt(3)/2*px)) + (1/3)*np.exp(px)
    print("  x | 誤差率 ")
    print("-------------")
    for i in range(len(px)):
        print(f"{px[i]:.1f}", f"{round(error(py[i], y_val[i]), 3):6.3f}", end = "% \n", sep = " | ")

if __name__ == "__main__":
    main()