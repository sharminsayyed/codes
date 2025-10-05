
#Write a Python Program to Calculate the Average of Numbers in a Given List.
n = input("enter the no in the list :")
nl= []
for x in n.split():
    nl.append(int(x))
avg = sum(nl) / len(nl)
print("Average :",avg)