import sys
A = raw_input()
B = raw_input()

m = len(A)
n = len(B)

C = [[0 for l in range(n+1)] for k in range(m+1)]
S = [[0 for l in range(n+1)] for k in range(m+1)]
for i in range(1,m+1):
    for j in range(1,n+1):
        if(A[i-1]==B[j-1]):
            C[i][j] = C[i-1][j-1]+1
            S[i][j] = 3                                                     # 1 : left 2: up 3: diag
        else:
            #rint i,j
            if(C[i-1][j]>C[i][j-1]):
                C[i][j] = C[i-1][j]
                S[i][j] = 2
            else:
                C[i][j] = C[i][j-1]
                S[i][j] = 1

sys.stdout.write("  ")
for i in range(1,n+1):
    sys.stdout.write(B[i-1]+" ")
print ""
for i in range(1,m+1):
    sys.stdout.write(A[i-1]+" ")
    for j in range(1,n+1):
        sys.stdout.write(str(C[i][j])+" ")
    print ""

def printer(C,S,i,j):
    if(i==0 and j==0):
        return
    if(i>=0 and j>=0):
        if(S[i][j]==3):
            printer(C,S,i-1,j-1)
            sys.stdout.write(A[i-1])
        elif(S[i][j]==2):
            printer(C,S,i-1,j)
        else:
            printer(C,S,i,j-1)

#printer(C,S,m,n)