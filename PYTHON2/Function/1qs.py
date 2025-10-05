# Write a python function to sum of all the elements in a list 


def list_sum(numbers):
    total =0
    for num in numbers :
        total += num
    return total 

nums  = input("enter elements in the list :")

l = [int (x) for x in nums.split()]

res = list_sum(l)

print("Sum of list element :",res)