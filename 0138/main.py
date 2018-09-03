n = int(input())
count = 0

count += n // 500
n = n % 500

count += n // 200
n = n % 200

count += n // 100
n = n % 100

count += n // 50
n = n % 50

count += n // 20
n = n % 20

count += n // 10
n = n % 10

if n < 10 and n > 0:
    print(-1)
    exit()

if count == 10:
    print(-1)
else:
    print(count)
