'''
Write a Python program to perform given operations on set. [20 M]
a. check whether 2 sets are equal or not
b. Symmetric difference
c. Intersection of sets
d. Find maximum and the minimum value in a set.
'''


# equal or not
set1=set(input("enter the values of set1 :"))
print(f"set1 :{set1}")
set2=set(input("enter the values for set2 :"))
print(f"set2 :{set2}")
print(set1 == set2 )

# symmetric difference
set3 = set1.symmetric_difference(set2)
print(f"symmetric  difference :{set3}")

# intersection
set4 = set1.intersection(set2)
print(f"intersection :{set4}")

# maximum
set5 = max(set1)
print(f"maximum of set1 :{set5}")
set5 = min(set1)
print(f"minimum of set1 :{set5}")

# ORRRRRRRRRRRRRRRRRRRRR IMPTTTTTTTTTT
set1 = set(input("enter set 1:"))
set2 = set(input("enter set 2:"))
print(f"original set 1 :{set1}")
print(f"original set2 :{set2}")
print(f"set1 and set2 are equal : {set1 == set2}")

print(f"symmetric difference  : {set1.symmetric_difference(set2)}")
print(f"intersection of 2 set :{set1.intersection(set2)}")
print(f"union of 2 sets :{set1.union(set2)}")
print(f"difference set1 :{set1.difference(set2)}")
print(f"difference set2 :{set2.difference(set1)}")