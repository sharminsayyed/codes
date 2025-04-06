/*Write a program in GO language to read and write Fibonacci series to the using channel. */

package main
import f "fmt"
import t "time"

func show (ch<- chan int ){
for v:= range ch {
f.Println(v)
}
}

func main(){
var n1 ,n2 , n int 
f.Println("enter no of elements in fibo series :")
f.Scan(&n)
n1=0
n2=1

ch := make(chan int ,n)
ch<-n1
ch<-n2 

for i:= 3; i<=n; i++{
nth := n1+n2
ch<- nth 
n1,n2 = n2,nth 
}

f.Println("fibo series :")
go show(ch)
t.Sleep(t.Second)
}
