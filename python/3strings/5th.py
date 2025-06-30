'''
Write a python program to check if a string is a Palindrome or not.
'''

str1 = input("enter a string :")
str1 = str1.casefold()
str2 = reversed(str1)

if list(str1) == list(str2):
    print("string is palindrome")
else:
    print("string is not palindrome ")

#  orrrr
str1 = input("enter :")
print(str1[::-1])  # it basically reverses the string
# [::-1] means: Start at the end (the minus does that for you), end when nothing's left and walk backwards by 1.
if (str1 == str1[::-1]):
    print("string is palindrome ")
else:
    print("string is not palindrome ")
