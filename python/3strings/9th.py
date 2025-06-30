'''
Write a Python program to accept string and remove the characters which have odd index
values of a given string using user defined function
'''


def remove_odd(str1):
    result = ""
    for i in range(len(str1)):
        # if i % 2 != 0:
        if i % 2 == 0:
            result = result + str1[i]

    return result


str1 = input("enter the string :")
print(remove_odd(str1))

