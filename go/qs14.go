/*Write a program in GO language to accept two matrices and display its multiplication*/

package main 
import f  "fmt"
func main(){
var r1,c1,r2,c2,i,j int 
f.Println("enter the no of rows and column for 1st matrix:")
f.Scan(&r1,&c1)
f.Println("enter the no of rows and column for 2nd matrix:")
f.Scan(&r2,&c2)

if c1 != r2{
f.Println("multiplication cannot happen Columns of First Matrix = Rows of Second")
}

mat1:=make([][]int ,r1)
mat2:=make([][]int, r2)

for i=0;i<r1;i++{
mat1[i] = make([]int ,c1)
}

for i=0;i<r2;i++{
mat2[i] = make([]int ,c2)
}

f.Println("enter the elements in the 1st matrix :")
for i=0;i<r1;i++{
for j=0;j<c1;j++{
f.Scan(&mat1[i][j])
}
}

f.Println("enter the elements in the 2nd matrix :")
for i=0;i<r2;i++{
for j=0;j<c2;j++{
f.Scan(&mat2[i][j])
}
}
f.Println("1st matrix :")
for i=0;i<r1;i++{
for j=0;j<c1;j++{
f.Print(mat1[i][j],"\t")
}
f.Println()
}

f.Println(" 2nd matrix is :")
for i=0;i<r2;i++{
for j=0;j<c2;j++{
f.Print(mat2[i][j],"\t")
}
f.Println()
}

res:=make([][]int ,r1)
for i=0;i<r1;i++{
res[i] = make([]int ,c2)
}

// multiplication
for i=0;i<r1;i++{
for j=0;j<c2;j++{
for k:=0;k<c1;k++{
res[i][j] += mat1[i][k] * mat2[k][j]
}
}
}

f.Println("multiplicattion of 2 matrix is :")
for i=0;i<r1;i++{
for j=0;j<c2;j++{
f.Print(res[i][j],"\t")
}
f.Println()
}

}

