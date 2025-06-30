'''Write a Sequential search function which searches an item in a sorted list. The function
should return the index of element to be searched in the list '''


def sort(list):
    n =len(list)
    for i in (0,n):
        for j in range(i+1 , n):
            if (list[i] > list[j]):
                temp = list[i]
                list[i] = list[j]
                list[j] = temp

    return list


def sequence_search(list, item):
    length = len(list)
    # print(length)
    for i in range(length):
        if (list[i] == item):
            return i
            break
    return 0


n = int(input("enter the no of elements :"))

list = []
for i in range(0, n):
    print("index", i + 1, ":")
    ele = int(input())
    list.append(ele)

'''Append in Python is essential to add a single item at the end of a list,
 array, deque, or other collection types and data structures on the go'''

print(f"list is :{list}");

list = sort(list)
print(f"sorted list is :{list}");

item = int(input("enter the item to be searched :"));

res = (sequence_search(list, item))

if res+1 == 0:
    print("item not found")
else:
    print(f"{item} is found on the position {res +1}")
