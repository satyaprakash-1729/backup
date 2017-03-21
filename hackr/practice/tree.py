import os, sys

n,m = map(int,raw_input().split())

adj = [[] for _ in range(n+1)]

for i in range(m):
    a,b = map(int,raw_input().split())
    adj[a].append(b)
    adj[b].append(a)

level = [[]]
pi = [0 for _ in range(n+1)]

def bfs_level_set(adj,s,n):
    Q = [s,-1]
    l=0
    level[0].append(s)
    done=[False for i in range(n+1)]
    while Q:
        l+=1
        level.append([])
        while(Q[0]!=-1):
            u = Q[0]
            done[u]=True
            #print u,l
            try:
                del Q[0]
            except:
                break
            for v in adj[u]:
                if done[v]==False:
                    pi[v] = u
                    Q.append(v)
                    level[l].append(v)
        del Q[0]
        if(len(Q)>0):
            Q.append(-1)

bfs_level_set(adj, 1, n)
level = level[:-1]
subTree = [0 for _ in range(n+1)]
for i in reversed(level):
    for j in i:
        subTree[pi[j]]+=(subTree[j]+1)

count = 0
for l in subTree[2:]:
    if l%2==1:
        count+=1

print count