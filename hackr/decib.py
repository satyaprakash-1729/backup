import sys

q = int(raw_input())
query = []
rm = 0
for _ in range(q):
    n = int(raw_input())
    query.append(n)
    if n>rm:
        rm = n

arr = {}
for i in range(max(rm/10,100)):
    arr[i]=[]

toDecimal = [0 for _ in range(100*rm+1)]
for i in range(10):
    toDecimal[i] = i
    arr[i].append(i)

for i in range(10,100*rm+1):
    a = str(i)
    toDecimal[i] = int(a[0])*(2**(len(a)-1)) + toDecimal[int(a[1:])]
    arr[toDecimal[i]].append(i)

ans = []
for i in arr.values():
    for j in i:
        ans.append(j)

for i in query:
    print ans[i-1]