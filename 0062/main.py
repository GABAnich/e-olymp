import math

n = int(input())

i = 1
while True:
    if math.factorial(i) == n:
        print(i)
        break
    i += 1
