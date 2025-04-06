/* Write a program in GO language that creates a slice of integers, checks numbers from the slice are even or odd and further sent to respective go routines through channel and display values received by goroutines. */

package main
import f "fmt"
import t "time"

func even (ch <-chan int){
for v:=range ch {
f.Println("even:",v)
}
}

func odd (ch <-chan int){
for v:=range ch {
f.Println("odd:",v)
}
}

func main(){
var slice = []int {1,2,3,4,5,8,6}

ch1 := make(chan int ,5)
ch2 := make(chan int ,5)

go even(ch1)
go odd(ch2)

for _,v := range slice {
if v % 2 == 0 {
ch1 <- v 
}else {
ch2<-v
}
}


t.Sleep(t.Second)
}



