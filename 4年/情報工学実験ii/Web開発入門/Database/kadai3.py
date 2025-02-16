import sqlite3
import os
import sys
import random
import datetime

con = sqlite3.connect('kadai3.db')
cur = con.cursor()

os.system("clear")
name = input("Your Name?: ")

os.system("clear")
print("OK!!")
os.system("sleep 0.5")

query = "SELECT * FROM ranking WHERE name = ?;"
cur.execute(query, (name,))
rows = cur.fetchall()
already_flag = False


if not rows:
	print("Nice to meet you, " + name)
else:
	if rows[0][0] == name:
		print("Hello, " + name)
		high_score = rows[0][2]
		last_date = rows[0][1]
		print("Your High Score is: " + str(high_score) + "pt (" + last_date + ")")
		already_flag = True


os.system("sleep 0.5")
s = input("Are you ready??(y / n): ")
if s != 'y':
	print("OK, Good Bye!!")
	sys.exit()

i = 3
while True:
	os.system("clear")
	print("-----" + str(i) + "-----")
	os.system("sleep 1")
	i -= 1
	if i == 0:
		os.system("clear")
		break

collect_count = 0

while True:
	print("-----Game Start!!-----")
	num1 = random.randint(1, 100)
	num2 = random.randint(1, 100)

	ans = int(input(str(num1) + " + " +  str(num2) +  " = ?: "))

	if ans == num1 + num2:
		print("Collect Answer!!")
		collect_count += 1
		os.system("sleep 1")
	else :
		print("Wrong Answer")
		break
	
	os.system("clear")

os.system("clear")
print("-----YOUR RESULT-----")
print("Name: " + name)
date = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
print("Date: " + date)
print("Collect Answer: " + str(collect_count))

if already_flag:
	if collect_count >= high_score:
		query = "UPDATE ranking SET date = ?, answer = ? WHERE name = ?;"
		cur.execute(query, (date, collect_count, name))
else:
	query = "INSERT INTO ranking(name, date, answer) VALUES (?, ?, ? );"
	cur.execute(query, (name, date, collect_count))

con.commit()

query = "SELECT * FROM ranking ORDER BY answer DESC;"
cur.execute(query,)
rows = cur.fetchall()

i = 1
print()
print("-----RANKING-----")
for row in rows:
	if row[0] == name:
		print("[" + str(i) + "] " + "{: <10}".format(row[0]) + ": " + "{: >3}".format(str(row[2])) + "pt (" + row[1] + ") <--YOU!!")
	else:
		print("[" + str(i) + "] " + "{: <10}".format(row[0]) + ": " + "{: >3}".format(str(row[2])) + "pt (" + row[1] + ")")

	i += 1
	if i > 5:
		break;

cur.close()
con.close()
