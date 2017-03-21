from myLib1729 import ngramsDictionary,countSort
n = int(raw_input())
f = open("inp.txt","r")
string = f.read()
sArr = string.split("\n")
slist = []
for i in sArr:
    for j in i:
        slist.append(j)
a = ngramsDictionary(slist,n)
b = countSort(a,1000)
k=0
for key in b:
    if(k>=20):
        break
    print key
    k+=1