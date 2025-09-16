#print multiplication table
disptable = function(n)
{   for(i in 1 :10)
{
cat ( n ,"*",i,"=",n*i,"\n")
}}
nums = as.integer(readline("enter a number :"))
disptable(nums)