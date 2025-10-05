# . write a python program to get the number of occurrences of specified elements in an array 

import array

# arr = array.array('i',[1,2,3,4,1,1,1])
nums = input("enter the elements in array :")

arr = array.array('i',[int(x) for x in nums.split()])

n = int(input("enter the number to count occurences :"))

count = arr.count(n)

if count >0 :
    print(f" the number {n} occurs for {count} times in the arrat ")
else:
    print(f"the  number {n} is not present in the array")