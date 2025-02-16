#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import socket
import sys
import datetime

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
		dt_now = datetime.datetime.now().strftime("%Y年%m月%d日 %H:%M\n")
		conn.sendall(dt_now.encode('utf-8'))

	except OSError as msg:
		print(msg)
		conn.close()
		sys.exit(1)

	# クライアントとの接続を閉じる
	print('通信終了')
	conn.close()
	# 待ち受け用ソケットを閉じる
sock.close()

