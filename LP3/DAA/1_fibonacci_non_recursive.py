def fib(n, steps):
    a, b = 0, 1
    if n == 0:
        return a
    for i in range(2, n+1):
        steps[0] += 1
        a, b = b, a + b
    steps[0] += 1
    return b

n = int(input())
steps = [0]
result = fib(n, steps)
print(f"Fibonacci({n}) = {result}")
print(f"Steps: {steps[0]}")