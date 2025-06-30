'''
Write a Python program which accepts 6 integer values and prints “DUPLICATES” if any
of the values entered are duplicates otherwise it prints “ALL UNIQUE”.
Example: Let 5 integers are (32, 10, 45, 90, 45, 6) then output “DUPLICATES” to be printed
'''
# from typing import List

list = []
for i in range(0, 6):
    print(i + 1, "number:")
    ele = int(input())
    list.append(ele)

print(list)

d = 0
for i in range(0,6):
    for j in range(i+1,6):
        if list[i] == list[j]:
            d = 1
            break

if (d == 1):
    print("DUPLICATES")
else:
    print("ALL UNIQUES")
