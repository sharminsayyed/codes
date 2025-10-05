    #   2. Write a Python script to generate and print a dictionary that contains a number (Between 
    #          1 and n) in the form (x, x*x). 
    #            Sample Dictionary (n = 5) 
    #            Expected Output : {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}

num = int(input("enter a  number :"))
d={}
for i in range (1,num+1):
    key = i
    value = i*i
    d[key] = value

print(d)