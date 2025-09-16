#Write a Python Programme to apply Apriori algorithm on Groceries dataset. Dataset can be downloaded from Also display support and confidence for each rule. 

#import library
import pandas as pd 
from apyori import apriori 
#read dataset 
db=pd.read_csv(r"F:\Sharmin\5 sem code\dmds slips\Groceries_dataset.csv",on_bad_lines='skip')

#print the dataset and shape 
print("dataset :",db.head())
print("shape of the dataset :",db.shape)

#conversion amd display
rec =[]
for i in range(0,250):
    rec.append([str(db.values[i,j]) for j in range(0,3)])

# print(rec)

#apply apriori
ar = apriori(rec , min_support =0.0040 ,min_confidence = 2, min_lift =0.2 , min_length =3)
# ar= apriori(rec)

#convert to list
ass_rule = list(ar)

#no of rules 
print("total no of rules :",len(ass_rule))

# print rules 
print(ass_rule)
print(ass_rule[0])