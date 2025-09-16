#Write a python program to implement multiple Linear Regression model for a car dataset. 

#import library 
import pandas as pd 
import numpy as np

#import library for regression
from sklearn.linear_model import LinearRegression

#read data set 
db = pd.read_csv(r"F:\Sharmin\5 sem code\dmds slips\car.csv")
#identify x and y 
x = np.array(db[['Volume','Weight']]).reshape(-1,2)
y = np.array(db['CO2'])
print("data set of x :",x)
print("data set of y :",y)

# split x and y in train and test and display 
from sklearn.model_selection import train_test_split as tts 
x_train,x_test,y_train,y_test = tts(x,y,test_size = 0.2)
print("training set of x :\n",x_train)
print("testing set of x :\n",x_test)
print("training set of y :\n",y_train)
print("testing set of y :\n",y_test)

# build the model for regression
m = LinearRegression()
#fit the training data 
m = m.fit(x_train,y_train)
#predict the value
y_pred = m.predict(x_test)

# using dataframe to dispaly 
df = pd.DataFrame({'real y' : y_test , 'predicted y':y_pred})
print("compareing the value of y :\n",df)

# predict for a value 
print("predict co2 for weight = 1300kg and volume = 2300cm2 :",m.predict([[1300,2300]]))

#estimate the coefficients 
bo = m.intercept_
b1 = m.coef_
r = m.score(x,y)
print("estimated coefficients : bo = :",b1," b1 = ",b1,"r = ",r)
