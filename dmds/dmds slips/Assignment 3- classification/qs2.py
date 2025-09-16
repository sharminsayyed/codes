# Write a Python program build Decision Tree Classifier for shows.csv from pandas and predict class label for show starring a 40 years old American 
#comedian, with 10 years of experience, and a comedy ranking of 7? Create a csv file as shown in https://www.w3schools.com/python/python_ml_decision_tree.asp 

# import libraries
import pandas as pd 
from sklearn.model_selection import train_test_split as tts 

# read database and display 
db = pd.read_csv(r"F:\Sharmin\5 sem code\dmds slips\shows.csv")
print("\n ***** database ***** \n",db)

# convert categorical data to numnerical 
d = {'USA':0,'UK':1,'N':2}
db['Nationality'] = db['Nationality'].map(d)
g = {'YES':1,'NO':0}
db['Go'] = db['Go'].map(g)
# check if everything is map 
print("dataset :\n",db)

# identify the x and y and display there data set 
x = db.iloc[:,:-1]
y = db.iloc[:,-1]
print("\n **** dataset of x **** \n",x.head())
print("\n ***** dataset of y *** \n",y.head())

#slipt x and y in train and test and display 
x_train,x_test,y_train,y_test = tts(x,y,test_size=0.2)
print("\n *** training set of x ****",x_train)
print("\n **** testing set of x ****",x_test)
print("\n **** training set od y ****",y_train)
print("\n **** testing set of y *****",y_test)

# import decision tree
from sklearn.tree import DecisionTreeClassifier as dtc 
# build model
m = dtc()
# train the model 
m = m.fit(x_train,y_train)
#predict the values 
y_pred = m.predict(x_test)
#display the predicted and original values 
print("\n**** predicted value  **** \n",y_pred)
print("\n**** original value ****\n",y_test)

#check accuracy 
from sklearn import metrics 
print("Accuracy :",metrics.accuracy_score(y_pred ,y_test)*100)

# predict acc to qs 
print(" A 40-year-old American comedian, with 10 years of experience, and a comedy ranking of 7 film : ",m.predict([[40,10,7,0]]))
