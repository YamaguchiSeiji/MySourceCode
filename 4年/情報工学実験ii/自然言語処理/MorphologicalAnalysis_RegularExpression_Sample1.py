#下の行は初めの一回だけ実行する．Janomeのインストール
#!pip install janome
#インストールが終わったらコメントアウトしておくとよい

from janome.tokenizer import Tokenizer
tokenizer = Tokenizer()
#参考サイトhttps://note.nkmk.me/python-janome-tutorial/

f1 = open('NatsumeKusamakura.txt', 'r', encoding='UTF-8')
s = f1.read()
f1.close
#print(s)
#参考サイト https://rbn-lab.net/google-colaboratory-file-import/

import re #正規表現を扱うためのライブラリ
# データの前処理
def preprocessing(text):
   # 英数字の削除
   text = re.sub("[a-xA-Z0-9_]", "", text)
   # 記号の削除
   text = re.sub("[!-/:-@[-`{-~*]", "", text)
   # 空白・改行の削除
   text = re.sub(u'\n\n', '\n', text)
   text = re.sub(u'\r', '', text)


   return text
#参考サイト　https://note.com/shimakaze_soft/n/n60b7e7ef6696

text = preprocessing(s)
#print(s[:100])

#sentences = s.split('。')
tokens = tokenizer.tokenize(text, wakati=True)#分かち書きにするように指定．
w = list(tokens)
#print(w[:100])
#参考サイトhttps://qiita.com/makaishi2/items/63b7986f6da93dc55edd



def save_wakati_file(wakati_list, save_path='wakati.txt'):
   # 分かち書きしたデータをファイルに保存．確認のためにもファイルにいったん書き出した．
   with open('./' + save_path, mode="w", encoding='utf-8') as f2:
       f2.write(' '.join(wakati_list))#この書き方で，" "半角スペースで区切りながらリスト内の単語をファイルに書き出せる
#word2vecにデータを入れる際には，形態素と形態素の間は，半角スペースで区切られている必要があるため．
#参考サイト https://note.com/shimakaze_soft/n/n60b7e7ef6696

save_wakati_file(w)

