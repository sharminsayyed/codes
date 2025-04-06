/*Write a program in GO language to demonstrate working of slices (like append, remove, copy etc.) */

package main 
import f  "fmt"
func main(){
slice := []int{10,20,30}

slice = append(slice,40,50,60)
f.Println("afte appending :",slice)

ind := 2
slice = append(slice[:ind],slice[ind+1:]...)
f.Println("after removing a element :",slice)

slice2 := make([]int,len(slice))
copy(slice2,slice)
f.Println("copied slice :",slice2)

}
