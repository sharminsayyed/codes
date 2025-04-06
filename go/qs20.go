/*Write a program in GO language to create an interface and display its values with the help of type assertion.*/

package main
import f "fmt"
func main(){
var val interface{}
val ="sharmin"

_,ok := val.(int)
if ok {
f.Println("integer recieved ")
}else{
f.Println("no integer recieved ")
}

_,ok = val.(string)
if ok {
f.Println("string recieved ")
}else{
f.Println("no string recieved ")
}

_,ok = val.(bool)
if ok {
f.Println("boolean recieved ")
}else{
f.Println("no boolean recieved ")
}

_,ok = val.(float32)
if ok {
f.Println("float32 recieved ")
}else{
f.Println("no float32 recieved ")
}

_,ok = val.(float64)
if ok {
f.Println("float64 recieved ")
}else{
f.Println("no float64 recieved ")
}

}