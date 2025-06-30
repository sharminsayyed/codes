'''Write a Python program to calculate the average of numbers in a given list. '''

n = int(input("enter the number"));

list = []
for i in range(0, n):
    print(f"index :{i + 1}")
    ele = int(input())
    list.append(ele)

print(list)
sum =0
for i in list:
    sum = sum+i;

print(f"the sum of list is :{sum}")
print(f"the average of list is {sum/n}")
