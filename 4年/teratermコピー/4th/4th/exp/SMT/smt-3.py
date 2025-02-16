from z3 import *

c10 = Int('c10')
c50 = Int('c50')
c100 = Int('c100')
c500 = Int('c500')

s = Optimize() # 最適解を見つけるために，Solver でなく Optimize を用いる

s.add(c10 >= 1)
s.add(c50 >= 1)
s.add(c100 >= 1)
s.add(c500 >= 1)
s.add(c10 > c50)
s.add(c50 > c100)
s.add(c100 > c500)

s.add(c10 * 10 + c50 * 50 + c100 * 100 + c500 * 500 == 1590)
s.minimize(c10 + c50 + c100 + c500) # 硬貨の合計枚数が最小となる解を選ぶ

result = s.check()
print(result)
if result == sat:
	print(s.model())

