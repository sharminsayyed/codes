'''
Write a Python program to create a set with any 3 weekdays. Add single element to the set
and print it. Add multiple elements and print the set
'''

# use this when user input is asked
# n = int(input("enter the no of elements in set:"))
# weekdays = set()
# for i in range(n):
#     ele = (input(f"enter element {i + 1}"))
#     weekdays.add(ele)

weekdays ={"monday","tuesday","wednesday"}
print(f"original set : {weekdays}")
# add a single element
weekdays.add("thursday")
print(f"see set after adding a single element ;{weekdays}")
multiple = {"friday","saturday","sunday"}
weekdays.update(multiple)
print(f"see set after adding a multiple element ;{weekdays}")
