def accept(arr,n):
    for i in range(n):
        m=int(input("Enter the Mark of Student %d : "%(i+1)))
        arr.append(m)

def display(arr):
    print("Marks : ",arr)

def average(arr,n):
    ab=0
    sum=0
    for i in range(n):
        if(arr[1]>=0):
            sum+=arr[i]
        if(arr[i]==-1):
            ab+=1
    avg=sum/(n-ab)
    print("Average Marks : ",avg)
    print("Number of Absent Students : ",ab)

def highest(arr,n):
    max=0
    for i in range (n):
        if(arr[i]>max):
            max=arr[i]
    print("Highest Marks : ",max)

def lowest(arr,n):
    min=100
    for i in range (n):
        if(arr[i]<min and arr[i]>=0):
            min=arr[i]
    print("Lowest Marks : ",min)

def frequency(arr,n):
    f=[]
    for i in range(101):
        f.append(0)
    for i in range(n):
        for j in range(101):
            if(arr[i]==j):
                f[j]+=1
    max=0
    for i in range(101):
        if(f[i]>max):
            max=f[i]
            t=i
    print("Marks with highest frequency : ", t)

def main():
    marks=[]
    n=int(input("Enter the total Number of Students : "))
    accept(marks,n)
    display(marks)
    while True:
        print("1 : Find Average and Number of Absent Students")
        print("2 : Find the Highest and Lowest Marks")
        print("3 : Find Marks with Highest Frequency")
        print("4 : Exit")
        ch=int(input("Enter Your Choice : "))
        if(ch==4):
            print("End of Program")
            break
        elif(ch==1):
            average(marks,n)
        elif(ch==2):
            highest(marks,n)
            lowest(marks,n)
        elif(ch==3):
            frequency(marks,n)
        else:
            print("Entered Wrong Choice")
main()
