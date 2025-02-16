import matplotlib.pyplot as plt

y = [83, 75, 90, 88]
x = ["Q1", "Q2", "Q3", "Q4"]

N = len(y)

plt.plot(range(0, N), y, marker="o")
plt.xticks(range(0, N), x)
plt.ylim(50,100)
plt.show()