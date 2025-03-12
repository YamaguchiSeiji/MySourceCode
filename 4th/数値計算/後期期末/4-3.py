#4-3
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
        [4, 1],
        [1, 0]])
    e = 10E-5
    x = np.array([1, 1])
    l, u = powerMethod(A, x, e)
    print("固有値:", l)
    print("固有ベクトル:", u)

if __name__ == "__main__":
    main()