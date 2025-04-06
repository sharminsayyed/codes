/*Write a Program in GO language to accept n records of employee information (eno,ename,salary) and display record of employees having maximum salary.*/
/* Write a program in GO language to accept n records of employee information (eno,ename,salary) and display records of employees having minimum salary.*/

package main 
import f  "fmt"
type emp struct {
eno int 
nm string 
sal float64
}

func main(){
var n,i,j,k int 
f.Println("enter no of employee :")
f.Scan(&n)

e:=make([]emp,n)
for i=0; i<n; i++{
f.Println("enter number , name and salary of employee ",i+1,":")
f.Scan(&e[i].eno,&e[i].nm,&e[i].sal)
}

max := e[0].sal
min:=e[0].sal
for i=0;i<n;i++{
if e[i].sal > max{
max = e[i].sal
j=i
}
if e[i].sal < min{
min= e[i].sal
k=i
}
}

f.Println("employee with maximum salary :")
f.Println("eno:",e[j].eno,"name:",e[j].nm,"salary:",e[j].sal)
f.Println("employee with minimum salary :")
f.Println("eno:",e[k].eno,"name:",e[k].nm,"salary:",e[k].sal)

}