mat1=[]
mat2=[]
r1=int(input("Enter the Number of Rows in Matrix 1 : "))
c1=int(input("Enter the number of Columns in Matrix 1 : "))
r2=int(input("Enter the Number of Rows in Matrix 2 : "))
c2=int(input("Enter the number of Columns in Matrix 2 : "))

def accept(mat,r,c):
    for i in range(r):
        d=[]
        for j in range(c):
            e=int(input("Enter the Elements : "))
            d.append(e)
        mat.append(d)

def display(mat,r):
    for i in range(r):
        print(mat[i])

def add(mat1,mat2,r,c):
    a=[]
    for i in range(r):
        s=[]
        for j in range(c):
            e=mat1[i][j]+mat2[i][j]
            s.append(e)
        a.append(s)
    print("Matrix 1 + Matrix 2 : ")
    for i in range(r):
        print(a[i])

def sub(mat1,mat2,r,c):
    s=[]
    for i in range(r):
        d=[]
        for j in range(c):
            e=mat1[i][j]-mat2[i][j]
            d.append(e)
        s.append(d)
    print("Matrix 1 - Matrix 2 : ")
    for i in range(r):
        print(s[i])

def mul(mat1,mat2,r1,c1,c2):
    m=[]
    for i in range(r1):
        p=[]
        for j in range(c2):
            p.append(0)
        m.append(p)
    for i in range(r1):
        for j in range(c2):
            for k in range(c1):
                m[i][j]+=(mat1[i][k]*mat2[k][j])
    print("Matrix 1 x Matrix 2 : ")
    for i in range(r1):
        print(m[i])

def transpose(mat,r,c):
    t=[]
    for i in range(r):
        d=[]
        for j in range(c):
            d.append(mat[j][i])
        t.append(d)
    print("Transpose of Matrix : ")
    for i in range(c):
        print(t[i])

def main():
    accept(mat1,r1,c1)
    display(mat1,r1)
    accept(mat2,r2,c2)
    display(mat2,r2)
    while(True):
        print("\n")
        print("1 : Addition of Matrices")
        print("2 : Subtraction of Matrices")
        print("3 : Multiplication of Matrices")
        print("4 : Transpose of Matrix")
        print("5 : Exit")
        ch=int(input("Enter Your Choice : "))
        if (ch==5):
            print("End of Program")
            break
        elif(ch==1):
            if(r1==r2 and c1==c2):
                add(mat1,mat2,r1,c1)
            else:
                print("Addition of Matrices not Possible")
        elif(ch==2):
            if(r1==r2 and c1==c2):
                sub(mat1,mat2,r1,c1)
            else:
                print("Subtraction of Matrices not Possible")
        elif(ch==3):
            if(c1==r2):
                mul(mat1,mat2,r1,c1,c2)
            else:
                print("Multiplication of Matrix is not possible")
        elif(ch==4):
            c=int(input("Enter Matrix Number to Transpose : "))
            if(c==1):
                transpose(mat1,r1,c1)
            elif(c==2):
                transpose(mat2,r2,c2)
            else:
                print("Invalid Choice ")
        else:
            print("Entered Wrong Choice")
main()