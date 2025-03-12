lat = 32.868852
deg = int(lat)
num = (lat - deg) * 60
min = int(num)
num = (num - min) * 60
sec = round(num,2)
print(f"{deg}度{min}分{sec}秒")

lon = 130.742914
deg = int(lon)
num = (lon - deg) * 60
min = int(num)
num = (num - min) * 60
sec = round(num,2)
print(f"{deg}度{min}分{sec}秒")
