'''
Write a Python program to print a dictionary where the keys are numbers between 1 and
15 (both included) and the values are square of keys.
Sample Dictionary: {10: 100, 20: 400, 30: 900, 40: 1600, 50: 2500}
'''

n = int(input("enter a number between 1 to 15 :"))
d = {}
for x in range(1, n + 1):
    d[x] = x * x

print(d)
