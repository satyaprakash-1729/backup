import math
glob = 1

def postOrder(i,n,q,ans,done):
    global glob
    if(i<n):
        postOrder(2*i,n,q,ans,done)
        postOrder(2*i+1,n,q,ans,done)
        try:
            ans[q.index(glob)] = i/2
        except:
            pass
        for r in range(len(ans)):
            if(ans[r]==i and done[r]==False):
                ans[r]=glob
                done[r] = True
                break
        glob+=1

def answer(h, q):
    if(2**h-1 not in q):
        rt = max(q)
        rt = int(math.ceil(math.log(rt,2)))
        h = rt+1
    ans = [0 for _ in range(len(q))]
    done = [False for _ in range(len(q))]
    postOrder(1,2**h,q,ans,done)
    if((2**h-1) in q):
        ans[q.index((2**h-1))]=-1
    return ans

print answer(30,[113232,4312312,731241])