'''
 Write a Python program to check if a given key already exists in a dictionary. If key exists
replace with another key/value pair.
'''


d = {}
n = int(input("enter the number of entries u want ?"))
for i in range(n):
    key = input("enter key :")
    value = input("enter value :")
    d[key] = value

print(d)

key = input("enter the key to find :")
if key in d.keys():
    print(f"the key {key} exists and the values is {d[key]}")
    d.update({4: 90})
    d.pop(key)                          #
    print(f"after replacing :{d}")

else:
    print(f"the key {key} does not exists")


