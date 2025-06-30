'''
Write a Python program to remove special symbols/Punctuation from a given string.
'''

# define punctuation
pun = '''\?/<>.,;;"'{}[]()_+-*&^%$#@!~'''
print(pun)
# To take input from the user
str = input("enter the string :")  # hey !!! how,, are yo ?? or "\sachin is @criketer && a kind person"

# remove punctuation from the string
no_pun = " "
for char in str:
    if char not in pun:
        no_pun = no_pun + char

# display the unpunctuated string
print(no_pun)
