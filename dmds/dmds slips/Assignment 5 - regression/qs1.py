# Consider the following observations/data. And apply simple linear regression and find out estimated coefficients b0 and b1.( use numpy package) 
# x=[0,1,2,3,4,5,6,7,8,9,11,13] 
# y = ([1, 3, 2, 5, 7, 8, 8, 9, 10, 12,16, 18] 

# import libraries
import pandas as pd 
import numpy as np
# import libraries for linear regression
from sklearn.linear_model import LinearRegression 
import  matplotlib.pyplot as plt

# define x(in columns) and y 
#  2D array with a single column (-1 means NumPy will automatically calculate the appropriate number of rows).
x = np.array([0,1,2,3,4,5,6,7,8,9,11,13] ).reshape(-1,1)
y = np.array([1, 3, 2, 5, 7, 8, 8, 9, 10, 12,16, 18] )

# slip x and y in train and test and display
from sklearn.model_selection import train_test_split as tts 
x_train,x_test,y_train,y_test = tts(x,y,test_size=0.2,random_state=1)
print("training set of x :\n",x_train)
print("testing set of x :\n",x_test)
print("training set of y :\n",y_train)
print("testing set of y :\n",y_test)

#build model
m = LinearRegression()
#fit it on training data 
m = m.fit(x_train,y_train)
#predict the values 
y_pred = m.predict(x_test)

#print the predicted and original values in dataframe 
df = pd.DataFrame({'real y' : y_test , 'predicted y ':y_pred})
print("comparing the result :",df)

#estimate the bo and b1
bo = m.intercept_
b1 = m.coef_
print("estimated coefficients : bo = ",bo," b1 = ",b1)

#visualize the result 
plt.scatter(x_test,y_test,color ='red',label="actual value of y")
plt.scatter(x_test,y_pred,color='green',label="predicted value of y")
plt.plot(x_train,m.predict(x_train),color='blue',label="training dataset ")
plt.title("actual vs predicted ")
plt.xlabel("<--------------x axis ------------->")
plt.ylabel("<--------------y axis ------------->")
plt.legend()
plt.savefig("plot.png")  

plt.show()


