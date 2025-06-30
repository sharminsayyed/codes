'''
 Write a function to calculate the sum of numbers from 0 to n.
'''


def add(n):
    s = 0
    for i in range(0, n + 1):
        s = s + i;

    return s


n = int(input("enter  a number :"))

sum = add(n)
print(f"sum of 0 to {n} numbers :{sum}")
