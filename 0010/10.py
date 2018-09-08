n = int(input())
saygac = n
days = 0
bucket = 0

while bucket <= 0.5:
    bucket += 1 / saygac
    saygac -= 1
    days += 1

print(n - days + 1)
