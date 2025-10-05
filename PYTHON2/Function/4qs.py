# Write a python function that takes a list and returns a new list with distict elements from the 
# first list 
# Sample list:[1, 2 , 2, 3, 3, 3, 3, 4, 5] 
# Unique list:[1, 2, 3, 4, 5]

def get_unique(list):
    unique=[]
    for item in list:
        if item not in unique :
            unique.append(item)
    return unique

# sample =[1,2,2,3,3,3,3,4,5]

nums = input("enter the ele in list :")
sample = [int(x) for x in nums.split()]

print("Original list :",sample)
print("Unique list :",get_unique(sample))
