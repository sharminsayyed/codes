#Write a python programme to implement multiple linear regression model for stock market data frame as follows: 
#And draw a graph of stock market price verses interest rate.

# import library 
import pandas as pd
Stock_Market = {
    'Year': [2017,2017,2017,2017,2017,2017,2017,2017,2017,2017,2017,2017,2016,2016,2016,2016,2016,2016,2016,2016,2016,2016,2016,2016], 
    'Month': [12, 11,10,9,8,7,6,5,4,3,2,1,12,11,10,9,8,7,6,5,4,3,2,1], 
    'Interest_Rate': [2.75,2.5,2.5,2.5,2.5,2.5,2.5,2.25,2.25,2.25,2,2,2,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75], 
    'Unemployment_Rate': [5.3,5.3,5.3,5.3,5.4,5.6,5.5,5.5,5.5,5.6,5.7,5.9,6,5.9,5.8,6.1,6.2,6.1,6.1,6.1,5.9,6.2,6.2,6.1], 
    'Stock_Index_Price': [1464,1394,1357,1293,1256,1254,1234,1195,1159,1167,1130,1075,1047,965,943,958,971,949,884,866,876,822,704,719]
    } 

# add to data frame 
df = pd.DataFrame(Stock_Market)
print(df)
# identify x and y
x =df.iloc[:,:-1]
y=df.iloc[:,-1]
print("data set of x ;\n",x)
print("data set of y :\n",y)

# import linear regression
from sklearn.linear_model import LinearRegression

#build model 
m = LinearRegression()

# fit the model
m = m.fit(x,y)

#predict the value 
y_pred = m.predict(x)

# use data frame
df1 = pd.DataFrame({'real y':y,'predicted y ':y_pred})
print("comparing the real and predicted value of y :\n",df1)

#estimated coefficients 
bo = m.intercept_
b1=m.coef_
r = m.score(x,y)
print("estimated coefficients : bo =",bo," b1 = ",b1 , " r = ",r)

#And draw a graph of stock market price verses interest rate.
import matplotlib.pyplot as plt 
plt.plot(df['Interest_Rate'] , df['Stock_Index_Price'],color='blue')
plt.title("interest rate vs stock market rate ")
plt.xlabel("interest rate ")
plt.ylabel("stock market price ")
plt.savefig("plot4.png")
plt.show()

