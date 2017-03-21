import sys

def printer(n):
    if(n==2):
        sys.stdout.write("min(int, int)")
    else:
        sys.stdout.write("min(int, ")
        printer(n-1)
        sys.stdout.write(")")

n = int(raw_input())
printer(n)