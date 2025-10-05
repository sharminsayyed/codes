# 5. Write a Python program to find the repeated items of a tuple.

tup=(1,2,3,4,2,3,5,6,7,1)
repeated=[]
for i in tup :
    if tup.count(i) >1 and i not in repeated :
        repeated.append(i)

print("repeated element :",repeated)