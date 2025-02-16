#2-2
import numpy as np
import math
import sympy as sym
from sympy.plotting import plot

def BisectionMethod(fa, x, e, a, h): #二分法による解法
    k = 0
    while True:
        h = 0.5 * h
        if fa.subs(a, x[k]) * fa.subs(a, x[k]+h) < 0:
            x.append(x[k])
        else:
            x.append(x[k] + h)

        if e > h:
            break

        print(k+1, ":", x[k])

        k += 1
    print(k+1, ":", x[k])
    print("2.64574との誤差率:", error(2.64575, x[k]), "%")

def error(est, act): #誤差率を求める関数
    return abs(100 * (est - act) / act)

def main():
    x = [0]
    e = 1.0E-5
    h = 7
    a = sym.symbols("a") #xを変数を表す文字として扱う
    fa = a ** 2 - 7

    BisectionMethod(fa, x, e, a, h)

if __name__ == "__main__":
    main()