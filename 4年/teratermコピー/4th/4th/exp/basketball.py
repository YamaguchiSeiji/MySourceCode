import sqlite3

con = sqlite3.connect('basketball.db')
cur = con.cursor()
res = cur.execute("SELECT * FROM score ORDER BY time")
rows = res.fetchall()

team1point = 0
team2point = 0
playerPoint = []
f = False
team1name = rows[0][2]

for row in rows:
	if row[2] != team1name and f == False:
		team2name = row[2]
		f = True
	print(row[1] + " {: <8}".format(row[2]) + " No. {: >2}".format(row[3]) + " [" + str(row[4]) + " Point]")	
	if row[2] == team1name:
		team1point += row[4]
	else :
		team2point += row[4]

print()
print(team1name + " " + str(team1point) + " - " + str(team2point) + " " + team2name)

if team1point > team2point:
	print(team1name + " Wins!")
elif taem1point < team2point:
	print(team2name + " Wins!")
else :
	print("Draw");

res = cur.execute( "SELECT team, player_no, SUM(point) FROM score GROUP BY player_no;")
rows = res.fetchall()

for row in rows:
	playerPoint.append(row[2])

maxPoint = max(playerPoint)

print()
print("Top scorer: ")
for row in rows:
	if maxPoint == row[2]:
		print(row[0] + " No. " + str(row[1]) + " (Points: " + str(row[2]) + ")")


con.close()

