/*Write a program in GO language to create an interface shape that includes area and volume. Implements these methods in square and rectangle type.*/

package main 
import f "fmt"

type shape interface {
area() float64
volume() float64
}

type square struct{
side float64
}
type rect struct{
l,w ,h float64
}

func (s square ) area() float64{
return s.side *s.side
}
func (s square) volume() float64{
return s.side *s.side* s.side
}
func (r rect) area() float64{
return r.l*r.w
}
func (r rect) volume() float64{
return r.l*r.w*r.h
}

func main(){
var s square
var r rect 
f.Println("enter the side of square :")
f.Scan(&s.side)
f.Println("enter the lenght and width and height of rectangle  :")
f.Scan(&r.l,&r.w,&r.h)

f.Println("Area of square:",s.area())
f.Println("volume of square:",s.volume())
f.Println("area of rectangle:",r.area())
f.Println("volume of rectangle :",r.volume())

}


