def palindrome(string):
    length = len(string)
    mid = length / 2
    if length % 2 == 0:
        newstring = string[:mid]+string[mid-1::-1]
    else:
        newstring = string[:mid]+string[mid::-1]
    return newstring

n = int(raw_input())
for i in range(n):
    num = raw_input()
    length = len(num)
    mid = length / 2
    newnum = palindrome(num)
    if int(newnum) <= int(num):
        newnum = int(newnum)+10**mid
    print palindrome(str(newnum))
