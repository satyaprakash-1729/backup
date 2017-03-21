N,L,R = map(int,raw_input().split())
arr = map(int,raw_input().split())

brr = sorted(arr)
mina = float('inf')
maxa = -float('inf')
for i in range(1,len(brr)):
    if(brr[-i] + brr[-i-1] > maxa):
        maxa = brr[-i] + brr[-i-1]
    if(brr[-i] - brr[-i-1] < mina):
        mina = brr[-i] - brr[-i-1]

ans = 0

flag = False
if(mina<L):
    flag = True
    ans += 1
if(maxa>R):
    ans += 1

if(ans==2):
    ans += max(R-L-1,0)
elif(ans==1):
    if(flag):
        ans += max(maxa-L-1,0)
    else:
        ans += max(R-mina-1,0)
else:
    ans += max(maxa-mina-1,0)
print ans