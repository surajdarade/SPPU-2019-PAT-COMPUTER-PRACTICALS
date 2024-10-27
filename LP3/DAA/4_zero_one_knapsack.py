# Below are two approaches of Dynamic Programming
# 1. Memoization
# 2. Tabulation

# You can use any one.

# 1. Memoization

def knapsack_01(n, values, weights, W, dp):
    if n == 0 or W == 0:
        return 0
    
    if (n, W) in dp:
        return dp[(n, W)]
    
    if weights[n - 1] <= W:
        included = values[n - 1] + knapsack_01(n - 1, values, weights, W - weights[n - 1], dp)
        excluded = knapsack_01(n - 1, values, weights, W, dp)
        dp[(n, W)] = max(included, excluded)
    else:
        dp[(n, W)] = knapsack_01(n - 1, values, weights, W, dp)

    return dp[(n, W)]

if __name__ == "__main__":
    n = int(input("Enter the number of items: "))
    values = []
    weights = []
    
    for i in range(n):
        value = int(input(f"Enter value of item {i + 1}: "))
        weight = int(input(f"Enter weight of item {i + 1}: "))
        values.append(value)
        weights.append(weight)
    
    W = int(input("Enter the capacity of the knapsack: "))
    dp = {}
    max_value = knapsack_01(n, values, weights, W, dp)
    print("Maximum value:", max_value)


# 2. Tabulation

def knapsack_01(n, values, weights, W):
    dp = [[0] * (W + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(W + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1])
            else:
                dp[i][w] = dp[i - 1][w]
    
    return dp[n][W]

if __name__ == "__main__":
    n = int(input("Enter the number of items: "))
    values = []
    weights = []
    
    for i in range(n):
        value = int(input(f"Enter value of item {i + 1}: "))
        weight = int(input(f"Enter weight of item {i + 1}: "))
        values.append(value)
        weights.append(weight)
    
    W = int(input("Enter the capacity of the knapsack: "))
    max_value = knapsack_01(n, values, weights, W)
    print("Maximum value:", max_value)




# Sample Input and Output

# 3
# 60
# 10
# 100
# 20
# 120
# 30
# 50

# Output: Maximum value: 220