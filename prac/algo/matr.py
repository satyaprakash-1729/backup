import sys
n = int(raw_input())
P = map(int,raw_input().split())
m = [[0 for i in range(n)] for j in range(n)]
pos = [[0 for i in range(n)] for j in range(n)]
A = ["A"+str(i) for i in range(1,n)]
def matChainOrder(P,n):
    for i in range(n):
        m[i][i]=0
    for l in range(1,n):
        for i in range(n-l+1):
            j = i+l
            #print i,j
            m[i][j] = 1000000
            for k in range(i,j):
                q = m[i][k]+m[k+1][j]+P[i-1]*P[k]*P[j]
                #print m[i][k],m[k+1][j],k,i,j
                if(q<m[i][j]):
                    m[i][j]=q
                    pos[i][j]=k
    return m,pos

def printer(pos,A,i,j):
    if(i==j):
        sys.stdout.write(A[i])
    else:
        sys.stdout.write("(")
        printer(pos,A,i,pos[i][j])
        printer(pos,A,pos[i][j]+1,j)
        sys.stdout.write(")")

m,pos = matChainOrder(P,n-1)
#print m
#print pos
printer(pos,A,0,n-2)