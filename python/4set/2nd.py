'''
Write a Python program to print average of all elements of sets
'''

a = {1, 2, 3, 5, 6, 7, 8}
print(f"set :{a}")
l = len(a)
print(l)
summ = sum(a)
print(summ)
avg = summ / l
print("average of all elements of se :", round(avg,3))
