/*Write a program in GO language to print Fibonacci series of n terms.*/

package main
import f "fmt"
func main(){

var n,i int 
f.Println("enter the no of element in fibo series :")
f.Scan(&n)

n1:=0
n2:=1
f.Println("fibo series:")
f.Print(n1,"\t",n2,"\t")

for i=3 ;i<= n;i++{
nth:= n1+n2 
f.Print(nth,"\t")
n1,n2=n2,nth
}

}

