'''
Write a program which prints Fibonacci series of a number
'''

num = int(input("how many fibonacci terms the user wants to print:"))

n1 = 0
n2 = 1
cnt = 0

if num < 0:
    print("enter a positive number ")
elif num == 1:
    print(f"fibonacci seriees upto {num} number is :")
    print(n1)
else:
    # the main logic for series
    print(f"fibonacci seriees upto {num} number is :")
    while cnt < num:
        print(n1)
        nth = n1 + n2
        # update the value of n1 n2 and n3
        n1 = n2
        n2 = nth
        cnt = cnt + 1
