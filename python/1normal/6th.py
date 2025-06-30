'''
 Write a Python program to display the following pattern (Floyd's triangle)
For n=3
1
2 3
4 5 6
'''

row = int(input("enter the no of rows :"))
n = 1
print("flouds trigangle :")
for i in range(1, row + 1):
    for j in range(1, i + 1):
        # when i= 1 here i+1 = 2 (from 1,2 there will be only one iteration run only one time and one number will be printed)
        # when i= 2 here i+1 = 3 (from 1,3 there will be only two iteration run only two time and two numers will be printed)

        print(n, "\t", end="")
        n = n + 1
    print()
