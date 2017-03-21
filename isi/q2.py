import sys,os
import math
a = 0
def H(n,An,Mn,ansArr):
    global a
    a+=1
    if(ansArr[n]!=None):
        return ansArr[n]
    if(n==0):
        ansArr[n] = An,Mn
        return ansArr[n]
    elif(n==1):
        ansArr[n] = An,Mn
        return ansArr[n]
    elif(n==2):
        ansArr[n] = An+1,Mn+1
        return ansArr[n]
    elif(n==3):
        ansArr[n] = An+3,Mn+1
        return ansArr[n]
    else:
        t = int(math.log(n,2))
        ar = H(t-1,An+2,Mn+1,ansArr)
        br = H(n-t,An+2,Mn+1,ansArr)
        ansArr[n] = ar[0]+br[0],ar[1]+br[1]
        return ansArr[n]

r = 1
m = 20172017

arr = [0 for _ in range(25)]
while (m>3):
    a = int(math.log(m,2))
    arr[a]+=1
    m-=a
if(m==3):
    AnsA = 3
    AnsM = 1
elif(m==2):
    AnsA = 1
    AnsM = 1
else:
    AnsA = 0
    AnsM = 0
for i in range(25):
    ansArr = [None for _ in range(i+1)]
    tmp = H(i,0,0,ansArr)
    AnsA+=tmp[0]*arr[i]
    AnsM+=tmp[1]*arr[i]
print AnsM,AnsA
