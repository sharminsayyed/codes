'''
Write a Python program to generate and print a dictionary that contains a number (between
1 and n) in the form (x, x*x).
Sample Dictionary (n = 5)
Expected Output: {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}
'''

n = int(input("enter a number :"))
d = {}
for x in range(1, n + 1):
    key = x
    value = x * x
    d[key] = value
    # dictionaryname[key] = value

print(d)
