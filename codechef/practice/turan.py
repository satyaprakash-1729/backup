t = int(raw_input())
for _ in range(t):
    n,m = map(int,raw_input().split())
    flag = False
    for i in range(2,n+1):
        a = (float(i-2)/(2*(i-1)))*float(n*n)
        if(a>m):
            print i-1
            flag = True
            break
    if flag == False:
        print n