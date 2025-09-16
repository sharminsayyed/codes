# pie diagram
digits  = c(1,2,3,4,5,6)
freq = c(7,2,6,3,4,8)
df = data.frame(digits ,freq)
print(df)
per = round(100 * (df  $freq/sum ( df $freq)))
pie (df $freq ,label=paste(df $ digits , sep="-",per,"%") , main = "frequency of digits" ,col = c("pink","green","black","blue","yellow","red"))