from sklearn import datasets
from sklearn import svm, metrics
from sklearn.model_selection import ShuffleSplit

wine = datasets.load_wine()

X = wine.data
y = wine.target

wine_ss = ShuffleSplit(train_size=0.6, test_size=0.4, random_state=1)
train_index, test_index = next(wine_ss.split(X))

X_train, y_train = X[train_index], y[train_index]
X_test, y_test = X[test_index], y[test_index]

#SVC
clf = svm.SVC()
clf.fit(X_train, y_train)
print("-----SVC: RESULT-----")
print("score:", clf.score(X_test, y_test))
predicted = clf.predict(X_test)
(y_test != predicted).sum()

result = metrics.confusion_matrix(y_test, predicted)
print("wine", 0, "(Correct, Incorrect):", result[0][0], ",", result[0][1]+result[0][2])
print("wine", 1, "(Correct, Incorrect):", result[1][1], ",", result[1][0]+result[1][2])
print("wine", 2, "(Correct, Incorrect):", result[2][2], ",", result[2][0]+result[2][1])

print(metrics.classification_report(y_test, predicted))



#LinearSVC
clf = svm.LinearSVC(max_iter = 50000000)
clf.fit(X_train, y_train)
print("-----LinearSVC: RESULT-----")
print("score:", clf.score(X_test, y_test))
predicted = clf.predict(X_test)
(y_test != predicted).sum()

result = metrics.confusion_matrix(y_test, predicted)
print("wine", 0, "(Correct, Incorrect):", result[0][0], ",", result[0][1]+result[0][2])
print("wine", 1, "(Correct, Incorrect):", result[1][1], ",", result[1][0]+result[1][2])
print("wine", 2, "(Correct, Incorrect):", result[2][2], ",", result[2][0]+result[2][1])

print(metrics.classification_report(y_test, predicted))
