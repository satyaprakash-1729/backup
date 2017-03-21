import sys
f = open("inp.txt","r")
string = f.read()
sArr = string.split("\n")
s = ""
for i in sArr:
    s+=i
s = raw_input() #s.lower()
al = "abcdefghijklmnopqrstuvwxyz"
alpha = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
alphaMat = [alpha[i:i+26] for i in range(26)]
alphaGrid = {}
for i in alphaMat:
    #for j in i:
    #    sys.stdout.write(j+" ")
    #print ""
    alphaGrid[i[0]] = i

key1 = "statistics"
ans = ""
key = ""
for i in range(len(s)):
    key+=key1[i%len(key1)]
for i in range(len(s)):
    ans+=alphaGrid['a'][alphaGrid[key[i]].index(s[i])]
print ans