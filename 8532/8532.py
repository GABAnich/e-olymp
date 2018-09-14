a, b = input().split()
a = int(a)
b = int(b)

for i in range(a, b+1):
    print(i**2, end=' ')
print()

for i in range(b, a-1, -1):
    print(i**3, end=' ')