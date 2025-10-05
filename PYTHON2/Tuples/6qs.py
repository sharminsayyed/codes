# Write a Python program to check whether an element exists within a tuple. 

tups = input("enter the elemenets :")
tuplist =[] # in tuple we cannot append ele so we used list 
for x in tups.split():
    tuplist.append(int(x))

tup = tuple(tuplist)

# tup = (1,2,5,6,7)
num = int(input("enter the no to find :"))
if num in tup :
    print(num," exists in the tuple")
else:
    print(num," does not exists in the tuple")