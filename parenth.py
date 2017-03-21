import sys

def printer(s,i,j):
    if(i+1==j):
        sys.stdout.write(s)
    else:
        for k in range(i,j+1):
            sys.stdout.write("(")
            printer(s[i:k-1],i,k-1)
            printer(s[k+1:j],k+1,j)
            sys.stdout.write(")")

sf = raw_input()
printer(sf,0,len(sf))