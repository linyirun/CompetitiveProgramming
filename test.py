import math

tt = int(input())

while tt > 0:
    tt -= 1
    ls = input().split()
    n = int(ls[0])
    d = int(ls[1])

    f = math.factorial(n)
    num = 0

    for i in range(f):
        num += d * (10 ** i)

    print(num)
    for div in [1, 3, 5, 7, 9]:
        if num % div == 0:
            print(div, end=' ')
    print()

