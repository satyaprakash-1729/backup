import sys,os

def checker1(n):
    while n > 1:
        if(n%2==0):
            n=n/2+1
        else:
            n=n/2
        if(n==2):
            return True
    return False

def checker2(n):
    while n > 1:
        n=n/2
        if(n==2):
            return True
    return False

t = int(raw_input())
for _ in range(t):
    n,k = map(int,raw_input().rstrip().split())
    s = raw_input().rstrip()
    num = []
    c = 0
    i = 0
    while i < len(s):
        while s[i+c]==s[i]:
            c+=1
            if(i+c==len(s)):
                break
        i=i+c
        num.append(c)
        c=0 
    sent = num[0]
    sent2 = num[-1]
    num = sorted(num, reverse = True)
    while k>0:
        k-=1
        if num[0]==1:
            break
        elif len(num)>1 and num[1]==2 and num[0]==2:
            if(checker1(sent) or checker2(sent2)):
                num[1]=1
                if(checker1(sent) and checker2(sent2)):
                    num[0]=1
                    break
                else:
                    break
            else:
                break
        elif num[0]==2:
            if(checker1(sent) or checker2(sent2)):
                num[0]=1
                break
            else:
                break
        if(num[0]%2==1):
            part1 = num[0]/2
            del num[0]
            i=0
            while i<len(num) and part1<=num[i]:
                i+=1
            num = num[:i] + [part1,part1] + num[i:]
        else:
            part1 = num[0]/2
            part2 = (num[0]/2)-1
            del num[0]
            i=0
            while i<len(num) and part1<=num[i]:
                i+=1
            num = num[:i]+[part1,part2]+num[i:]
    print num[0]