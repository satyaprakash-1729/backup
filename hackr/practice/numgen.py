import random as rn
import sys
n = int(raw_input())
a = rn.sample(range(1,1000), n)

print n
for i in a:
    sys.stdout.write(str(i)+" ")
print ""