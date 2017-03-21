import sys
N,L,R = map(int, raw_input().split())
length = map(int, raw_input().split())

length = sorted(length)

mindiff = float('inf')
for i in range(N-1):
    a = length[i+1]-length[i]
    if(a<mindiff):
        mindiff = a

maxsum = length[N-1]+length[N-2]
lower = 0
higher = 0
if(mindiff>=L):
    lower = mindiff
else:
    lower = L-1

if(maxsum<=R):
    higher = maxsum
else:
    higher = R+1

print higher - lower - 1