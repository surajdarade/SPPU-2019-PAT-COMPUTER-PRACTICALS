class Item:
    def __init__(self, profit, weight):
        self.profit = profit
        self.weight = weight

def fractionalKnapsack(capacity, items):
    items.sort(key=lambda item: item.profit / item.weight, reverse=True)
    total_value = 0.0

    for item in items:
        if capacity >= item.weight:
            total_value += item.profit
            capacity -= item.weight
        else:
            total_value += item.profit * (capacity / item.weight)
            break
            
    return total_value

if __name__ == "__main__":
    n = int(input("Enter number of items: "))
    items = [Item(int(input(f"Enter profit of item {i + 1}: ")), int(input(f"Enter weight of item {i + 1}: "))) for i in range(n)]
    capacity = int(input("Enter capacity of knapsack: "))
    print("Maximum value in knapsack:", fractionalKnapsack(capacity, items))
    
    
    
    
# Sample Input and Output

# 3
# 60
# 10
# 100
# 20
# 120
# 30
# 50

# Output: Maximum value in knapsack: 240.0