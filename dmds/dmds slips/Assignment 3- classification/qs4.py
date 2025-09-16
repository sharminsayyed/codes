# Write a Python program to build SVM model to Cancer dataset.  The dataset is available in the scikit-learn library.
#  Check the accuracy of model with precision and recall.

#import library
import pandas as pd 
#read dataset 
db = pd.read_csv(r"F:\Sharmin\5 sem code\dmds slips\cancer.csv")

#This code will drop the diagnosis(1=m,0=b) column from the DataFrame db to form the features (X),
#  while the dropped column becomes the target variable (y).
# axis=1: This tells pandas to drop a column (or columns).
print(db.columns)
x =db.drop('diagnosis(1=m, 0=b)',axis = 1)
y =db['diagnosis(1=m, 0=b)']

print("\n dataset of x :\n",x.head())
print("\n dataset of y :\n",y.head())

# slipt x and y in training and testing and display
from sklearn.model_selection import train_test_split as tts 
x_train,x_test,y_train,y_test = tts(x,y,test_size=0.2)
print("\n *** training set of x ****",x_train)
print("\n **** testing set of x ****",x_test)
print("\n **** training set od y ****",y_train)
print("\n **** testing set of y *****",y_test)

# import svm 
from sklearn import svm 

#build model
m = svm.SVC(kernel='linear')
#svm.SVC: This initializes a Support Vector Machine (SVM) classifier. SVMs are commonly used for classification tasks.
#kernel='linear': This specifies that the SVM should use a linear kernel, which is suitable when the data can be separated by
#  a straight line (or hyperplane in higher dimensions). This kernel is often effective for linearly separable data.

# train the model
m = m.fit(x_train,y_train)

# predict the value 
y_pred = m.predict(x_test)

# display the original and predicted value 
print("predicted value :",y_pred)
print("original value :",y_test)

#check accuracy 
from sklearn import metrics
print("acuracy :",metrics.accuracy_score(y_pred,y_test)*100)

#precision and recall
print("precision :",metrics.precision_score(y_pred,y_test)*100)
print("recall :",metrics.recall_score(y_pred,y_test)*100)
