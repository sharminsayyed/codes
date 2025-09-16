# write a r program to sort list of string in ascending and desending order
l = list("zebra","cat" , "dog","cow","fox")
cat("\n original list\n")
print(l)
cat("\n ascending order :")
print(sort(unlist(l)))
cat("\n desending order : ")
print(sort(unlist(l),decreasing=TRUE))

