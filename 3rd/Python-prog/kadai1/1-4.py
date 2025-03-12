import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0.0, 8 * np.pi, num = 8 * 180 // 5 + 1)
N = int(input())

f = 0

for i in range(1, N + 1):
    f += (np.sin((2 * i -1) * x)) / (2 * i - 1)

f = f * (4 / np.pi)
plt.plot(x, f)
plt.show()
