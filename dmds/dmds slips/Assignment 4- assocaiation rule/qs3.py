#Write a Python program to read “StudentsPerformance.csv” file. 
# Solve following: - To display the shape of dataset. - 
# To display the top rows of the dataset with their columns. Note: Download

import pandas as pd 

#read dataset 
db = pd.read_csv(r"F:\Sharmin\5 sem code\dmds slips\StudentsPerformance.csv")

#shape
s = db.shape
print("shape of the dataset :",s)

# print top and bottom 10 rows 
print("top rows :",db.head(10))
print("bottom rows :",db.tail(10))

#random row 
print("random rows  :",db.sample(5))

#no of columns and column name 
print(" no of columns :",s[1])
print("names of columns",db.columns.values)