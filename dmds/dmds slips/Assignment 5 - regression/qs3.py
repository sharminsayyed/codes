#Consider the student data set. It can be downloaded from: Write a programme in python to apply simple linear regression and find out mean 
# absolute error, mean squared error and root mean squared error. 

# import library
import pandas as pd 
import numpy as np

# import library for regression
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt 

# read data set 
db = pd.read_csv(r"F:\Sharmin\5 sem code\dmds slips\student_scores.csv")
x=np.array(db['Hours']).reshape(-1,1)
y =np.array(db['Scores'])

#split in train and test and display
from sklearn.model_selection import train_test_split as tts 
x_train,x_test,y_train,y_test = tts(x,y,test_size=0.2)
print("training set of x :\n",x_train)
print("testing set of x :\n",x_test)
print("training set of y :\n",y_train)
print("testing set of y :\n",y_test)

# build the model and apply linear regression
m = LinearRegression()
# fit into training set 
m = m.fit(x_train,y_train)
#predict the values 
y_pred = m.predict(x_test)
#use dataframe to display the predicted and real values
df = pd.DataFrame({'real y':y_test,'predicted y':y_pred})
print("comparing the value : \n",df)

#estimated coefficients
bo = m.intercept_
b1 = m.coef_
print("estimated coefficient : bo = ",bo ,"b1 = ",b1)

#eroorsss
import math
from sklearn.metrics import mean_absolute_error ,mean_squared_error
mae = mean_absolute_error(y_test,y_pred)
mse = mean_squared_error(y_test,y_pred)
rmse = math.sqrt(mse)
print("mean absolute error : ",mae ,"mean squared error :",mse,"root mean squared error :",rmse)

# vivsualize the result 
plt.scatter(x_test,y_test,color='red',label='actaul value ')
plt.scatter(x_test, y_pred , color ='green',label='predicted value')
plt.plot(x_train,m.predict(x_train) ,color='blue',label='training data ')
plt.xlabel("<------------- x axis ------------->")
plt.ylabel("<------------- y axis -------------->")
plt.legend()
plt.savefig("plot3.png")
plt.show()

