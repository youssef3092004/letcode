


def Fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return Fibonacci(n-1) + Fibonacci(n-2)

print(Fibonacci(6))


# 5 => 0 1 1 2 3 5
# Fibonacci(5) => Fibonacci(4) + Fibonacci(3)
# Fibonacci(4) => Fibonacci(3) + Fibonacci(2)
# Fibonacci(3) => Fibonacci(2) + Fibonacci(1)
# Fibonacci(2) => Fibonacci(1) + Fibonacci(0)
# Fibonacci(0) => 0
# Fibonacci(1) => 1
# Fibonacci(2) => 1 + 0 = 1
# Fibonacci(3) => 1 + 1 = 2
# Fibonacci(4) => 2 + 1 = 3
# Fibonacci(5) => 3 + 2 = 5
