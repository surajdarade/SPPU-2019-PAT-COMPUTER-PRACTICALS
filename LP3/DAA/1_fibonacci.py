def fib(n, steps):
    steps[0] += 1
    if n <= 1:
        return n
    return fib(n - 1, steps) + fib(n - 2, steps)

n = int(input("Enter a number: "))
steps = [0]
result = fib(n, steps)
print(f"Fibonacci({n}) = {result}")
print(f"Steps: {steps[0]}")