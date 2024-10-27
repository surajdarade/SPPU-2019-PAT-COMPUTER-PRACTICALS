# 1. Direct Input
# 2. User Input

# You can use any one.

# 1. Direct Input

from operator import attrgetter

class Job:
    def __init__(self, jobId, deadline, profit):
        self.jobId = jobId
        self.deadline = deadline
        self.profit = profit

def comparison(x, y):
    return x.profit > y.profit

def jobScheduling(arr, n):
    arr.sort(key=lambda x: x.profit, reverse=True)

    jobsSelected = [-1] * 3
    slots = [False] * 3

    for i in range(n):
        for j in range(arr[i].deadline - 1, -1, -1):
            if not slots[j]:
                jobsSelected[j] = i
                slots[j] = True
                break

    max_profit = 0
    for i in range(3):
        if jobsSelected[i] != -1:
            max_profit += arr[jobsSelected[i]].profit
            x = arr[jobsSelected[i]].jobId
            print(f"{x} {arr[jobsSelected[i]].profit}")

    print(f"Max Profit is {max_profit}")

if __name__ == "__main__":
    arr = [Job('a', 2, 100), 
           Job('b', 1, 19), 
           Job('c', 2, 27), 
           Job('d', 1, 25), 
           Job('e', 3, 15)]

    n = len(arr)

    jobScheduling(arr, n)


# 2. User Input

class Job:
    def __init__(self, jobId, deadline, profit):
        self.jobId = jobId
        self.deadline = deadline
        self.profit = profit

def comparison(x):
    return x.profit

def jobScheduling(arr, n):
    arr.sort(key=comparison, reverse=True)

    jobsSelected = [-1] * 3
    slots = [False] * 3

    for i in range(n):
        for j in range(arr[i].deadline - 1, -1, -1):
            if not slots[j]:
                jobsSelected[j] = i
                slots[j] = True
                break

    max_profit = 0
    for i in range(3):
        if jobsSelected[i] != -1:
            max_profit += arr[jobsSelected[i]].profit
            x = arr[jobsSelected[i]].jobId
            print(f"{x} {arr[jobsSelected[i]].profit}")

    print(f"Max Profit is {max_profit}")

if __name__ == "__main__":
    n = int(input("Enter the number of jobs: "))
    arr = []
    print("Enter job details (jobId, deadline, profit) for each job:")
    for i in range(n):
        print(f"Job {i + 1}: ", end="")
        jobId, deadline, profit = input().split()
        deadline = int(deadline)
        profit = int(profit)
        arr.append(Job(jobId, deadline, profit))

    jobScheduling(arr, n)
    
    
    
    
# Sample Input and Output for User Input Program: 


# Enter the number of jobs: 5
# Enter job details (jobId, deadline, profit) for each job:
# Job 1: a 2 100
# Job 2: b 1 19
# Job 3: c 2 27
# Job 4: d 1 25
# Job 5: e 3 15
# c 27
# a 100
# e 15
# Max Profit is 142