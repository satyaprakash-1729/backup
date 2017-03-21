import os,sys

n,m = map(int,raw_input().split())

W = [[float('inf') for i in range(n+1)] for j in range(n+1)]

for i in range(1,n+1):
    for j in range(1,n+1):
        if i==j:
            W[i][j] = 0
        else:
            W[i][j] = float('inf')

for i in range(m):
    a,b,w = map(int,raw_input().split())
    W[a][b] = w
    W[b][a] = w

def slow_APSP(W):
    n = len(W)-1
    d = W[:]
    for m in range(2,n):
        dp = extend(d,W)
        d = dp
    return d

def fast_APSP(W):
    n = len(W)-1
    d=W[:]
    m=1
    while n-1>m:
        dp = extend(d,d)
        d = dp
        m=2*m
    return d

def extend(dp,W):
    n = len(dp)-1
    d = [[0 for _ in range(n+1)] for i in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,n+1):
            d[i][j] = float('inf')
            for k in range(1,n+1):
                d[i][j] = min(d[i][j],dp[i][k]+W[k][j])
    return d

adj2 = fast_APSP(W)

ans = int('0b0',2)
for i in range(1,n+1):
    for j in range(i+1,n+1):
        a=int('0b1'+'0'*adj2[i][j],2)
        ans+=a

print ans