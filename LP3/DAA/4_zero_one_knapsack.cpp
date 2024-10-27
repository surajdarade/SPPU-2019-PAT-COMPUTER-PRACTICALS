// # Below are two approaches of Dynamic Programming
// # 1. Memoization
// # 2. Tabulation

// # You can use any one.

// # 1. Memoization

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int knapsack_01(int n, vector<int>& values, vector<int>& weights, int W, unordered_map<string, int>& dp) {
    if (n == 0 || W == 0) return 0;

    string key = to_string(n) + "-" + to_string(W);
    if (dp.find(key) != dp.end()) return dp[key];

    if (weights[n - 1] <= W) {
        int included = values[n - 1] + knapsack_01(n - 1, values, weights, W - weights[n - 1], dp);
        int excluded = knapsack_01(n - 1, values, weights, W, dp);
        dp[key] = max(included, excluded);
    } else {
        dp[key] = knapsack_01(n - 1, values, weights, W, dp);
    }

    return dp[key];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter value of item " << (i + 1) << ": ";
        cin >> values[i];
        cout << "Enter weight of item " << (i + 1) << ": ";
        cin >> weights[i];
    }

    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    unordered_map<string, int> dp;
    int max_value = knapsack_01(n, values, weights, W, dp);
    cout << "Maximum value: " << max_value << endl;

    return 0;
}

// # 2. Tabulation

#include <iostream>
#include <vector>

using namespace std;

int knapsack_01(int n, vector<int>& values, vector<int>& weights, int W) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter value of item " << (i + 1) << ": ";
        cin >> values[i];
        cout << "Enter weight of item " << (i + 1) << ": ";
        cin >> weights[i];
    }

    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int max_value = knapsack_01(n, values, weights, W);
    cout << "Maximum value: " << max_value << endl;

    return 0;
}


// # Sample Input and Output

// # 3
// # 60
// # 10
// # 100
// # 20
// # 120
// # 30
// # 50

// # Output: Maximum value: 220