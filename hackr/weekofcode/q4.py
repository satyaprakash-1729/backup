import sys,os

n,k = map(int,raw_input().split())

poles = [[0, 0] for i in range(n)]

for i in range(n):
    poles[i] = map(int,raw_input().split())

poles = [i for i in reversed(poles)]

ansMat = [[[-1 for _ in range(k)] for j in range(n)] for i in range(n)]

def func(poles,n,k,last):
    if(ansMat[last][n][k]!=-1):
        return ansMat[last][n][k]
    if n==0 or k==0:
        ans = 0
        for i in range(last):
            ans+=poles[i][1]*abs(poles[i][0]-poles[last][0])
        ansMat[last][n][k] = ans
    else:
        ansMat[last][n][k] = min(poles[n-1][1]*abs(poles[n-1][0]-poles[last][0]) + func(poles,n-1,k,last),func(poles,n-1,k-1,n-1))
    return ansMat[last][n][k]

print func(poles,n-1,k-1,n-1)