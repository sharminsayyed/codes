/*Write a program in GO language to create structure student. Write a method show() whose receiver is a pointer of struct student. */

package main
import f  "fmt"
type student struct {
rno int 
nm , city string 
}
func (s *student ) show(){
f.Println("display student details:")
f.Println("student roll no :",s.rno)
f.Println("name :",s.nm)
f.Println("city :",s.city)
}

func main(){
var s student 
f.Println("enter the roll no , name , city of student :")
f.Scan(&s.rno,&s.nm,&s.city)
(&s).show()
}
