# coding: utf-8
# utf-8はUTF-8のBOM無しの事．
#読み込むデータファイルは，UTF-8のBOM無しで保存する事．

import csv
import networkx as nx
import matplotlib.pyplot as plt
import math
import pylab as pl
import numpy as np

#05からDiGraph
#G=nx.Graph()
G=nx.DiGraph()


#Python3では，以下のように，try - with open等と書かなければならない？
#try:
#      with open('CompNetSample02data.csv','r') as f1:



#シングルクオーテーションにすれば，p3でもいけるみたい．
#ファイルを開いて
f1 = open('CompNetSample02data.csv', 'r')
#ファイルからデータを読み出せる形にする
reader1 = csv.reader(f1)

#データは，リンク強度にとりあえず全部1を入れただけ．
#あとで，より現実的な強度を入れる必要がある



#f2 = open("keyword0621.csv","r")
#reader2 = csv.reader(f2)


##for row in reader1:
##   if int(row[2]) != 0:     
##      a = row[0]
##      b = row[1]
##      G.add_edge(a, b, weight = int(row[2]))
##   else:
##      G.add_nodes_from([row[0],row[1]])

###csvのオブジェクトからデータを読み出す．rowというリストに
##for row in reader1:
####   if int(row[2]) != 0:
##      if row[1] != "NONE":
##            #以下のifは，実数でリンク強度を設定した場合の閾値
##            if float(row[2]) > 0.1:
##                  a = row[0]
##                  b = row[1]
##                  G.add_edge(a, b)
##                  ##   else:
##                  ##      G.add_nodes_from([row[0],row[1]])


###csvのオブジェクトからデータを読み出す．rowというリストに
#重みをリンクに加える
for row in reader1:
##   if int(row[2]) != 0:
      if row[1] != "NONE":#貿易相手が"None（居ない）"以外なら
            #以下のifは，実数でリンク強度を設定した場合の閾値
            if float(row[2]) > 0.05:
                  a = row[0]
                  b = row[1]
                  #CSVから持ってきた値は全て文字列として扱われるから，float()やint()で変換せんと
                  G.add_edge(a, b,weight = float(row[2])) 
                  ##   else:
                  ##      G.add_nodes_from([row[0],row[1]])


   

'''
for row1 in reader1:
   for row2 in reader2:
      if row2 == row1[0]:
         if row1 != []:
            a = row1[0]
            b = row1[1]
            G.add_edge(a, b)
'''
f1.close()
#ここまででネットワークデータ読み込みと，ネット再構築



#以下は様々な指標計算の例
#Betweenness centrallity媒介中心性を求める
#戻り値はdictionary型なんだそうな
b=nx.betweenness_centrality(G)

for k,v in sorted(b.items()):
      print(str(k) + ": " + str(v))

#CSV形式で書き出し．これが一番シンプルで書きやすかった．
file = open("BC.csv",'w')
for k,v in sorted(b.items()):
      file.write(str(k) + "," + str(v)+"\n")
file.close()


#以下固有ベクトル中心性の例
#固有値ベクトル中心性は無向グラフでしか使えない
#ec = nx.eigenvector_centrality_numpy(G)
#file = open("EigenVectorCentr.csv",'w')
#for k,v in sorted(ec.items()):
#      file.write(str(k) + "," + str(v)+"\n")
#file.close()


#有向グラフでも，PageRankなら使える．Googleで有名．      
pr = nx.pagerank(G)
file = open("PageRank.csv",'w')
for k,v in sorted(pr.items()):
      file.write(str(k) + "," + str(v)+"\n")
file.close()



#以下は描画関係
pos = nx.spring_layout(G, k=1.1) #ここでノードの位置を決めている


#nx.draw(G, pos)#ノードも，エッジも一緒にかける関数
#今回はエッジやノードの書き方を個別指定しているので必要なし．

#ノードの書き方
#G:描画するネットワーク．pos:位置．事前に決めたものを使う． 
#node_clolr:ノードの色．RGBAでも指定できる．
#https://matplotlib.org/stable/tutorials/colors/colors.html
nx.draw_networkx_nodes(G, pos, node_color='r',alpha=0.9, node_size=50)
#ページランクが大きい程丸が大きくなるような書き方
#prには，(ノード名,ページランクの値)が入っているので
#forで回すとき二つの値が来るのでkとvで受けています
#node_size = [100 * float(v) for k,v in pr]
#nx.draw_networkx_nodes(G, pos, node_color='r',alpha=0.5, node_size=node_size)
#色の指定をRGBAで
#nx.draw_networkx_nodes(G, pos, node_color='#0F019F0F',alpha=0.5, node_size=node_size)

#エッジの書き方
nx.draw_networkx_edges(G, pos, alpha=0.4, edge_color='c', width=1)

#connectionstyleというのを指定すると，線を曲げて表示できる
#nx.draw_networkx_edges(G, pos, alpha=0.4, edge_color='c', connectionstyle='arc3, rad = 0.1', width=1)

#エッジの太さをweightに応じて変えるやり方
#https://qiita.com/harutine/items/e3073ba4f5daf1fa5d7b
#edge_weights = [G[u][v]['weight'] for u,v in G.edges]
#nx.draw_networkx_edges(G, pos, alpha=0.4, edge_color='c', width=edge_weights)



#ラベルの書き方．基本編
#nx.draw_networkx_labels(G, pos)

#らべるの更におしゃれな書き方
#まずlabel_optionsでラベル箱のおしゃれな書き方を辞書形式で指定
#ecはedgecolor．fcはfacecolor背景の色
#https://qiita.com/nkay/items/d1eb91e33b9d6469ef51#45-%E5%9B%B3%E5%BD%A2%E3%81%AE%E8%A8%AD%E5%AE%9Abbox
#label_options = {"ec": "k", "fc": "white", "alpha": 0.7}
#nx.draw_networkx_labels(G, pos, font_size=11, bbox=label_options)

#とにかく目立たないラベル指定
nx.draw_networkx_labels(G, pos, font_size=11, bbox={"alpha":0.0})




#画面に表示
plt.axis('off')
plt.show()




#G.add_edges_from([(1,2),(1,3),(2,3)])
#G.add_node("spam")
#G.add_node("Jin Akaishi")
#G.add_edge("spam","Jin Akaishi")
#print G.nodes()
#print G.edges()
#print nx.connected_components(G)
#print nx.clustering(G)

'''
a=1
while a < 10:
   print a
   a = a+1

nx.draw(G)
plt.show()
'''

#sys.exit()

