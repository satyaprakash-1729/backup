import sys

s = raw_input()

n = len(s)
ans = 0
k=1
for i in s:
    r = "1"*(n-k+1)
    ans = (ans+int(i)*k*int(r))%1000000007
    k+=1
print ans