#Write a Python program to create a list of tuples with the first element as the number and 
#second element as the square of the number.  

n = int(input("enter the no of elements :"))
listoftuples =[]
for i in range (1,n+1):
    listoftuples.append((i,i*i))

print("list of tuple :",listoftuples)


num  = input("enter the numbers :")
numlist=[]
for x in num.split():
    numlist.append(int(x))
listoftuple=[]
for i in  numlist:
    listoftuple.append((i,i*i))
print("List of tuples :",listoftuple)

