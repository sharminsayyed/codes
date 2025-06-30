'''
Write a Python program to accept n numbers in list and remove duplicates from a list.
'''

n = int(input("how many numbers in the list :"))

list = []
for i in range(0, n):
    print(f"number {i + 1}")
    ele = int(input())
    list.append(ele)

print(f" original list is :{list}")

duplist = []
reslist = []

for i in list:
    if i not in reslist:
        reslist.append(i)
    else:
        duplist.append(i)


print(f"list without duplicate elements :{reslist}")
print(f"duplicate elements in the list :{duplist}")
