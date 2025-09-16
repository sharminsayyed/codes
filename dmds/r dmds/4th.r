#display employee names , add an employye name ,  remove an employee name 
emp = list("sharmin", "iqra","laxmi","priya")
cat("employee name :\n")
print(emp)
emp = append(emp,"pooja")
cat("\n after adding a new employee :\n")
print(emp)
emp[[3]] = NULL;
cat("\n after removing an employee :\n")
print(emp)

