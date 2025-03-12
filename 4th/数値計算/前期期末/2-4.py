#2-4
import numpy as np
import math
import sympy as sym
from sympy.plotting import plot

def NewtonMethod(fa, x, e, a): #ニュートン法による解法
    k = 0
    while True:
        print(k+1, ":", x[k])
        k += 1
        x.append(float(x[k-1] - fa.subs(a, x[k-1]) / sym.diff(fa, a).subs(a, x[k-1])))
        if abs((x[k] - x[k-1])/x[k]) < e:
            break;
    
    print("5.5452との誤差率:", error(5.5452, x[k]), "%")


def error(est, act): #誤差率を求める関数
    return abs(100 * (est - act) / act)

def main():
    x = [1]
    e = 1.0E-5
    E = 1
    R = 100 * 10**3
    C = 80 * 10**-6
    t = sym.symbols("t") #xを変数を表す文字として扱う
    it = (E/R) * math.e ** (-t / (C * R)) - (E/R/2)

    NewtonMethod(it, x, e, t)

if __name__ == "__main__":
    main()