// Write a program in GO language to print a multiplication table of number using function. 

package main 
import f "fmt"
func mult(n int){
f.Println("multiplication table of ",n,":")
for i:=1 ;i<= 10;i++{
f.Println(n,"*",i,"=",n*i)
}
}
func main(){
var  n int 
f.Println("enter a number:")
f.Scan(&n)
mult(n)
}
