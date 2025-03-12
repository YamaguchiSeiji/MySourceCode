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

    return Sn

def error(est, act): #誤差率を求める関数
    return abs(100 * (est - act) / act)

def main():
    x = [0]
    a = 10
    b = 20
    n = 1000
    m = 1000
    h = (b - a)/n
    t = sym.symbols("t") #tを変数を表す文字として扱う
    u = sym.symbols("u") #tを変数を表す文字として扱う
    f = t**2 * u**2

    f = DefiniteIntegrals(f, t, 0, a, n) #区分求積法
    f = DefiniteIntegrals(f, u, 0, b, m) #区分求積法
    print(f)

    print("V=888889との誤差率:", round(error(888889, f), 5), "%")

if __name__ == "__main__":
    main()