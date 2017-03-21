#f = open("aplusb.in","r")
#t = int(f.readline().rstrip())
import sys
t = int(raw_input())
for _ in range(t):
    n = int(raw_input())
    #n = int(f.readline().rstrip())
    B = map(int,raw_input().split())
    B = [0] + B
    ans = [[0 for _ in range(n+1)] for i in range(n+1)]
    # ----------> (B[i])
    # |
    # |  (1)
    # |
    # \/
    A = [0 for _ in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,n+1):
            #print i,j
            if(ans[i][j-1] + abs(B[max(i,j)]-A[max(i,j)-1]) > ans[i-1][j] + abs(1-A[max(i,j)-1])):
                if A[max(i,j)-1] != 0:
                    ans[i][j] = ans[i][j-1] + abs(B[max(i,j)]-A[max(i,j)-1])
                    A[max(i,j)] = B[max(i,j)]
            else:
                if A[max(i,j)-1] != 0:
                    ans[i][j] = ans[i-1][j] + abs(1-A[max(i,j)-1])
                    A[max(i,j)] = 1
    s = 0
    for i in range(1,n+1):
        s+=abs(A[i]-A[i-1])
    print s
    '''for i in range(n+1):
        for j in range(n+1):
            sys.stdout.write(str(ans[i][j])+" ")
        print ""
    '''