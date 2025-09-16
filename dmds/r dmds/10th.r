#print 1st 10 fibinacci series 
cat("\n  1st 10 fibinacci series \n")
n1=0
n2=1
cat(n1,"\t",n2,"\t")
for(i in 3:10)
{
	nth = n1+n2
	cat ( nth	,"\t")
	n1 = n2
	n2 =nth
}
