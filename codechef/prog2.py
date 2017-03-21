t = int(raw_input())
for _ in range(t):
    n,m = map(int,raw_input().split())
    arr = map(int,raw_input().split())
    brr = map(int,raw_input().split())
    score = 0
    for i in range(len(brr)):
        l = brr[i]
        maxa = 0
        indmax = 0
        print arr
        for j in range(len(arr)-l+1):
            r =sum(arr[j:j+l])
            if(r>maxa):
                maxa = r
                indmax = j
        arr = arr[indmax+1:indmax+l-1]
        if(i%2 ==0):
            score+=maxa
        else:
            score-=maxa
    print score
