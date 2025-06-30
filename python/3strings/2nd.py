'''
Write a Python function to get a string made of the first 2 and the last 2 chars from a given
string. If the string length is less than 2, it returns empty string.
Sample String: 'General12' Expected Result: 'Ge12'
Sample String: 'Ka' Expected Result: 'KaKa'
Sample String: ' K' Expected Result: Empty String
'''


def get_string(string):
    if len(string) < 3:
        print("the new string is :empty")
    else:
        print(f"the new string is :{string[0:2] + string[-2:]}")


string = input("enter the string :")
get_string(string)
