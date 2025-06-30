'''
 Write a Python function to multiply all the numbers in a list. [20 M]
Sample-List: (8, 2, 3, -1, 7)
Expected Output: -336
'''

def multiply(list):
    m=1
    for i in list:
        m = m*i
    print(f"multiplication of all elements :{m}")


n = int(input("enter a no of elements in list :"))
list=[]

for i in range (0,n):
    print(f"number {i+1}:")
    ele =int(input())
    list.append(ele)

print(f"list :{list}")

multiply(list)