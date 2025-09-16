# Consider the following observations/data. And apply simple linear regression and find out estimated coefficients b1 and b1 Also analyse the performance of the model  (Use sklearn package) 
#x = np.array([1,2,3,4,5,6,7,8]) 
#y = np.array([7,14,15,18,19,21,26,23])

# import libraries 
import pandas as pd 
import numpy as np

# import linear regression librbries 
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt 

#read x and y 
x = np.array([1,2,3,4,5,6,7,8]).reshape(-1,1)
y = np.array([7,14,15,18,19,21,26,23])

# build the model
m= LinearRegression()

#fit the model 
m =m.fit(x,y)

#predict the value 
y_pred = m.predict(x)

# use data frame to show original and predicted value 
df = pd.DataFrame({'real y':y , 'predicted y':y_pred})
print("comparing the value of y : \n",df)

# estimated coefficients 
bo = m.intercept_
b1=m.coef_
r = m.score(x,y)
print("estimated coefficients : bo =",bo," b1 = ",b1," r = ",r)

# plot everything 
plt.scatter(x,y,color="red",label="actual value")
plt.scatter(x,y_pred,color="green",label="predicted value")
plt.plot(x,m.predict(x),color="blue",label="training line")
plt.title("actual vs predicted ")
plt.xlabel("<-------------x axis ---------->")
plt.ylabel("<------------y axis ------------>")
plt.legend()
plt.savefig("plot2.png")
plt.show()



