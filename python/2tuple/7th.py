'''
Write a Python program to sort the tuple T=(4,2,6.8,1.8,10)
'''

# T = (4, 2, 6.8, 1.8, 10)
# s = sorted(T)
# print(s)

# or use list for sorting
T = (4, 2, 6.8, 1.8, 10)
l = list(T)
# print(l)
l.sort()
print(l)
T = tuple(l)
print(T)
