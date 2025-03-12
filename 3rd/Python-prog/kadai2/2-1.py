sec = 3700

hh = sec//3600
mm = (sec - hh*3600) // 60
ss = sec % 60

print(hh, mm, ss)
