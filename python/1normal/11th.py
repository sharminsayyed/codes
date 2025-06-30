'''
Write a Python program to accept n numbers in list. Find average of list and sort it in
descending order.
'''

n = int(input("enter the no of elements in list :"))
list = []
for i in range(0, n):
    print(f"number {i + 1}:")
    ele = int(input())
    list.append(ele)

print(f"original list is :{list}")

for i in range(0, n):
    for j in range(i + 1, n):
        if (list[i] < list[j]):
            temp = list[i]
            list[i] = list[j]
            list[j] = temp

print(f"descending sort of list :{list}")

sum=0
for i in list:
    sum = sum+i;

avg = sum/2
print(f"Averrage of list elements : {avg}")
