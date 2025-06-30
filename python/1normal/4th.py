'''
Q.2) Write a program to display following pattern. [20 M]
1 2 3 4
1 2 3
1 2
1
'''

# i=for rows where as j = print values j (1,n+1-i) -- staring number (in all rows) is 1
for i in range(1,5):
    for j in range(1,6-i):
        print(j,end="")
    #     To print in the same line, use the "end" parameter in the print() function and set it to an empty string.
    print()
