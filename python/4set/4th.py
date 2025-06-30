'''
Write a Python program to print the set difference and a symmetric difference of two sets
'''

set1 =set(input("enter the values for set :"))
print(f"set1 :{set1}")
set2 =set(input("enter the values for set2 :"))
print(f"set2 :{set2}")

# symmetric difference
set3= set1.symmetric_difference((set2))
print(f"symmetric difference : {set3}")

# set difference
set4 = set1.difference(set2)
print(f"difference btw set1 and set2 :{set4}")
set4=set2.difference(set1)
print(f"difference btw set2 and set1 :{set4}")