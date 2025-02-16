import matplotlib.pyplot as plt

x = ["q1", "q2", "q3", "q4"]
ay = [83, 75, 90, 88]
by = [70, 83, 65, 82]
cy = [82, 98, 80, 94]

N = len(y)

plt.plot(range(0, N), ay, marker = "o", color = "b", label = "A")
plt.plot(range(0, N), by, marker = "x", color = "orange", label = "B")
plt.plot(range(0, N), cy, marker = "D", color = "g", label = "C")

plt.xticks(range(0, N), x)
plt.legend(loc = "lower left")
plt.ylim(50,100)
plt.show()