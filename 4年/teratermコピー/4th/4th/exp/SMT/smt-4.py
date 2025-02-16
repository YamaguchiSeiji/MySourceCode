from z3 import *
import numpy as np

n = IntVector('n', 9)

s = Solver()

for i in range(9):
	s.add(n[i] >= 1)
	s.add(n[i] <= 9)

s.add(n[0] < n[1])
s.add(n[0] < n[4])
s.add(n[1] < n[2])
s.add(n[1] > n[5])
s.add(n[2] > n[6])
s.add(n[3] > n[4])
s.add(n[3] < n[6])
s.add(n[4] < n[5])
s.add(n[4] < n[7])
s.add(n[5] < n[8])
s.add(n[6] < n[7])
s.add(n[7] > n[8])

s.add(Distinct(n))

result = s.check()
print(result)
if result == sat:
	m = s.model()

data = np.array([])
for i in range(9):
	data = np.append(data, m[n[i]])

data = data.reshape(3, 3)
print(data)
