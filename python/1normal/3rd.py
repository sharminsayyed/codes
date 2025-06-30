'''
Write a Python program which finds sum of digits of a number. [20 M]
Example n=130 then output is 4 (1+3+0).
'''

n = int(input("enter a number"))
sum = 0
r = 0
while n > 0:
    r = n % 10
    sum = (sum) + (r)
    n = n // 10
print((sum))
# // =Divides and returns the integer value of the quotient. It dumps the digits after the decimal.
