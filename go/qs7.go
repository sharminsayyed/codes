/*Write a program in GO language to demonstrate function return 
multiple values. 

 Write a program in GO language to illustrate the concept of 
returning multiple values from a function. ( Add, Subtract, 
Multiply, Divide)

 Write a program in GO language  to  illustrate  the  function 
returning multiple values(add, subtract). */

package main
import f "fmt"

func operation(a,b int) (add int , sub int , mult int , div int){
add = a+b
sub = a-b
mult=a*b
div = a/b
return 
}

func main(){
var a , b int 
f.Println("enter 2 numbers:")
f.Scan(&a,&b)

add,sub,mult,div := operation(a,b)
f.Println("Addition :",add)
f.Println("Substraction :",sub)
f.Println("Multiplication :",mult)
f.Println("Division :",div)

}