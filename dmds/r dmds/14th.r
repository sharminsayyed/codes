# bar plot 
y = c(2001,2001,2002,2002,2003,2003)
df = data.frame(year=c(2001,2002,2003), export =c(23,34,55) , import=c(35,45,12))
cat("\n dataframe \n")
print(df)
barplot(c ( df $export, df $import ) , main="export and import" ,names.arg=year, xlab="years" , ylab="export and import", col =c("pink","purple") , beside=TRUE)

df = data.frame(year=c(2001,2002,2003), export=c(26,32,35) , import=c(35,40,50))
print(df)
barplot(
    c(df$expor , df$import),
    main = "export and import",
    names.args = df$year,
    xlab = "export and import",
    ylab = "years",
    col=c("black","blue"),
    beside =TRUE
)