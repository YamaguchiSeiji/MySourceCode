from z3 import *

x = Real('x')
y = Real('y')
z = Real('z')

s = Solver()
s.add(x + y*3 - z == 6)
s.add(x*2 - y + z*2 == 1)
s.add(x*3 + y*2 - z == 2)

result = s.check() # sat or unsat
print(result)
if result == sat:
    print(s.model()) # show a solution
