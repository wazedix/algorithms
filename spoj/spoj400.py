while True:
    n = int(raw_input())
    if n == 0:
        break
    _list = []
    s = raw_input()
    for i in range(len(s)/n):
        _list.append(s[i*n:i*n+n])
    for i in range(len(_list)):
        if i % 2 == 1:
            _list[i] = _list[i][::-1]
    ans = ''
    for i in range(n):
        for j in _list:
            ans += j[i]
    print ans
