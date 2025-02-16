from z3 import *
import time

data = [
[0, 2, 3, 0, 0, 5, 0, 6, 0],
[7, 0, 5, 0, 2, 0, 9, 0, 0],
[0, 0, 0, 0, 7, 0, 0, 0, 4],
[5, 8, 0, 0, 0, 0, 3, 0, 9],
[0, 0 ,0 ,0 ,0, 0, 0, 0, 0],
[6, 0, 2, 0, 1, 0, 5, 0, 0],
[0, 0, 0, 2, 9, 0, 0, 0, 0],
[2, 3, 7, 0, 0, 8, 0, 0, 0],
[0, 4, 1, 0, 0, 0, 0, 0, 0]]

#タイマーセット
start_time = time.time()

n = IntVector('n', 81)
Sum = Int('Sum') 

s = Solver()

for i in range(81):
	s.add(n[i] >= 1)
	s.add(n[i] <= 9)

for i in range(9):
	for j in range(9):
		if data[i][j] != 0:
			s.add(n[i * 9 + j] == data[i][j])

#縦方向を見る
for i in range(0, 81, 9):
	s.add(Sum == sum(n[i:i+9]))
	s.add(Distinct(n[i:i+9]))

#横方向を見る
for i in range(9):
	s.add(Sum == sum(n[i:81:9]))
	s.add(Distinct(n[i:81:9]))

#3x3を見る
for i in range(0, 81, 27):
	for j in range(i, i + 9, 3):
		s.add(Sum == sum(n[j:j+3] + n[j+9:j+12] + n[j+18:j+21]))
		s.add(Distinct(n[j:j+3] + n[j+9:j+12] +  n[j+18:j+21]))

result = s.check()
print(result)
if result == sat:
	end_time = time.time()
	print()
	print("time:")
	print(end_time - start_time, end = "s\n\n")
	m = s.model()
	print("Puzzle: ")
	for i in range(9):
		for j in range(9):
			if data[i][j] == 0:
				print("-", end = ' ')
				continue
			print(data[i][j], end = ' ')
		print()

	print()
	print("Solution: ")
	for i in range(81):
		print(m[n[i]], end = ' ')
		if i % 9 == 8:
			print()
