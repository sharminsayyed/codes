/*Write a program in GO language to swap two numbers using call by reference concept*/

package main
import f "fmt"
func swap (a,b *int){
temp:= *a
*a=*b
*b=temp
}
func main(){
var a,b int 
f.Println("enter 2 numbers :")
f.Scan(&a,&b)
f.Println("before swapping a=",a,",b=",b)
swap(&a,&b)
f.Println("After swapping a=",a,",b=",b)
}