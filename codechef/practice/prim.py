def minab(arr,done):
    mina = 100001
    index = 0
    for i in range(len(arr)):
        if(arr[i]<mina and done[i]==False):
            mina = arr[i]
            index = i
    return index

def prim(adj, s, n, m):
    d = [100001 for i in range(n+1)]
    pi = [None for i in range(n+1)]
    d[s] = 0
    done = [False for _ in range(n+1)]
    done[0] = True
    k=0
    while k<n:
        k+=1
        u = minab(d,done)
        done[u] = True
        for v in adj[u].keys():
            if done[v]==False:
                if(d[v]>adj[u][v]):
                    d[v] = adj[u][v]
                    pi[v] = u
    return d[1:],pi[1:]

n, m = map(int,raw_input().split())
adj = [{} for _ in range(n+1)]
for i in range(m):
    a,b,w = map(int,raw_input().split())
    adj[a][b] = w
    adj[b][a] = w

s = int(raw_input())
print sum(prim(adj,s,n,m)[0])

