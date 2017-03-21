def maxSub(s,t):
    m = len(s)
    n = len(t)
    ansmax = 0
    ans = [[0 for _ in range(m+1)] for j in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            if(t[i-1]==s[j-1]):
                ans[i][j] = ans[i-1][j-1]+1
                if(ans[i][j]>ansmax):
                    ansmax = ans[i][j]
            else:
                ans[i][j] = 0
        print ans[i]
    return ansmax

n,q = map(int,raw_input().split())
arr = []

for i in range(n):
    string = raw_input().rstrip()
    arr.append(string)

for i in range(q):
    a,b = map(int,raw_input().split())
    print maxSub(arr[a],arr[b])