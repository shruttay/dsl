list=[]
n=int(input("Enter the Total Nymber of Students : "))
for i in range(n):
    p=float(input("Enter the Percentage : "))
    list.append(p)
print(list)

def quicksort(list,p,q):
    if(p<q):
        i=partition(list,p,q)
        quicksort(list,p,i-1)
        quicksort(list,i+1,q)

def partition(list,p,q):
    x=list[p]
    i=p
    for j in range(i+1,q+1):
        if(list[j]<=x):
            i+=1
            temp=list[i]
            list[i]=list[j]
            list[j]=temp
    temp1=list[p]
    list[p]=list[i]
    list[i]=temp1
    return i

def main():
    quicksort(list,0,n-1)
    print (list)
    print("Top 5 Percentage : ")
    for i in range(-1,-6,-1):
        print(list[i])
main()
