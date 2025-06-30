'''
Write a Python program to create tuple of n numbers, print the first half values of tuple in
one line and the last half values of tuple on next line.
'''

n =int(input("enter the number :"))
tuple1=()
list1=[]
for i in range (0,n):
    print(f"index {i+1} :")
    ele = int(input())
    list1.append(ele)

tuple1 = tuple(list1)
print(f"tuple is :{tuple1}")

tp1 = tuple1[:n//2]
tp2 =tuple1[n//2:]
print(f"first half value of tuples :{tp1}")
print(f"last half values of tuple :{tp2}")

# ORRRRRRRRRRRRRRRRRRRRRR
t = (1,2,3,4,5,6)
t1 = t[:3]
t2 = t[3:]
print(t1)
print(t2)