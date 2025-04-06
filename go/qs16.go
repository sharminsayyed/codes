/*Write a program in GO language to copy all elements of one array into another using a method. */

package main
import f  "fmt"

type array struct {
a1[5]int 
}

func (a array) copyarray(a2[5]int){
a.a1 = a2
f.Println("copies array :",a.a1)
}
func main(){
var a array 
var a2 = [5]int{10,20,30,40,50}
f.Println("original array :",a2)
a.copyarray(a2)
}

