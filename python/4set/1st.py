'''
Write a Python program to accept n elements in a set and find the length of a set, maximum,
minimum value and the sum of values in a set. (Don’t use built-in function)
'''

n = int(input("enter the no of elements :"))
a = set()
for i in range(n):
    ele = int(input(f"enter element {i + 1} :"))
    a.add(ele)
print(f"set :{a}")

# sum
s = 0
for i in a:
    s += i
print(f"sum of all values :{s}")

# lengthh
count = 0
for i in a:
    count += 1
print(f"the length of set : {count}")

# maximum
l = list(a)
maxi = l[0]
for i in l:
    if (i > maxi):
        maxi = i
print(f"maximum value of set :{maxi}")

# minimum
mini = l[0]
for i in l:
    if (i < mini):
        mini = i
print(f"minimum value of set :{mini}")
