n = int(raw_input())

def fib(n):
    lut = [0 for _ in range(n+1)]
    lut[0] = 1
    lut[1] = 1
    lut[2] = 2
    for i in range(3,n+1):
        #print lut
        lut[i] = lut[i-1]+lut[i-2]
    return lut[n]

print fib(n)