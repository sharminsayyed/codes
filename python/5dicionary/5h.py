'''
Write a Python program to match key values in two dictionaries. [20 M]
Sample dictionary: {'key1': 1, 'key2': 3, 'key3': 2}, {'key1': 1, 'key2': 2}
Expected output: key1: 1 is present in both x and y
'''

a = {'key1': 1, 'key2': 2, 'key3': 3, 'key6': 5}
b = {'key1': 3, 'key2': 2, 'key3': 4, 'key6': 5}

for key in a and b:
    if a[key] == b[key]:
        print(f"{key} = {b[key]} present  in both the dictionary")
