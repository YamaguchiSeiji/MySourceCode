#4-5
import numpy as np

def powerMethod(A, x, e):
    l = [1]
    k = 0
    while True:
        k += 1
        u = np.dot(A, x)
        l.append(np.dot(x.T, u))
        x = np.dot(u, 1 / np.sqrt(np.dot(u.T, u)))
        if abs(l[k] - l[k-1]) < e:
            break

    return l[-1], x

def main():
    A = np.array([
        [3, 0, 0, 1],
        [0, 3, 0, 0],
        [0, 0, 1, 0],
        [1, 0, 0, 3]
        ])
    e = 10E-5
    x = np.array([1, 1, 1, 1])
    n = 2
    l, u = powerMethod(A, x, e)
    print("固有値:", l)
    print("固有ベクトル:", u)

if __name__ == "__main__":
    main()