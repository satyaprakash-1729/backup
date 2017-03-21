import os,sys

n,m = map(int,raw_input().split())

adj = [[[0 for i in range(n+1)] for _ in range(n+1)] for j in range(n+1)]
for i in range(1,n+1):
    for j in range(1,n+1):
        if i==j:
            adj[0][i][j]=0
        else:
            adj[0][i][j]=float('inf')
for i in range(m):
    a,b,w = map(int,raw_input().split())
    if adj[0][a][b] > 2**w:
        adj[0][a][b] = 2**w
        adj[0][b][a] = 2**w

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            adj[k][i][j] = min(adj[k-1][i][j], adj[k-1][i][k] + adj[k-1][k][j])

ans = 0
for i in range(1,n+1):
    for j in range(i+1,n+1):
        ans += adj[n][i][j]

print bin(ans)[2:]
