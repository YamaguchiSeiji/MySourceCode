#2-3
import numpy as np
import math
import sympy as sym
from sympy.plotting import plot

def DefiniteIntegrals(ft, t, a, b, n): #区分求積法による解法
    h = (b - a)/n
    xk = []
    Sn = 0

    for k in range(n):
        xk.append(a + k * h)
        Sn += ft.subs(t, xk[k]) * h
        print(Sn)

    print("区分求積法による解法: ", Sn)
    print("πとの誤差率: ", error(Sn, math.pi), "%")
    print()

def TrapezoidalRule(ft, t, a, b, n): #台形公式による解法
    h = (b - a)/n
    xk = []
    Sn = 0

    for k in range(n+1):
        xk.append(a + k * h)

    for k in range(n):
        Sn += (h/2) * (ft.subs(t, xk[k]) + ft.subs(t, xk[k+1]))
        print(Sn)

    print("台形公式による解法: ", Sn)
    print("πとの誤差率: ", error(Sn, math.pi), "%")
    print()

def SimpsonsRule(ft, t, a, b, n): #シンプソンの公式による解法
    h = (b - a)/n
    xk = []
    Sn = 0

    for k in range(n+1):
        xk.append(a + k * h)

    for k in range(int(n/2)):
        Sn += (h/3) * (ft.subs(t, xk[2*k]) + 4*(ft.subs(t, xk[2*k+1])) + ft.subs(t, xk[2*k+2]))
        print(Sn)

    print("シンプソンの公式による解法: ", Sn)
    print("πとの誤差率: ", error(Sn, math.pi), "%")
    print()

def error(est, act): #誤差率を求める関数
    return abs(100 * (est - act) / act)

def main():
    x = [0]
    a = 0
    b = 1
    n = 5
    t = sym.symbols("t") #tを変数を表す文字として扱う
    ft = 4 / (1 + t**2)

    DefiniteIntegrals(ft, t, a, b, n) #区分求積法
    TrapezoidalRule(ft, t, a, b, n) #台形公式
    SimpsonsRule(ft, t, a, b, n) #シンプソン

if __name__ == "__main__":
    main()