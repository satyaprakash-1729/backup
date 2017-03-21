import os, sys

class Graph(object):
    def __init__(self):
        self.V = []
        self.E = {}
        self.adj = {}
    def insert_undirected_minedge(self,a,b,w):
        if a not in self.V:
            self.V.append(a)
        if b not in self.V:
            self.V.append(b)
        if a not in self.adj.keys():
            (self.adj)[a] = [b]
        else:
            (self.adj)[a].append(b)
        if b not in self.adj.keys():
            (self.adj)[b] = [a]
        else:
            (self.adj)[b].append(a)
        if((a,b) not in self.E.keys()):
            (self.E)[(a,b)] = w
        else:
            (self.E)[(a,b)] = min(w,(self.E)[(a,b)])
        if((b,a) not in self.E.keys()):
            (self.E)[(b,a)] = w
        else:
            (self.E)[(b,a)] = min(w,(self.E)[(b,a)])

    def insert_directed_edge(self,a,b,w):
        if a not in self.V:
            V.append(a)
        if b not in self.V:
            V.append(b)
        if b not in (self.adj)[a]:
            if (self.adj)[a] == None:
                (self.adj)[a] = [b]
            else:
                (self.adj)[a].append(b)
        (self.E)[(a,b)] = w

    def __str__(self):
        ans = str(self.V)+"\n"
        ans += str(self.E)+"\n"
        ans += str(self.adj)
        return ans

def initialize_ss(G, s):
    vertices = G.V
    d = {}
    pi = {}
    for v in vertices:
        d[v] = float('inf')
        pi[v] = None
    d[s] = 0
    return d,pi

def relax(u, v, w, d, pi):
    if d[v] > d[u] + w:
        d[v] = d[u] + w
        pi[v] = u

def extract_min(G, d, Q):
    mina = float('inf')+1
    ans = Q[0]
    for v in Q:
        if(d[v] < mina):
            mina = d[v]
            ans = v
    Q.remove(ans)
    return ans

def dijkstras(G, s):
    d,pi = initialize_ss(G, s)
    done = []
    Q = G.V[:]
    while Q:
        u = extract_min(G, d, Q)
        #print Q,u,d
        if d[u]==float('inf'):
            break
        done.append(u)
        for v in (G.adj)[u]:
            if v in Q:
                relax(u,v,(G.E)[(u,v)], d, pi)
    return d,pi

t = int(raw_input())
for _ in range(t):
    G = Graph()
    n,m = map(int,raw_input().split())
    for i in range(m):
        a,b,w = map(int, raw_input().split())
        G.insert_undirected_minedge(a,b,w)
        #print G
    s = int(raw_input())
    d,pi = dijkstras(G, s)
    for i in range(1,n+1):
        if i != s:
            try:
                if(d[i]==float('inf')):
                    d[i]=-1
                sys.stdout.write(str(d[i])+" ")
            except:
                sys.stdout.write("-1 ")
    print ""