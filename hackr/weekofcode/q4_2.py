import sys,os

n,k = map(int,raw_input().split())

poles = [[0, 0] for i in range(n)]

for i in range(n):
    poles[i] = map(int,raw_input().split())

poles = [i for i in reversed(poles)]

ansMat = [[[-1 for _ in range(2)] for j in range(2)] for i in range(n)]

def func(poles,n,k,last):
    if(ansMat[last][0][0]!=-1):
        return ansMat[last][0][0]
    if n==0 or k==0:
        ans = 0
        for i in range(last):
            ans+=poles[i][1]*abs(poles[i][0]-poles[last][0])
        ansMat[last][1][1] = ans
    else:
        ansMat[last][1][1] = min(poles[n-1][1]*abs(poles[n-1][0]-poles[last][0]) + func(poles,n-1,k,last),func(poles,n-1,k-1,n-1))
    ansMat[last][0][0] = ansMat[last][1][1]
    return ansMat[last][0][0]

print func(poles,n-1,k-1,n-1)