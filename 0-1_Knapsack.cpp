#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0-1 Knapsack problem using dynamic programming
int knapsackDP(int capacity, vector<int>& weights, vector<int>& values, int n) {
    // Create a 2D DP array to store maximum value at each n, capacity
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the DP table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][capacity]; // The last cell contains the maximum value for the given capacity
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<int> values(n), weights(n);
    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    int maxValue = knapsackDP(capacity, weights, values, n);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
