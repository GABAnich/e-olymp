a, b = input().split()
a = int(a)
b = int(b)

def func(num):
    a = num // 1000
    b = (num // 100) % 10 
    c = (num % 100) // 10 
    d = (num % 1000) % 10

    if a != b and a != c and a != d and b != c and b != d and c != d:
        return True
    return False

arr = []
for i in range(a, b + 1):
    if func(i):
        arr.append(i)

print(' '.join(str(el) for el in arr))