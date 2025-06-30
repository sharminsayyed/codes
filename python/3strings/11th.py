'''
Write a Python program to count the occurrences of each word in a given sentence.
'''

# veryyyyy importanttttttt

def check_word_frequency(str1):
    d1 = dict()
    str2 = str1.split()
    for w in str2:
        if w in d1:
            d1[w] += 1
        else:
            d1[w] = 1

    return d1


str1 = input("enter the string in sentence :")
print(f"frequency of each word :{check_word_frequency(str1)}")


