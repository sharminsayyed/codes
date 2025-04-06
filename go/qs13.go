/* Write a program in GO language to accept the book details such as BookID, Title, Author, Price. Read and display the details of ‘n’ number of books*/

package main 
import f  "fmt"
type book struct {
bid int 
t ,a string 
pr float64
}

func main(){
var n,i int 
f.Println("enter no of books :")
f.Scan(&n)

b:= make([]book ,n)
for i=0;i<n;i++{
f.Println("enter book id ,title,author ,price of book ",i+1,":")
f.Scan(&b[i].bid,&b[i].t,&b[i].a,&b[i].pr)
}

f.Println("book details :")
for i=0 ;i<n;i++{
f.Println("book id :",b[i].bid,"\t title:",b[i].t,"\t author:",b[i].a,"\t price :",b[i].pr)
}

}
