


def return_prime(n):
    if n < 2:
        return []

    upper = int(math.sqrt(n))
    prime = [True for _ in range(n + 1)]

    ret = []

    for i in range(2, n + 1):
        if not prime[i]:
            continue

        ret.append(prime[i])

        if i > upper:
            continue

        for j in range(i * i, n + 1):
            prime[j] = False
            j += i

    return ret


