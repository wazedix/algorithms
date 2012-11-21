n = int(raw_input())
for i in range(n):
    x, y = raw_input().split(" ")
    x, y = int(x), int(y)
    if x == y:
        print x/2*4+x%2
    elif x == y + 2:
        print x/2*4-2+x%2
    else:
        print "No Number"
