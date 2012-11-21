t = raw_input()
for i in range(int(t)):
    n = int(raw_input())
    m = 5
    ans = 0
    while n >= m:
        ans += n / m
        m *= 5
    print ans
