'''
 Write a Python program to create a tuple of n numbers and print maximum, minimum, and
sum of elements in a tuple.
'''

t=()
l=[]
n =int(input("enter the number:"))
for i in range(0,n):
    print(f"index {i+1}:")
    ele = int(input())
    l.append(ele)

t=tuple(l)

# orrrrrr
# t = (1,2,3)

maximum = max(t)
mini = min(t)
summ = sum(t)
print(f"tuple is :{t}")
print(f"maximum element :{maximum}")
print(f'minimum element :{mini}')
print(f"sum of elements :{summ}")