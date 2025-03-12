from sklearn import datasets
import matplotlib.pyplot as plt

iris = datasets.load_iris()

#plt.scatter(X[:50, 0], X[:50, 1], color='r', marker='o', label='setosa')
#plt.scatter(X[50:100, 0], X[50:100, 1], color='g', marker='+', label='versicolor')
#plt.scatter(X[100:, 0], X[100:, 1], color='b', marker='x', label='virginica')
for i, cl, mk, lb, in zip([0,1,2], 'rgb', 'o+x', iris.target_names):
    plt.scatter(X[y==i][:,0], X[y==i][:,1], color=cl, marker=mk, label=lb)
plt.title("Iris Plants Database")
plt.xlabel('sepal length(cm)')
plt.ylabel('sepal width(cm)')
plt.legend()
plt.show
