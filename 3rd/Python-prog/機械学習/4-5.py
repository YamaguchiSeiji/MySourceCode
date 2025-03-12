from sklearn import datasets
from sklearn import svm, metrics
from sklearn.model_selection import ShuffleSplit
import matplotlib.pyplot as plt

wine = datasets.load_wine()

X = wine.data
y = wine.target

n1 = int(input("Input Number(n1): "))
n2 = int(input("Input Number(n2): "))

for i, cl, mk, lb, in zip([0,1,2], 'rgb', 'o+x', ["wine1", "wine2", "wine3"]):
    plt.scatter(X[y==i][:, n1], X[y==i][:, n2], color=cl, marker=mk, label=lb)
plt.title("Wine Database")
plt.xlabel(wine.feature_names[n1])
plt.ylabel(wine.feature_names[n2])
plt.legend()
plt.show
