t = int(raw_input())
k = int(raw_input())

arr = []
for i in range(t):
    a = int(raw_input())
    arr.append(a)

ansMat = [[-11 for _ in range(k+1)] for j in range(t+1)]
def dp(arr,n,k,ans,ansMat):
    if ansMat[n][k]!=-11:
        return ansMat[n][k]
    if k==0:
        ansMat[n][k]=0
        return ansMat[n][k]
    elif n==0:
        ansMat[n][k]=100000
        return ansMat[n][k]
    ansa = 0
    for i in ans:
        ansa+=abs(i-arr[n-1])
    ansMat[n][k] = min(ansa+dp(arr,n-1,k-1,ans+[arr[n-1]],ansMat),dp(arr,n-1,k,ans,ansMat))
    return ansMat[n][k]

print dp(arr,t,k,[],ansMat)