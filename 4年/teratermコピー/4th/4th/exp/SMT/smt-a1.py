from z3 import *

x = Real('x')
y = Real('y')


s = Solver()
s.add(y == 9 * x**2 + 11 * x + 3)
s.add(5 * x -y + 2 == 0)

result = s.check() # sat or unsat
print(result)
if result == sat:
    print(s.model()) # show a solution
