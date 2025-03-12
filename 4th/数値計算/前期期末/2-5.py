#2-5
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

        print(x[k])

        if e > h:
            break

        k += 1

def error(est, act): #誤差率を求める関数
    return abs(100 * (est - act) / act)

def main():
    x1 = [1.0E-4]
    x2 = [1.0E-3]
    e = 1.0E-6
    E = 1
    R = 1095
    L = 0.3
    C = 1 * 10E-6
    h1 = 1.0E-4
    h2 = 1.0E-3
    t = sym.symbols("t") #tを変数を表す文字として扱う
    it = (E/L) * t * math.e ** ((-t * R) / (2 * L)) - ((2 * E)/(math.e * R)/2)

    print("xの初期値:", x1[0], ", hの初期値:", h1, "の場合")
    BisectionMethod(it, x1, e, t, h1)
    print("T1 = 1.27102e-4との誤差率:", round(error(1.27102E-4, x1[-1]),6), "%")

    print("xの初期値:", x2[0], ", hの初期値:", h2, "の場合")
    BisectionMethod(it, x2, e, t, h2)
    print("T2 = 1.46759e-3との誤差率:", round(error(1.46759E-3, x2[-1]),6), "%")

if __name__ == "__main__":
    main()