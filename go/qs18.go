/*Write a program in GO language to create an interface shape that includes area and perimeter. Implements these methods in circle and rectangle type.*/

package main 
import f "fmt"

type shape interface {
area() float64
perimeter() float64
}

type circle struct{
rad float64
}
type rect struct{
l,w float64
}

func (c circle ) area() float64{
return 3.412 *c.rad*c.rad
}
func (c circle) perimeter() float64{
return 2*3.142*c.rad
}
func (r rect) area() float64{
return r.l*r.w
}
func (r rect) perimeter() float64{
return 2*(r.l+r.w)
}

func main(){
var c circle 
var r rect 
f.Println("enter the radius of circle:")
f.Scan(&c.rad)
f.Println("enter the lenght and width of rectangle  :")
f.Scan(&r.l,&r.w)

f.Println("Area of circle :",c.area())
f.Println("perimeter of circle :",c.perimeter())
f.Println("area of rectangle:",r.area())
f.Println("perimeter of rectangle :",r.perimeter())

}


