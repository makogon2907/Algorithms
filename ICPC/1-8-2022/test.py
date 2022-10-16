
def fact(n):
    res = 1
    for i in range(1, n + 1):
        res *= i

    return res


def get_last_non_zero(n):
    n = str(n)
    if len(n) == 1:
        return n
    while n[-1] == '0':
        n = n[:len(n) - 1]

    return n[len(n) - 2:]


rests = []

for i in range(0, 1000):
    rests.append(int(get_last_non_zero(fact(i))))

print(rests)
