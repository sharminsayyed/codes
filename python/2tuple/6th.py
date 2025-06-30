'''
Write a Python program to display occurrence of the elements in the tuple, which appears
more than 2 times.
'''

temp = 0
tup = (6, 1, 2, 3, 4, 5, 6, 6, 5, 5)
t1 = []
for i in tup:
    temp = tup.count(i)
    # print(temp)
    if temp > 2 and i not in t1:
        t1.append(i)

print(t1)


# // orrrrrr for 20 marks


my_dict = {'1': ['a', 'b'], '2': ['c', 'd']}
print(my_dict.values())
my_list = list(my_dict.values())
print(my_list)
for i in my_list[0]:
    for j in my_list[1]:
        print(i + j)
