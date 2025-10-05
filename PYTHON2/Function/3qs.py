# Write a python function to check whether a number falls within a given range. 


def check_range(num ,start,end):
    if num in range (start,end +1):
        print(f"{num} is within the range {start} to {end}")
    else:
        print(f"{num} is not within the range {start} to {end}")

check_range(3,1,5)
check_range(20,10,15)
check_range(34,1,50)