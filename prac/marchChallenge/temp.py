t = int(raw_input())
for _ in range(t):
    n,k = map(int,raw_input().split())
    s = raw_input()
    for i in range(2,n):
        left = k
        zeroCount = 0
        onesCount = 0
        flag = True
        for j in range(len(s)):
            if(s[j]=='1'):
                onesCount+=1
                zeroCount=0
            else:
                zeroCount+=1
                onesCount=0
            if(zeroCount==i+1):
                if(left==0):
                    flag = False
                    break
                onesCount=i-1
                zeroCount=0
                left-=1
            if(onesCount==i+1):
                if(left==0):
                    flag = False
                    break
                onesCount=0
                zeroCount=i-1
                left-=1
        if(flag):
            print i
            break


'''
    zeros = []
    ones = []
    zeroCount = 0
    onesCount = 0
    for i in range(len(s)):
        if i!=0:
            if(s[i]!=s[i-1]):
                if(s[i]=='1'):
                    zeros.append(zeroCount)
                else:
                    ones.append(onesCount)
        if s[i] == '0':
            zeroCount+=1
            onesCount = 0
        else:
            onesCount+=1
            zeroCount = 0
    if(onesCount!=0):
        ones.append(onesCount)
    elif(zeroCount!=0):
        zeros.append(zeroCount)
'''