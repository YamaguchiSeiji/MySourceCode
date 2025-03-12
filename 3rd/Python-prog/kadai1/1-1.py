import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0.0, 2 * np.pi, num = 2 * 180 // 5 + 1)
f = 2 * np.sin(2 * x)
print(f)

plt.plot(x, f)
plt.show()
