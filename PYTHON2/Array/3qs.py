# .Write a python program to reverse the order of the items in the array

import array
nums = input("enter the elements of array :")
arr = array.array('i',[int (x) for x in nums.split()])
print("Original array :",list(arr))
# arr.reverse()
# print("Reversed array :",list(arr))

rev = array.array('i',[])

for i in range (len(arr) -1 ,-1,-1): #(start ,stop, step) (4 index start , -1 (0) index stop  , -1 decrement)
    rev.append(arr[i])

print("Reversed array :",list(rev))

