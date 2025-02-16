import csv

data = []

# CSVファイルを開く
with open(r"C:\Users\s1230\OneDrive - 独立行政法人 国立高等専門学校機構\HI4山口\信号処理\1105\meiji1.csv", mode='r', encoding='utf-8') as file:
    reader = csv.reader(file)
    
    # 各行を読み込む
    for row in reader:
        data.append(row)

for i in range(1, len(data)):
    for j in range(1, len(data[i])):
        data[i][j] = float(data[i][j].replace(',', ''))
       
for i in range(1, len(data)):
    data[i][0] = f'"{data[i][0]}"'
        
with open(r"C:\Users\s1230\OneDrive - 独立行政法人 国立高等専門学校機構\HI4山口\信号処理\1105\meiji2.csv", mode='w', encoding='utf-8', newline='') as file:
    writer = csv.writer(file)
    
    # データをファイルに書き込む
    for row in data:
        writer.writerow(row)