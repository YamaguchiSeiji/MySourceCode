#4-10
import numpy as np

def powerMethod(A, x, e, n):
    for i in range(n):
        l = [1]
        k = 0
        while True:
            k += 1
            u = np.dot(A, x)
            l.append(np.dot(x.T, u))
            x = u / np.linalg.norm(u)
            if abs(l[k] - l[k-1]) < e:
                break

        A = A - l[-1] * np.outer(x, x)

    return l[-1], x

def main():
    A = np.array([
        [3, 0, 0, 1],
        [0, 3, 0, 0],
        [0, 0, 1, 0],
        [1, 0, 0, 3]
        ])
    e = 10E-5
    x = np.array([1, 1, 1, 0])
    l2 , u2 = powerMethod(A, x, e, 2)
    l3 , u3 = powerMethod(A, x, e, 3)
    l4 , u4 = powerMethod(A, x, e, 4)
    print("2番目の固有値λ2:", l2)
    print("2番目の固有ベクトルu2:", u2)
    print("3番目の固有値λ3:", l3)
    print("3番目の固有ベクトルu3:", u3)
    print("4番目の固有値λ4:", l4)
    print("4番目の固有ベクトルu4:", u4)

if __name__ == "__main__":
    main()