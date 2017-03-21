import sys
n = int(raw_input())

arr = map(int,raw_input().split())
arr = sorted(arr, reverse = True)
for i in range(n-2):
    if(arr[i]>=arr[i+1]+arr[i+2]):
        continue
    print arr[i+2],arr[i+1],arr[i]
    sys.exit(0)

print -1