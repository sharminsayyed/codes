/*Write a program in GO language to check whether the accepted number is two digit or not. */

package main
import f "fmt"
func main(){
var n int 
f.Println("enter any number :")
f.Scan(&n)

if n>= 10 && n<=99{
f.Println(n," is two digit number ")
}else{
f.Println(n," is not two digit number ")
}

}