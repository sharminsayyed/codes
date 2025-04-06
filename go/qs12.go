/*Write a program in GO language to accept one matrix and display its transpose. */

package main 
import f  "fmt"
func main(){
var r,c,i,j int 
f.Println("enter the no of rows and column :")
f.Scan(&r,&c)

mat:=make([][]int,r)
for i=0;i<r;i++{
mat[i] = make([]int ,c)
}

t:=make([][]int,c)
for i=0;i<c;i++{
t[i]=make([]int ,r)
}

f.Println("enter the elements in the matrix :")
for i=0;i<r;i++{
for j=0;j<c;j++{
f.Scan(&mat[i][j])
t[j][i] = mat[i][j]
}
}

f.Println("original matrix :")
for i=0;i<r;i++{
for j=0;j<c;j++{
f.Print(mat[i][j],"\t")
}
f.Println()
}

f.Println("transpose matrix :")
for i=0;i<c;i++{
for j=0;j<r;j++{
f.Print(t[i][j],"\t")
}
f.Println()
}

}
