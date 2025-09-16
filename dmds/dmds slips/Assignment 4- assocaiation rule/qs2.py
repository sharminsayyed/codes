#Write a Python Programme to read the dataset (“Iris.csv”). dataset download from (https://archive.ics.uci.edu/ml/datasets/iris) and apply Apriori algorithm.

#import library
import pandas as pd
from apyori import apriori

#read dataset 
db = pd.read_csv(r"F:\Sharmin\5 sem code\dmds slips\Iris.csv",on_bad_lines='skip')
# display database and shape 
print("**** dataset ***",db.head())
print("shape of the dataset ",db.shape)

#converion and printing
rec=[]
for i in range(0,105):
    rec.append( [str(db.values[i,j]) for j in range (0,6)])

print(rec)

#apply apriori
ar = apriori(rec , min_support = 0.0040 , min_cofidence = 2 , min_lift = 0.2 , min_length =3)

# conver to list 
ass_rule = list(ar)

# total no of rules 
print("total no of rules :",len(ass_rule))

#print rules
print(ass_rule)
print("rulesss : \n")
print(ass_rule[0])


