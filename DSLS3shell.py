def accept(A): 
   n = int(input("Enter the total no. of student : "))
   for i in range(n):
      x = float(input("Enter the  Second year percentage of student %d : "%(i+1)))
      A.append(x)
   print("Array accepted successfully\n\n")

def display(A): 
   n = len(A)
   if(n == 0) :
      print("\nNo records in the database",n)
   else :
      print("Array of SE Marks : ",end=' ')
      for i in range(n) :
         print("%.2f  "%A[i],end=' ')
      print("\n")


def Insertion(A) :
   n = len(A)
   for i in range(1,n) :
      element = A[i]
      j  = i-1
      while( j >= 0) :
         if (A[j] <= element) :
            break
         else :
            A[j+1] = A[j]
            j = j - 1
      A[j+1] = element



def shell(A,n):
   gap = n // 2
   while gap > 0:
      for i in range(gap,n):
         temp = A[i]
         j = i
         while j >= gap and A[j - gap] > temp:
            A[j] = A[j - gap]
            j =j-gap
         A[j] = temp
      gap= gap// 2

def main() :   
   A = []
   while True :
      print ("\n1 : Accept & Display the SE Marks")
      print ("\n2 : Insertion Sort Ascending order")
      print ("\n3 : Shell sort Ascending order and display top five scores")
      print ("\n4 : Exit")
      ch = int(input("Enter your choice : "))
      if (ch == 4):
         print ("End of Program")
         quit()
      elif (ch==1):
         A = []
         accept(A)
         display(A)
      elif (ch==2):
         print("Marks before sorting")
         display(A)
         Insertion(A)
         print("Marks after sorting")
         display(A)
      elif (ch==3):
         print("Marks before sorting")
         display(A)
         n=len(A)
         shell(A,n)
         print("Marks after sorting")
         display(A)
         n =len(A)
         if(n >= 5) :
            print("Top Five Scores : ")
            for i in range(n-1,n-6,-1) :
               print("\t%.2f"%A[i])
         else :
            print("Top Scorers : ")
            for i in range(n-1,-1,-1) :
               print("\t%.2f"%A[i])                  
      else :
           print ("Wrong choice entered !! Try again")


main()
