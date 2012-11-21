n = raw_input()
for i in range(int(n)):
    nums = raw_input().split(' ')
    i = nums[0][::-1]
    j = nums[1][::-1]
    ans = int(i)+int(j)
    print int(str(ans)[::-1])
