import random as rn
n = int(raw_input())
arr = rn.sample(range(n,2*n+1),n)
k = int(raw_input())

def findMedian(arr,n):
    brr = sorted(arr)
    #print arr,"--",n
    return brr[n/2]

def partition(arr,n,a):
    i = 0
    j = n-1
    k = -1
    #print i,j,a
    while(i<j):
        r = False
        while(arr[i]<=a and i<n):
            if(arr[i]==a):
                k = i
            i+=1
        while(arr[j]>a and j>=0):
            j-=1
        if(arr[i]>arr[j]):
            if(k==-1 and arr[j]==a):
                k = i
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
            i+=1
            j-=1
    if j != k:    
        temp1 = arr[j]
        arr[j] = a
        arr[k] = temp1
    return j

def select(arr,n,k):
    #print arr,"--",k
    if(n<=10):
        arr = sorted(arr)
        return arr[k]
    if(n%5==0):
        num = n/5
    else:
        num = (n/5)+1
    meds = [0 for i in range(num)]
    if(n%5==0):
        for i in range(num):
            meds[i] = findMedian(arr[5*i:5*i+5],5)
    else:
        for i in range(num-1):
            meds[i] = findMedian(arr[5*i:5*i+5],5)
        temp = arr[(n/5)*5:]
        meds[num-1] = findMedian(temp,len(temp))
    medOfMed = select(meds,num,num/2)
    #medOfMed = findMedian(meds,num)
    #print medOfMed
    j = partition(arr,n,medOfMed)
    if(j==k):
        return medOfMed
    elif(j<k):
        temp = arr[j+1:]
        return select(temp,len(temp),k-j-1)
    else:
        temp = arr[:j]
        return select(temp,len(temp),k)

#print arr
print "BLUM:"
print select(arr,n,k-1)
print "-------------------------"
print "SORT:"
arr = sorted(arr)
print arr[k-1]
