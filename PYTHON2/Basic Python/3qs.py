#3) Write a program to display following pattern. 
            
row = 4
num =1
for i in range(1 ,row+1):
    for j in range(i):
        print(num , end=" ")
        num+=1
    print()