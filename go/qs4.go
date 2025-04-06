/*Write a program in the GO language using function to check whether accepts number is palindrome or not.*/

package main
import  f "fmt"
func palindrome(n int){

num := n
sum:=0
for n>10 {
r:= n%10
sum = (sum*10)+r
n=n/10
}

if sum == num{
f.Println(num,"is palindrome")
}else{
f.Println(num,"is not  palindrome")
}

}

func main(){
var n int 
f.Println("enter a number :")
f.Scan(&n)
palindrome(n)
}

