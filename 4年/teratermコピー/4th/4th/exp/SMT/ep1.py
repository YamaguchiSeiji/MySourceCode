from z3 import *

x = Int('x')
y = Int('y')
s = Solver()
s.add(x*4 + y*2 == 2)
s.add(x*4 + y*5 == -7)
result = s.check() # sat or unsat
print(result)
if result == sat:
    print(s.model()) # show a solution
