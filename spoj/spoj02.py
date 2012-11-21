t = int(raw_input())
_list = []
s = 1000
for j in range(2, int(s ** 0.5)):
    for k in range(2, s/j):
        _list.append(j*k)
print _list
for i in range(t):
    n, m = raw_input().split(' ')
    for j in range(min(n,m),max(n,m)+1):
        if not j in _list: 
            print j
    print ''
