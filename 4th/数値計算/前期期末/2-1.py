#2-1
import numpy as np
import math
import sympy as sym
from sympy.plotting import plot

def NewtonMethod(fa, x, e, a): #ニュートン法による解法
    k = 0
    while True:
        print(k+1,":", x[k])
        k += 1
        x.append(float(x[k-1] - fa.subs(a, x[k-1]) / sym.diff(fa, a).subs(a, x[k-1])))
        if abs((x[k] - x[k-1])/x[k]) < e:
            break;

    print(k+1, ":", x[k])
    print("2.64574との誤差率:", error(2.64575, x[k]), "%")

def error(est, act): #誤差率を求める関数
    return abs(100 * (est - act) / act)

def main():
    x = [4]
    e = 1.0E-5
    a = sym.symbols("a") #xを変数を表す文字として扱う
    fa = a ** 2 - 7

    NewtonMethod(fa, x, e, a)

if __name__ == "__main__":
    main()