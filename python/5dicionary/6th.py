'''
Write a Python program to create and display all combinations of letters, selecting each
letter from a different key in a dictionary. [20 M]
Sample data: {'1':['a','b'], 2':['c','d']}
Expected Output:
ac
ad
bc
bd
'''

dict = {'1': ['a', 'b'], '2': ['c', 'd']}
print(dict.values())
my_list = list(dict.values())
print(my_list)
for i in my_list[0]:
    for j in my_list[1]:
        print(i+j)