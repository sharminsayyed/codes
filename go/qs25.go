/*  Write a program in GO language that prints out the numbers from 0 to 10, waiting between 0 and 250 ms after each one using the delay function. */

package main
import f "fmt"
import t "time"

func generateno(){
for i:=1 ;i<=10 ;i++{
f.Print(i,"\t")
}
}

func main(){
for i:= 0;i<5; i++{
go generateno()
f.Println()
t.Sleep(250*t.Millisecond)

}
}
