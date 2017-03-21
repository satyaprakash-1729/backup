vals = map(int,raw_input().split())
wts = map(int,raw_input().split())
W = int(raw_input())

def knapsack01(vals,wts,W,i,tot):
    if(i==len(vals)):
        return tot
    else:
        if(W>=wts[i]):
            return max(knapsack01(vals,wts,W,i+1,tot),knapsack01(vals,wts,W-wts[i],i+1,tot+vals[i]))
        else:
            return knapsack01(vals,wts,W,i+1,tot)

def knapsack02(vals,wts,W):
    n = len(vals)
    ans = [[0 for i in range(n+1)] for j in range(W+1)]
    for i in range(1,W+1):
        for j in range(1,n+1):
            if(i>=wts[j-1]):
                ans[i][j] = max(ans[i-wts[j-1]][j-1]+vals[j-1], ans[i][j-1])
            else:
                ans[i][j] = ans[i][j-1]
    return ans[W][n]

print knapsack02(vals,wts,W)
print knapsack01(vals,wts,W,0,0)
