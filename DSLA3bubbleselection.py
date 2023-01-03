list=[]
n=int(input("Enter the Total Number of Students : "))
for i in range(n):
    p=float(input("Enter the Percentage of Students : "))
    list.append(p)
print(list)

def selection_sort():
    for i in range(n):
        for j in range(i+1,n):
            if(list[i]>list[j]):
                temp=list[i]
                list[i]=list[j]
                list[j]=temp
    print("Sorted List : ",list)

def bubble_sort():
    for i in range(n):
        for j in range(n-1-i):
            if(list[j]>list[j+1]):
                temp=list[j]
                list[j]=list[j+1]
                list[j+1]=temp
    print("Sorted List : ",list)
    print("Top 5 Percentage : ")
    for i in range(-1,-6,-1):
        print(list[i])

def main():
    print("\n")
    print("1 : To Sort using Selection Sort")
    print("2 : To Sort using Bubble Sort")
    ch=int(input("Enter your Choice : "))
    if(ch==1):
        selection_sort()
    elif(ch==2):
        bubble_sort()
    else:
        print("Invalid Choice")
main()
