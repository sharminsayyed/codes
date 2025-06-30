'''
Write a Python program to unpack a tuple in several variables. Display type of each
variable
'''

student = ("sharmin", 19, "hv desai", "pune", "maharashtra", 30.90, True)
(name, age, college, city, state, salary, education) = student
print(f"name :{name}")
print(f"Type :{type(name)}")
print(f"age :{age}")
print(f"Type :{type(age)}")
print(f"college :{college}")
print(f"Type :{type(college)}")
print(f"city :{city}")
print(f"Type :{type(city)}")
print(f"state :{state}")
print(f"Type :{type(state)}")
print(f"salary :{salary}")
print(f"Type :{type(salary)}")
print(f"education :{education}")
print(f"Type :{type(education)}")
