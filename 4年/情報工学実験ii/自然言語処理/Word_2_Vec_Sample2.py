
from gensim.models import word2vec
# 分かち書きしたテキストデータからコーパスを作成
sentences = word2vec.LineSentence("wakati.txt")
#print(sentences[:50])
#Word2Vecががver4.0より前の人は以下の行を使うこと。sizeがvector_sizeになっています。
model = word2vec.Word2Vec(sentences,  sg=1, size=100, window=5, min_count=1)
#Word2Vecががver4.0以上の人は以下の行を使うこと。sizeがvector_sizeになっています。
#model = word2vec.Word2Vec(sentences,  sg=1, vector_size=100, window=5, min_count=1)
model.save("NatsumeKusamakura_model")
#参考　https://qiita.com/g-k/items/69afa87c73654af49d36
#参考　https://m0t0k1ch1st0ry.com/blog/2016/08/28/word2vec/

