from z3 import *

x = Real('x')
y = Real('y')

s = Solver()
s.add(3*y == 5 - 2*x)
s.add(y**2 == x * y + 5)

result = s.check() # sat or unsat
print(result)
if result == sat:
    print(s.model()) # show a solution
