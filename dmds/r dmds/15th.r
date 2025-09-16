# to find all the elements in the given list that are not in another list 
l1 = list("X","Y","Z","x","y","z")
l2 = list("x","y","z")
v1 = unlist(l1)
v2=unlist(l2)
cat("\n element present in one list but not in another : \n")
print(setdiff(v1,v2))