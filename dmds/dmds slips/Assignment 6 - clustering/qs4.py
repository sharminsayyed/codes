#Write a python program to implement k-means algorithms on a synthetic dataset.
import matplotlib.pyplot as plt 
from sklearn.cluster import KMeans 
from sklearn.datasets import make_blobs 

data = make_blobs(n_samples=300,n_features=2,random_state =1)
print("sysnthetic data set : \n",data)
x = data[0]
print("********* values ********** \n",x)

m=KMeans(n_clusters =5,n_init='auto',random_state=1)
y_pred = m.fit_predict(x)
print("predicted values :\n",y_pred)

KMeans_labelf,(ax1,ax2)= plt.subplots(1,2,sharey=True,figsize=(10,6))

ax1.scatter(x[data[1] == 0,0], x[data[1] == 0,1],color='red',label='cluster 1 ')
ax1.scatter(x[data[1] == 1,0], x[data[1] == 1,1], color='green', label='cluster 2')
ax1.scatter(x[data[1] == 2,0], x[data[1] == 2,1], color='blue' , label='cluster 3')
ax1.legend()

ax2.scatter(x[y_pred == 0,0], x[y_pred == 0,1], color='red', label='cluster 1 ')
ax2.scatter(x[y_pred == 1,0], x[y_pred == 1,1], color='green', label='cluster 2 ')
ax2.scatter(x[y_pred == 2,0], x[y_pred == 2,1], color='blue', label='cluster 3 ')
ax2.scatter(x[y_pred == 3,0], x[y_pred == 3,1], color='orange', label='cluster 4 ')
ax2.scatter(x[y_pred == 4,0], x[y_pred == 4,1], color='black', label='cluster 5 ')
ax2.legend()

plt.savefig("qs4plot1.png")
#plt.show()

