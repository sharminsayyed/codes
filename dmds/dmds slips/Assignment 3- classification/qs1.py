#Write a Python program build Decision Tree Classifier using Scikit-learn  package for diabetes data set (download database from  https://www.kaggle.com/uciml/pima-indians-diabetes-database)
# 
# steps u need to understand 

# import libraries 
import pandas as pd 
from sklearn.model_selection import train_test_split as tts

#read database
db = pd.read_csv(r"F:\Sharmin\5 sem code\dmds slips\diabetes.csv")

#display database 
print("\n **** database **** \n",db.head())

#identify x and y 
x = db.iloc[:,:-1] 
y = db.iloc[:,-1]
#display the top rows of a and y 
print(" \n **** x database  *** \n",x.head())
print("\n **** y database ****\n",y.head())

#split the x and y in train and test
x_train,x_test,y_train,y_test = tts(x,y,test_size =0.2,random_state=1)
#display train and  test data 
print("\n *** training  set od x **** \n",x_train)
print("\n **** testing set of x ***\n",x_test)
print("\n **** training set of y ****\n",y_train)
print("\n ***** testing set of y ****\n",y_test)

# import decision tree
from sklearn.tree import DecisionTreeClassifier as dtc

# build model
m = dtc()

#train the model by fitting 
m = m.fit(x_train,y_train)

#predict by using the model 
y_pred = m.predict(x_test)

#print the predicted and original dataset of y
print("\n ** predicted vaule *** \n",y_pred)
print("\n **** original values of y *** \n",y_test)

# check the accuraccy
from sklearn import metrics 
print("accuracy :",metrics.accuracy_score(y_pred,y_test)*100)




