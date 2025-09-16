#Consider following dataset 
#weather=['Sunny','Sunny','Overcast','Rainy','Rainy','Rainy','Overcast','Sunny','Sunny','Rainy','Sunny','Overcast','Overcast','Rainy'] 
# temp=['Hot','Hot','Hot','Mild','Cool','Cool','Cool','Mild','Cool','Mild','Mild','Mild','Hot','Mild'] 
#play=['No','No','Yes','Yes','Yes','No','Yes','No','Yes','Yes','Yes','Yes','Yes','No']. 
# Use Naïve Bayes algorithm to predict[ 0:Overcast, 2:Mild] tuple belongs to which class whether to play the sports or not. 

#import libraries 
import pandas as pd 
# write data
data ={'weather' :['Sunny','Sunny','Overcast','Rainy','Rainy','Rainy','Overcast','Sunny','Sunny','Rainy','Sunny','Overcast','Overcast','Rainy'],
        'temp':['Hot','Hot','Hot','Mild','Cool','Cool','Cool','Mild','Cool','Mild','Mild','Mild','Hot','Mild'],
        'play':['No','No','Yes','Yes','Yes','No','Yes','No','Yes','Yes','Yes','Yes','Yes','No']
        }

# arrange the data in dataframe 
db=pd.DataFrame(data)
#display data 
print("******* dataframe *******",db.head())

# convert categorical into numerical
w = {'Overcast':0,'Sunny':1,'Rainy':2}
db['weather'] = db['weather'].map(w)
t = {'Hot':0,'Cool':1,'Mild':2}
db['temp'] = db['temp'].map(t)
p = {'No':0,'Yes':1}
db['play'] = db['play'].map(p)
# check if everything is map 
print("\n ** dataset *** :",db.head())

# identify x and y and display 
x=db.iloc[:,:-1]
y=db.iloc[:,-1]
print("\n **** dataset of x  **** \n",x.head())
print("\n *** data set of y ** \n",y.head())

# slipt x and y in train and test and display 
from sklearn.model_selection import train_test_split as tts 
x_train,x_test,y_train,y_test = tts(x,y,test_size =0.2)
print("\n *** training set of x ****",x_train)
print("\n **** testing set of x ****",x_test)
print("\n **** training set od y ****",y_train)
print("\n **** testing set of y *****",y_test)

# import naivebayes 
from sklearn.naive_bayes import GaussianNB as gnb
#build model
m = gnb()
#train the model
m = m.fit(x_train,y_train)
# predict the values using the model
y_pred = m.predict(x_test)
# print the predicted and original values 
print("predicted valuees  : ",y_pred)
print("original values  :",y_test)

#acuracy cjeck 
from sklearn import metrics 
print("accuracy:",metrics.accuracy_score(y_pred,y_test)*100)

# predict for qs 
print("play :",m.predict([[0,2]]) )






 
