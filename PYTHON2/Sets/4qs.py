# Write a Python program to find maximum and the minimum value in a set. 

nums = input("enter the ele in th set :")

s =set()
for x in nums.split():
    s.add(int(x))

# s = {1,2,3,4,5}

maxval = max(s)
minval = min(s)

print("Maximum value :",maxval)
print("minimum value :",minval)

