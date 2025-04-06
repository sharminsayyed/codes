/*Write a program in GO language to accept n student details like roll_no, stud_name, mark1,mark2, mark3. Calculate the total and average of marks using structure.*/

package main
import f "fmt"

type student struct{
rno int 
nm string 
m1,m2,m3 ,t,avg int 
}

func main(){
var n ,i int 
f.Println("enter no of student :")
f.Scan(&n)

s:=make([]student , n)

for i=0;i<n;i++{
f.Println("enter roll no , name, marks1,marks2,marks3 of student ",i+1,":")
f.Scan(&s[i].rno,&s[i].nm,&s[i].m1,&s[i].m2,&s[i].m3)
s[i].t = s[i].m1+s[i].m2+s[i].m3
s[i].avg = s[i].t/3
}

f.Println("details of students :")
f.Println("rno \t name \t marks1 \t marks2 \t marks3 \t total \t average \t")
for i=0; i<n; i++{
f.Println(s[i].rno,"\t",s[i].nm,"\t",s[i].m1,"\t",s[i].m2,"\t",s[i].m3,"\t",s[i].t,"\t",s[i].avg)
}

}