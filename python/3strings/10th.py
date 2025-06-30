'''
Write a Python program to accept the strings which contains all vowels.
'''


def check_vowel(str1):
    str1 = str1.lower()
    vowel = set("aeiou")
    s = set({})
    for char in str1:
        if char in vowel:
            s.add(char)
        else:
            pass
    #     The pass statement is used as a placeholder for future code.
    #     When the pass statement is executed, nothing happens, but you avoid
    #     getting an error when empty code is not allowed.

    if len(s) == len(vowel):
        print(f"{str1} contains all vowels")
    else:
        print(f"{str1} does not contains all vowels")


str1 =input("enter a string :")
check_vowel(str1)