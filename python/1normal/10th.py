'''
) Write a Python program to reverse a given number.
'''

n = int(input("enter a number:"))
r = 0
sum = 0
while n > 0:
    r = n % 10
    sum = sum * 10 + r
    n = n // 10

print(f"reverse of a given number :{sum}")
# // =Divides and returns the integer value of the quotient. It dumps the digits after the decimal.
