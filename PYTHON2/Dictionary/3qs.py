#  3. Write a Python program to create a dictionary from a string. 
#              Sample-String:’W3resource’ 
# Expected output: {'3': 1, 's': 1, 'r': 2, 'u': 1, 'w': 1, 'c': 1, 'e': 2, 'o': 1} 

str = "W3resource"
d={}
for char in str :
    if char in d:
        d[char] += 1
    else:
        d[char]=1

print(d)