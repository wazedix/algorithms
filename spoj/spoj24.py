t = raw_input()
for i in range(int(t)):
    n = int(raw_input())
    print reduce(lambda x,y:x*y,range(1,n+1))
