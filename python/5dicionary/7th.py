'''
Write a Python program to create a dictionary from two lists without losing duplicate
values.
Sample lists: ['Class-V', 'Class-VI', 'Class-VII', 'Class-VIII'], [1, 2, 2, 3]
Expected Output: defaultdict(<class 'set'>, {'Class-VII': {2}, 'Class-VI': {2}, 'Class-VIII':
{3}, 'Class-V': {1}})
'''

keylist =  ['Class-V', 'Class-VI', 'Class-VII', 'Class-VIII']
valuelist = [1, 2, 2, 3]

print(f"the key list :{keylist}")
print(f"the value list :{valuelist}")

d={}
for key in keylist:
    for value in valuelist:
        d[key] = value
        valuelist.remove(value)
        break


print(f"dictionary is :{d}")


# seee orrr one also