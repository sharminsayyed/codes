'''
Write a Python program to accept a string and from a given string where all occurrences of
its first character have been changed to '$', except the first char itself.
'''


def change_char(str1):
    char = str1[0]
    str1 = str1.replace(char, '$')
    str1 = char + str1[1:]
    # the very first character has been taken while replacing it starts from the 2 character
    # char contains the first character(0) to that is remains  same ans not replaced
    print(str1[1:])
    return str1


str1 = input("enter the string :")
str2 = change_char(str1)
print(str2)
