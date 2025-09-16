#concatenate 2 factors 
f1 = as.factor(readline("enter a factor 1:"))
f2 = as.factor(readline("enter a factor 2:"))
cat("\n factor 1 :")
print(f1)
cat("\n factor 2 :")
print(f2)
cf = factor(c(levels (f1)[f1] ,levels (f2)[f2]))
cat("\ncanacate factor :\n")
print(cf)

#enter a factor 1:1 2 3 
#enter a factor 2:1 2 3

# factor 1 :[1] 1 2 3
#Levels: 1 2 3

 #factor 2 :[1] 1 2 3
#Levels: 1 2 3

#canacate factor :
#[1] 1 2 3 1 2 3
#Levels: 1 2 3

