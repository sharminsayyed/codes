/* Write a program in GO language to create a buffered channel, store few values in it and find channel capacity and length. Read values from channel and find modified length of a channel*/

package main
import f "fmt"

func main(){
ch:= make(chan int ,10)
ch<-10
ch<-20
ch<-30
ch<-40
ch<-50
f.Println("capacity :",cap(ch))
f.Println("Length :",len(ch))
v:= <-ch 
f.Println("value 1 :",v)
v1:= <-ch 
f.Println("value 2 :",v1)
f.Println("modified length :",len(ch))
}