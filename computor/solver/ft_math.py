def ft_abs(number: float) -> float:
    return number if number >= 0 else -number


def ft_sqrt(s: float) -> float:
    if s < 0:
        raise ValueError
    elif s == 0:
        return 0

    def sqrt_loop(n, x):
        a = (s - (x * x)) / (2 * x)
        if ft_abs(a) >= ft_abs(n):
            return x
        return sqrt_loop(a, (x + a - (a * a) / (2 * (x + a))))

    return sqrt_loop(s, s / 2)


def ft_convert(line: str):
    return float(line) if '.' in line else int(line)
