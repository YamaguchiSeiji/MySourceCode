x = [0] * 3

for i in range(3):
    x[i] = int(input())
print(x)

i = 0
while i != 2:
    if x[i] > x[i + 1]:
        tmp = x[i]
        x[i] = x[i + 1]
        x[i + 1] = tmp
        i = 0
    else:
        i += 1

print(x)
