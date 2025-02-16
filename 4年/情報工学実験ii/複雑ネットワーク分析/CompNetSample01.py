import networkx as nx
import matplotlib
from nltk.corpus import wordnet as wn

def traverse(graph, start, node):
    graph.depth[node.name] = node.shortest_path_distance(start)
    for child in node.hyponyms():
        graph.add_edge(node.name, child.name) 
        traverse(graph, start, child) 

def hyponym_graph(start):
    G = nx.Graph() 
    G.depth = {}
    traverse(G, start, start)
    return G

def graph_draw(graph):
    #graphvizが普通は入っていないか．matplotlibで書き直すようにする必要がある．
    #nx.draw_graphviz(graph,
    #     node_size = [16 * graph.degree(n) for n in graph],
    #     node_color = [graph.depth[n] for n in graph],
    #     with_labels = False)
    #matplotlib.pyplot.show()
    
    #ノードの位置を決める．ばねSpringレイアウト．kが小さいとばねが詰まる．つまり小さい画像に．
    #iterationsを増やすと，きれいな図になる．計算が重くなるが．
    pos = nx.spring_layout(graph,k=1,iterations=1000)
    #pos = nx.spring_layout(graph)#最低限の記述
    
    #エッジの描画設定
    nx.draw_networkx_edges(graph,pos,width=0.1,edge_color='black')#少しおしゃれにした描画
    #nx.draw_networkx_edges(graph,pos)#最低限の描画
    
    #ノードの描画設定
    #ノードのサイズを可変にしてみる．つながっている線Edgesの数に応じて
    node_size = [16 * graph.degree(n) for n in graph]
    node_color = [graph.depth[n] for n in graph]
    
    nx.draw_networkx_nodes(graph,pos,alpha=0.5,node_size=node_size,node_color=node_color)#おしゃれにした描画
    #nx.draw_networkx_nodes(graph,pos,alpha=0.5,node_size=30)#ちょっとおしゃれにした描画
    #nx.draw_networkx_nodes(graph,pos)#最低限の描画
    
    #ラベルの描画設定
    #nx.draw_networkx_labels(graph,pos,font_size=6)
    
    #最後に設定どおりに描画
    matplotlib.pyplot.axis('off')#軸を描画しない設定
    matplotlib.pyplot.show()

dog = wn.synset('dog.n.01')
graph = hyponym_graph(dog)
graph_draw(graph)