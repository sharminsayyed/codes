# Write a python program to implement k-means algorithm to build prediction model (Use Credit Card Dataset CC GENERAL.csv Download from kaggle.com)

#import libraries
import pandas as pd 
import numpy as np
import matplotlib.pyplot as plt 
from sklearn.cluster import KMeans 

# read data set 
db = pd.read_csv(r"F:\Sharmin\5 sem code\dmds slips\CC GENERAL.csv")
x= db.iloc[:,[3,4]].values
# these 2 columns will be used for clustering 
#.values: This converts the selected columns into a NumPy array.
print(x)

# elbow graph  
# wcss = within cluster sum of square 
WCSS=[]
for i in range (1,11):
    m = KMeans(n_clusters=i,n_init='auto',random_state=1)
    m = m.fit(x)
    WCSS.append(m.inertia_)

print("\n wcss :",WCSS)
# as u increase number of cluster it will decrease the error 
#plotting elbow graph 
plt.plot(range(1,11),WCSS,color='blue')
plt.title("elbow graph")
plt.xlabel("no of clusters")
plt.ylabel("WCSS")
plt.savefig("qs1plot1.png")
#plt.show()
#check the ooptimal no of clusers from here 


m = KMeans(n_clusters=3,n_init ='auto',random_state=1)
y_pred = m.fit_predict(x)
print(y_pred)
# assigning the clusters for all the data in the x 

# do the clustering 
# y_pred == 0 all the values in x that are assigned cluster no 0 
plt.scatter(x[y_pred == 0,0],x[y_pred == 0,1], color ='red',label='Cluster 1')
plt.scatter(x[y_pred == 1,0],x[y_pred == 1,1], color='green',label='Cluster 2 ')
plt.scatter(x[y_pred == 2,0],x[y_pred == 2,1], color='yellow',label='Cluster 3')

plt.title("KMeans Clustering ")
plt.xlabel("Purchase ")
plt.ylabel("one of purchases ")

plt.scatter(m.cluster_centers_[:,0],m.cluster_centers_[:,-1],color='purple',label='centroid')
plt.legend()
plt.savefig("qs1plot2.png")
#plt.show()
