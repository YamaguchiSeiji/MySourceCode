from z3 import *

x = Real('x')
y = Real('y')

s = Solver()
s.add(2*x + 3*y == 6)
s.add(2*x + 3*y == 8)

result = s.check() # sat or unsat
print(result)
if result == sat:
    print(s.model()) # show a solution
