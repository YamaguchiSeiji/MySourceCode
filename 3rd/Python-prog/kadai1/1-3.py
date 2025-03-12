import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0.0, 8 * np.pi, num = 8 * 180 // 5 + 1)

f1 = (4 / np.pi) * np.sin(x)
f2 = (4 / (3 * np.pi)) * np.sin(3 * x)
f3 = (4 / (5 * np.pi)) * np.sin(5 * x)
f4 = (4 / (7 * np.pi)) * np.sin(7 * x)

plt.plot(x, f1)
plt.plot(x, f2)
plt.plot(x, f3)
plt.plot(x, f4)
plt.show()

f = f1 + f2 + f3 + f4
plt.plot(x, f)
plt.show()
