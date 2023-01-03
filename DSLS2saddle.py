def accept(m):
    print("Enter number of rows on column of matrix")
    row=int(input("\nrow:"))
    col=int(input("\ncol:"))
    print("Enter elements")
    

    for i in range(row):
        a=[]
        for j in range(col):
            a.append(int(input()))
        m.append(a)
    print("\nMatrix accepted\n")
    
def display(row,col,m):
    print("\nThe matrix is \n")
    for i in range(row):
        print(m[i])

def saddle(row,col,m):
    count=0
    rowmin=0
    c=0
    for i in range (row):
        rowmin=m[i][0]
        for j in range(col):
            if(m[i][j]<rowmin):
                rowmin=m[i][j]
                c=j
        flag=1
        for r in range(row):
            if(rowmin<m[r][c]):
                flag=0
                break
        if (flag == 1) :
            count += 1           
            print("%d value is minimum in row(%d) and maximum in column(%d)"%(rowmin,i+1,c+1))
    if (count == 0) :
        print("No Saddle Point Exist for the given Matrix")
        

def main():   
   while True :
       print("\n1: Accept Matrix")
       print("\n2: Display Matrix")
       print("\n3: Find the Saddle Point")
       print("\n4: Exit")
       ch = int(input("Enter your choice : "))       
       if (ch == 4):
           print ("End of Program")
           break
       elif (ch==1):
           Mat = []
           print("Input the Matrix ")
           accept(Mat)
           r = len(Mat)
           c = len(Mat[0])       
       elif (ch==2):
           display(r,c,Mat)           
       elif (ch==3):
           display(r,c,Mat)
           saddle(r,c,Mat)
       else :
           print ("Wrong choice entered !! Try again")

main()


