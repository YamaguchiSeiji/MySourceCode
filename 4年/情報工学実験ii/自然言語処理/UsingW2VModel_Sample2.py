from gensim.models import word2vec
#モデルの読み込み
model   = word2vec.Word2Vec.load("NatsumeKusamakura_model")

#ある単語のベクトルを表示する
#print(model.__dict__['wv']['角'])
#参考　https://m0t0k1ch1st0ry.com/blog/2016/08/28/word2vec/

#ある単語と最も意味が近い上位10個の単語を表示する
results = model.wv.most_similar("草", topn=10)

for result in results:
    print(result[0], '\t', result[1])

print()
#ある単語から次の言葉の意味を「引いた」意味に，
#最も意味が近い上位10個の単語を表示する
results = model.wv.most_similar("草", "女", topn=10)

for result in results:
    print(result[0], '\t', result[1])

#元の文章にない単語は使えずエラーが返ってくる