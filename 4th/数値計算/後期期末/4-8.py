#4-8
import numpy as np

def powerMethod(A, x, e, n):
    for i in range(n):
        l = [1]
        k = 0
        while True:
            k += 1
            u = np.dot(A, x)
            l.append(np.dot(x.T, u))
            x = np.dot(u, 1 / np.sqrt(np.dot(u.T, u)))
            if abs(l[k] - l[k-1]) < e:
                break

        A = A - l[-1] * np.outer(x, x)

    return l[-1], x

def main():
    A = np.array([
        [4, 1],
        [1, 0]])
    e = 10E-5
    x = np.array([1, 1])
    n = 2
    l2, u2 = powerMethod(A, x, e, 2)
    print("2番目の固有値λ2:", l2)
    print("2番目の固有ベクトルu2:", u2)

if __name__ == "__main__":
    main()