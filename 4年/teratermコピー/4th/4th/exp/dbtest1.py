import sqlite3

con = sqlite3.connect('practice.db')
cur = con.cursor()
res = cur.execute("SELECT * FROM fruits")
rows = res.fetchall()

for row in rows:
	print(row)

con.close()
