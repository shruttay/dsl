def accept(A,Str): 
   n = int(input("Enter the total no. of student playing %s : "%Str))
   for i in range(n) :
      x = input("Enter the name of student %d playing %s : "%((i+1),Str))
      A.append(x)

def display(A,Str): 
   n = len(A)
   if(n == 0) :
      print("\nGroup of Students playing %s =  { }"%Str)
   else :
      print("\nGroup of Students playing %s = { "%Str,end=' ')
      for i in range(n-1) :
         print("%s,"%A[i],end=' ')
      print("%s }"%A[n-1])
   
def search(A,X) :
    n = len(A)
    for i in range(n):
       if(A[i] == X) :
          return (1)
    return (0)

def intersection(A,B,C):
   for i in range(len(A)): 
      flag = search(B,A[i])
      if(flag == 1) :
          C.append(A[i])

def difference(A,B,C):
    for i in range(len(A)): 
      flag = search(B,A[i])
      if(flag == 0) :
          C.append(A[i])    


def union(A,B,C):
   for i in range(len(A)):
      C.append(A[i])
   for i in range(len(B)): 
      flag = search(A,B[i])
      if(flag == 0) :
          C.append(B[i])    
       
def Main() :
   Group_A = []
   Group_B = []
   Group_C = []
   
   while True :
       print ("\t1 : Accept the Information")
       print ("\t2 : List of students who play both cricket and badminton")
       print ("\t3 : List of students who play either cricket or badminton but not both")
       print ("\t4 : Number of students who play neither cricket nor badminton")
       print ("\t5 : Number of students who play cricket and football but not badminton")
       print ("\t6 : Exit")
       ch = int(input("Enter your choice : "))
       Group_R = []       
       if (ch == 6):
           print ("End of Program")
           break
       elif (ch==1):
           accept(Group_A,"Cricket")
           display(Group_A,"Cricket")
           accept(Group_B,"Badminton")
           display(Group_B,"Badminton")
           accept(Group_C,"Football")
           display(Group_C,"Football")           
       elif (ch==2):
           display(Group_A,"Cricket")
           display(Group_B,"Badminton")
           intersection(Group_A,Group_B,Group_R)
           display(Group_R," both Cricket and Badminton")
       elif (ch==3):
           display(Group_A,"Cricket")
           display(Group_B,"Badminton")
           R1 = []
           union(Group_A,Group_B,R1)
           R2 = []
           intersection(Group_A,Group_B,R2)
           difference(R1,R2,Group_R)
           display(Group_R," either cricket or badminton but not both")
       elif (ch==4):
           display(Group_A,"Cricket")
           display(Group_B,"Badminton")
           display(Group_C,"Football")
           R1 = []
           union(Group_A,Group_B,R1)
           difference(Group_C,R1,Group_R)
           display(Group_R," neither cricket nor badminton")
           print("Number of students who play neither cricket nor badminton = %s"%len(Group_R))
       elif (ch==5):
           display(Group_A,"Cricket")
           display(Group_C,"Football")
           display(Group_B,"Badminton")
           R1 = []
           intersection(Group_A,Group_C,R1)           
           difference(R1,Group_B,Group_R)           
           display(Group_R,"cricket and football but not badminton")
           print("Number of students who play cricket and football but not badminton = %d"%len(Group_R))                 
       else :
           print ("Wrong choice entered !! Try again")


Main()
quit()
