from difflib import SequenceMatcher

n,q = map(int,raw_input().split())
arr = []

for i in range(n):
    string = raw_input().rstrip()
    arr.append(string)

for i in range(q):
    a,b = map(int,raw_input().split())
    string1 = arr[a]
    string2 = arr[b]
    match = SequenceMatcher(None, string1, string2).find_longest_match(0, len(string1), 0, len(string2))
    print match.size