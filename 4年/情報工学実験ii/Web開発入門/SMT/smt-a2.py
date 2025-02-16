from z3 import *

start = IntVector('start', 6)
end = IntVector('end', 6)
time = [3, 2, 3, 4, 6, 2]

for i in range(6):
	end[i] = start[i] + time[i]

s = Optimize() 

s.add(start[2] == end[1])
s.add(start[3] == end[0])
s.add(start[4] == end[1])

for i in range(6):
	s.add(start[i] >= 0)
	s.add(end[i] >= 0)
	if i == 5:
		continue
	s.add(start[5] >= end[i])

s.minimize(sum(end))

result = s.check()
if result == sat:
	m = s.model()

start_time = []

flag = False

for i in range(6):
	print("job" + str(i+1) + ": ", end = "")
	for j in range(m[start[5]].as_long() + time[5]):
		if m[start[i]].as_long() <= j and m[start[i]].as_long() + time[i] > j:
			print("*", end="")
			flag = True
		else :
			print(".", end="")
			flag = False

	print()
