#create a data frame contains 5 employee and display the summary
eno = c(101:105)
ename = c("sharmin","laxmi","iqra","sushama","priya")
gen =c ("F","F","F","F","F")
age = c(23,34,45,12,33)
desg = c("developer","manager","clerk","worker","clerk2")
df = data.frame(eno,ename,gen,age,desg)

cat ("\n employee details \n")
print(df)
cat("\n summary \n")
print(summary(df))
