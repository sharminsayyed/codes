/*Write a program in GO language  to sort array elements in ascending order.*/

package main 
import f  "fmt"
func main(){
var n,i,j  int 
f.Println("enter the no of element in array :")
f.Scan(&n)

a:=make([]int ,n)
f.Println("enter the elements:")
for i=0 ;i<n ;i++{
f.Scan(&a[i])
}

for i=0; i<n; i++{
for j= i+1; j<n; j++{
if a[i] > a[j] {
a[i] ,a[j] = a[j],a[i]
}
}
}

f.Println("sorted array :")
for i=0 ; i<n; i++{
f.Print(a[i],"\t")
}

}
