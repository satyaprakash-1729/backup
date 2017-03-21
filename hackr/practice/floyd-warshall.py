import os,sys

n,m = map(int,raw_input().split())

adj = [[0 for i in range(n+1)] for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,n+1):
        if i==j:
            adj[i][j]=0
        else:
            adj[i][j]=float('inf')
for i in range(m):
    a,b,w = map(int,raw_input().split())
    adj[a][b] = 2**w
    adj[b][a] = 2**w


for k in range(1,n+1):
    for i in adj[1:]:
        for j in i[1:]:
            sys.stdout.write(str(j)+"   ")
        print ""
    print ""
    for i in range(1,n+1):
        for j in range(1,n+1):
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j])

ans = 0
for i in range(1,n+1):
    for j in range(i+1,n+1):
        ans += adj[i][j]

print bin(ans)[2:]
