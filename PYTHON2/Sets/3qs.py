#  Write a Python program to add and remove operation on set.

s = {10,20,30,40,50}
print("original set :",s)
s.add(60)
print("after adding a value :",s)
s.remove(30)
s.discard(20)
print("after removing a value :",s)