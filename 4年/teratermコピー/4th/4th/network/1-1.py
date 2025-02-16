#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import socket
import sys
port = 10045 # サーバのポート番号。10000 + 出席番号に書き換えること！
bufsize = 4096 # 比較的小さな2の累乗にする

# ソケットを作る
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# ソケットsockを待ち受け用ソケットにする
sock.bind(('', port))
sock.listen(1)

while True:
	# クライアントからの接続を待つ。
	# 接続されたらそのクライアントのアドレスがaddrに入り、
	# addrとの通信用ソケットとしてconnが作られる。
	conn, addr = sock.accept()
	print('クライアントが接続しました', addr)
	try:
		data = conn.recv(bufsize)
		try:
			data = data.decode('utf-8')
		except UnicodeDecodeError as msg:
			print(msg)
			conn.close()
			sys.exit(1)
		print('クライアントからの文字列: ', data)
		try:
			ans = int( int(data) * 1.1 )
		except ValueError:
			ans = '整数を入力して下さい\n'
			conn.sendall(ans.encode('utf-8'))
			print('通信終了')
			conn.close()
			continue
 	
		ans = str(ans)
		ans = ans + '\n'
		conn.sendall(ans.encode('utf-8'))
	except OSError as msg:
		print(msg)
		conn.close()
		sys.exit(1)

	# クライアントとの接続を閉じる
	print('通信終了')
	conn.close()
	# 待ち受け用ソケットを閉じる
sock.close()

