n,q = map(int,raw_input().split())

arr = map(int,raw_input().split())
for _ in range(q):
    left,right,x,y = map(int,raw_input().split())
    count = 0
    for i in arr[left:right+1]:
        if(i%x==y):
            count+=1
    print count