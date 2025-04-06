package cal 
import f "fmt"

func Calculate(){
var a,b int 
f.Println("enter the 2 numbers for calculation :")
f.Scan(&a,&b)
var ch string 
f.Println("enter ur choice for the operation (+,-,*,/) :")
f.Scan(&ch)
switch(ch){
case "+" : f.Println("addition :",a+b)
case "-" : f.Println("subtraction :",a-b)
case "*" : f.Println("multiplication :",a*b)
case "/" : f.Println("division :",a/b)
default : f.Println("invalid operations ")
}
}