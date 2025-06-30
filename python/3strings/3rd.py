'''
Write a Python program to count frequency of each character in a given string using user
defined function
'''


def check_frequency(str1):
    d1 = {}
    for c in str1:
        if c in d1:
            d1[c] = d1[c] +1
        else:
            d1[c] = 1

    return d1;


str1 = input("enter a string :")
print(f"the frequeng of each characters :{check_frequency(str1)}")
