# create  a data frame using 2 vectors and display duplicate rows 
v1 = c(10,20,30,40,10,20)
v2=c("a","b","c","d","a","e")
df = data.frame(v1,v2)
print(df)
cat("\n duplicated element :\n")
print(duplicated(df))