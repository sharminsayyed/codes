//Write a program in GO language to accept user choice and print answers using arithmetic operators. 

package main
import f "fmt"
func main(){
var a,b int 
f.Println("enter 2  number :")
f.Scan(&a,&b)
var ch string
f.Println("enter your choice (+,-,*,/):")
f.Scan(&ch)
switch(ch){
case "+":f.Println("Addition :",a+b)
case "-":f.Println("substraction :",a-b)
case "*":f.Println("multiplication :",a*b)
case "/":f.Println("division :",a/b)
}
}
