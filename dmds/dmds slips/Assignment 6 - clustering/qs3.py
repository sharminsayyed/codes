#. Write a python program to implement hierarchical clustering algorithm. (Download  Wholesale customers data dataset from github.com).

import pandas as pd 
import numpy as np
import matplotlib.pyplot as plt 
from sklearn.cluster import AgglomerativeClustering 
import scipy.cluster.hierarchy as s 

db = pd.read_csv(r"F:\Sharmin\5 sem code\dmds slips\Wholesale customers data.csv")
x = db.iloc[:,[3,4]].values
print(x)

# ddendrogram 
dendro = s.dendrogram(s.linkage(x,method='ward'))
plt.title("dendrogram")
plt.xlabel("customers")
plt.ylabel("eucledean distance")
plt.savefig("qs3plot1.png")


#clustering 
m = AgglomerativeClustering(n_clusters=3)
y_pred = m.fit_predict(x)
print(y_pred)

plt.scatter(x[y_pred == 0, 0] , x[y_pred == 0,1] ,color='red',label ='cluster 1')
plt.scatter(x[y_pred == 1,0] , x[y_pred == 1,1],color='green',label='cluster 2')
plt.scatter(x[y_pred == 2,0] ,x[y_pred == 2,1] , color='blue',label='cluster 3')
plt.title("hierarchical clustering ")
plt.xlabel("milk")
plt.ylabel('grocery')
plt.legend()
plt.savefig("qs3plot2.png")
#plt.show