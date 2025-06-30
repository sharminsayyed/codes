'''
Write a Python program to create a dictionary from a string.
Sample String: ’Hello all’
Expected output: {'e': 1, 'o': 1, 'a': 1, 'l': 4, 'H': 1}
'''

str = 'helloa'
d = {}
for char in str:
    if char in d:
        d[char] += 1
    else:
        d[char] = 1
        # dictionaryname[key] = value

print(d)