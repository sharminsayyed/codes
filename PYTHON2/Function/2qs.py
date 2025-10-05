# Write a python function to calculate the factorial of a number.the function accept the number 
# as an argument. 

def factorial(number):
    fact=1
    for i in range (1,number+1):
        fact *= i
    return fact 

num = int(input("enter a number :"))

res = factorial(num)

print(f"Factorail of {num} : {res}")