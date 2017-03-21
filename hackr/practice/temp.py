glob = 1

def postOrder(ans,i,n,q,tree):
    global glob
    temp = glob
    if(i<n):
        postOrder(ans,2*i,n,q,tree)
        postOrder(ans,2*i+1,n,q,tree)
        tree[i] = glob
        glob+=1

def answer(h,q):
    global glob
    tree = [0 for i in range(100000000)]
    tree[0]=-1
    #treeOrder = [0 for i in range(2**h)]
    ans = [0 for i in range(len(q))]
    postOrder(ans,1,(2**h),q,tree)
    for i in range(len(tree)):
        if(tree[i] in q):
            ans[q.index(tree[i])] = tree[i/2]
    glob=1
    return ans

print answer(3,[5,6,7])