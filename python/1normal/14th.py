'''
Write a Python function to check whether a number is in a given range.
'''


def check(num, srange, erange):
    if num in range(srange, erange + 1):
        print(f"{num} is in range {srange} to {erange}")
    else:
        print(f"{num} is not in range {srange} to{erange}")


srange = int(input("enter the start range :"))
erange = int(input("enter the end range :"))
num = int(input("enter the number to be checked :"))

print(check(num,srange ,erange))