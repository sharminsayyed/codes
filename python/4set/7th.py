'''
Write a Python program to find set difference, union, intersection and symmetric
difference.
'''

# unordered noduplicate

# symmetric_difference --The set which contains the elements which are either in
# set A or in set B but not in both is called the symmetric difference between two given sets
set1 = set(input("enter the values in set 1 :"))
print(f"original set 1 :{set1}")
set2 = set(input("enter the values in set 2 : "))
print(f"original set 2  :{set2}")
set3 = set1.symmetric_difference(set2)
print(f"symmetric difference : {set3}")

# difference() -- difference with 2 sets
set4 = set1.difference(set2)
print(f"difference btw set1 and set2 : {set4}")
set4 = set2.difference(set1)
print(f"difference btw set2 and set1 : {set4}")


# union = all elements from both the sets
set5 = set1.union(set2)
print(f"union : {set5}")

# intersection()--The intersection between two sets, results in a third set that contains the elements present in both
set6 = set1.intersection(set2)
print(f"intersection : {set6}")