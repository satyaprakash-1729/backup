f = open("aplusb.in","r")
t = int(f.readline().rstrip())
#t = int(raw_input())
for _ in range(t):
    #n = int(raw_input())
    n = int(f.readline().rstrip())
    arr = map(int,f.readline().split())
    ans = [1 for i in range(n)]
    an = 0
    for j in [1,arr[0]]:
        for i in range(1,n):
            if(abs(arr[i]-ans[i-1])>abs(1 - ans[i-1])):
                ans[i] = arr[i]
            else:
                ans[i] = 1
        s = 0
        for i in range(n-2,-1,-1):
            if(abs(arr[i]-ans[i+1])>abs(1 - ans[i+1])):
                ans[i] = arr[i]
            else:
                ans[i] = 1
            s += abs(ans[i+1]-ans[i])
        if(s>an):
            an = s
    print an