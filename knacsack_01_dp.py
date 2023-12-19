
def knapsack_01(weights, profits, capacity):
    n = len(profits)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    for i in range(n + 1):
        for w in range(capacity + 1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif weights[i - 1] <= w:
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]
    for row in dp:
        print(row)

    return dp[n][capacity]
n = int(input("Enter the number of items: "))
weights = list(map(int, input("Enter the weights of the items: ").split()))
profits = list(map(int, input("Enter the profits of the items: ").split()))
capacity = int(input("Enter the capacity of the knapsack: "))

max_value = knapsack_01(weights, profits, capacity)
print("The maximum value that can be obtained:", max_value)
