#Write a program which accepts 6 integer values and prints “DUPLICATES” if any of the 
#values entered are duplicates otherwise it prints “ALL UNIQUE”. Example: Let 5 integers 
#are (32, 10, 45, 90, 45, 6) then output “DUPLICATES” to be printed.
nums =[]
for i in range(5):
    n = int(input ("enter number "+ str(i+1) +" :"))
    nums.append(n)

if len(nums) != len(set(nums)):
    print("DUPLICATES")
else:
    print("UNIQUE")