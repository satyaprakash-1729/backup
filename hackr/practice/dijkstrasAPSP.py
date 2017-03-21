import os,sys

class PQueue(object):
    def __init__(self, listToInsert):
        self.queue = listToInsert
        self.buildHeap()

    def buildHeap(self):
        n = len(self.queue)
        for i in range(n/2-1,0):
            heapify(self.queue,n,i)

    def isEmpty(self):
        try:
            a = arr[1]
            return False
        except:
            return True

def heapify(arr,n):
    mina = 0
    l = 2*i
    r = 2*i+1
    if l <= n and arr[l]<arr[i]:
        mina = l
    else:
        mina = i
    if r <= n and arr[r]<arr[mina]:
        mina = r
    if mina != i:
        temp = arr[mina]
        arr[mina] = arr[i]
        arr[i] = temp
        heapify(arr,n,mina)

def extract_min(arr,n):
    try:
        a = arr[1]
        arr[1] = arr[n]
        del arr[n]
        heapify(arr,n-1,0)
        return a
    except:
        return None

def decrease_key(arr,n,i,k):
    if(arr[i]<=k):
        raise ValueError
    else:
        arr[i] = k
        while arr[i/2]>arr[i]:
            temp = arr[i]
            arr[i] = arr[i/2]
            arr[i/2] = temp
            i=i/2


n,m = map(int,raw_input().split())

adj = [[0 for i in range(n+1)] for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,n+1):
        if i==j:
            adj[i][j]=0
        else:
            adj[i][j]=float('inf')

def mine(d,done):
    mina = float('inf')
    ans = 0
    for i in range(len(d)):
        if d[i]<mina and done[i]==False:
            mina = d[i]
            ans = i
    try:
        return ans
    except:
        return None

for i in range(m):
    a,b,w = map(int,raw_input().split())
    if adj[a][b] > 2**w:
        adj[a][b] = 2**w
        adj[b][a] = 2**w

def dijkstras(adj, s):
    d = [float('inf') for _ in range(n+1)]
    pi = [None for _ in range(n+1)]
    done=[False for _ in range(n+1) ]
    d[s] = 0
    count=0
    while count<n:
        u = mine(d,done)
        done[u]=True
        count+=1
        for v in range(1,n+1):
            if adj[u][v]!=0 and adj[u][v]!=float('inf') and done[v]==False:
                if(d[v]>d[u]+adj[u][v]):
                    d[v]=d[u]+adj[u][v]
                    pi[v]=u
    return d,pi

ans = 0
for i in range(1,n+1):
    d2,pi2 = dijkstras(adj,i)
    for j in range(i+1,n+1):
        ans+=d2[j]
print bin(ans)[2:]
