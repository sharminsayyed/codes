/* Write a program in Go language how to create a channel and illustrate how to close a channel using for range loop and close function. */

package main 
import f "fmt"

func send(ch chan int){
for i:= 0;i<5;i ++{
ch <-i
}
close(ch)
}

func main(){
ch:=make(chan int ,10)
go send(ch)

for v:=range ch {
f.Println("value :",v)
}

defer f.Println("channel is closed and values are received ")
}
