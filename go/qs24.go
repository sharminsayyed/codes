/* Write a program in GO language using go routine and channel that will print the sum of the squares and cubes of the individual digits of a number.
 Example if number is 123 then 
squares = (1 * 1) + (2 * 2) + (3 * 3) 
cubes = (1 * 1 * 1) + (2 * 2 * 2) + (3 * 3 * 3). */

package main
import f "fmt"
import t "time"

func getsum(n int)(int ,int , int){
rem :=0 
sumsq:=0
sumcb:=0
for n>0{
rem = n%10
sumsq = sumsq+(rem*rem)
sumcb = sumcb+(rem*rem*rem)
n = n/10
}
totalsum:= sumsq +sumcb
return sumsq ,sumcb ,totalsum
}

func show( ch chan int){
f.Println("sum :",<-ch)
}

func main(){
var n int 
f.Println("enter any number :")
f.Scan(&n)

s1,s2,s3:= getsum(n)

ch := make(chan int ,1)

ch<-s1
go show(ch)
ch<-s2
go show(ch)
ch<-s3
go show(ch)

t.Sleep(t.Second)
}





	