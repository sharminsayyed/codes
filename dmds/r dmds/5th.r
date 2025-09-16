# reverse a number and calculate the sum of the digit
n = as.integer (readline("enter a number :"))
rev=0
sum=0
while(n>0)
{
	rem = n%%10
	sum = sum+rem
	rev = rev*10 + rem
	n = n%/%10
}
cat ("\n reverse =" ,rev,"summ =",sum)

