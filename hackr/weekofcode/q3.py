import sys

vowels = "aeiou"
consonants = "bcdfghjklmnpqrstvwxz"

ans = []

def printer(n, prevVowel, string=""):
    if(n==0):
        ans.append(string)
    else:
        if(prevVowel):
            for i in consonants:
                printer(n-1,False, string+i)
        else:
            for i in vowels:
                printer(n-1,True, string+i)

n=int(raw_input())
printer(n,False)
printer(n,True)
for i in ans:
    print i            