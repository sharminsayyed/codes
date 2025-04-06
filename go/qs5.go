/*Write a program in GO language to print a recursive sum of digits of a given number. */

package  main 
import f "fmt"

func sumofd(n int ) int {
if n<10{
return n
}
return (n%10) + sumofd(n/10)
}

func main(){
var n int 
f.Println("enter a number(positive only):")
f.Scan(&n)
ans:= sumofd(n)
f.Println("sum of ",n,":",ans)
}
