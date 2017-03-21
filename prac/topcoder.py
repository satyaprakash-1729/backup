arr = map(int,raw_input().split())

maxSeq = [0]*len(arr)

for i in range(len(arr)):
    for j in range(2,len(arr)):
        