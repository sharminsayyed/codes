# 1. Write a python program to create an array of 5 integers and display the array elements. Access 
# individual elements through indexes 

import array

arr = array.array('i' ,[10,20,30,40,50])

print("Array : ",arr)
print("Array :",list(arr))

for i in range(len(arr)):
    print(f"Element at index {i} :" ,arr[i])