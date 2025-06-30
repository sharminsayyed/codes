'''
Write a Python program which accepts an integer value ‘n’ and display all prime
numbers till ‘n’
'''

# VERYYYYYYYYYYYYY IMPORTANTTT

n = int(input("enter a number"));

print(f"prime numer from 1 to {n}");

for num in range(1, n + 1):
    if num > 1:
        for i in range(2, num):
            if num % i == 0:
                break
        else:
            print(num)
