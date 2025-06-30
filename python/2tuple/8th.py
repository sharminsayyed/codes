'''
Write a Python program to find the repeated items of a tuple
'''

tup = ("hi",1,2,3,"welcome","hi",1,2)
t1=[]
temp =0
for i in tup:
  temp=tup.count(i)
  if temp >1 and i not in t1:
      t1.append(i)


print(t1)