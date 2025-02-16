import sqlite3

con = sqlite3.connect('test.db');
cur = con.cursor()
cur.execute("CREATE TABLE movie(title, year, socre)")
cur.execute("""
	INSERT INTO movie VALUES
		('Monty Python and the Holy Grail', 1975, 8.2),
		('And Now for Something Completely Different', 1971, 7.5)
	""")

con.commit()

res = cur.execute("SELECT * FROM movie")
rows = res.fetchall()

for row in rows:
	print(row)

con.close()
