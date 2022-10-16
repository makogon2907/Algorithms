

def fact(n):
    res = 1
    for i in range(1, n + 1):
        res *= i

    return res


def get_last_non_zero(n):
    while n > 0 and n % 10 == 0:
        n //= 10
    return n % 100


def bin_pow(osn, pok, _mod):
    res = 1
    while pok > 0:
        if pok & 1:
            res *= osn
            res %= _mod
        osn *= osn
        osn %= _mod
        pok //= 2

    return res


def num_2s(n) -> int:
    r = 2
    ans = 0
    while r <= n:
        ans += n // r
        r *= 2
    return ans


def num_5s(n) -> int:
    r = 5
    ans = 0
    while r <= n:
        ans += n // r
        r *= 5
    return ans


rests = [1]

for i in range(1, 1000):
    rests.append(int(get_last_non_zero(fact(i))))


def get_answer(n):
    if n < 10:
        return rests[n]

    ans = bin_pow(rests[100], n // 100, 100)
    for i in range((n // 100) * 100 + 1, n + 1):
        ans *= i

    return int(get_last_non_zero(ans))


print(rests[100])
print(rests[200])

for i in range(1000):
    if get_answer(i) != rests[i]:
        print("KEK", i)
        print(rests[i], get_answer(i))
        exit(1)

n = int(input())
print(get_answer(n))
