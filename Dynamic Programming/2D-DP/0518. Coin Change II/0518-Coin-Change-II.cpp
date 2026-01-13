/* Pattern: Dynamic Programming (Unbounded Knapsack)
   Time Complexity: O(N * amount) - N is number of coins
   Space Complexity: O(N * amount) - For memoization table
*/

class Solution {
public:
    int t[301][5001];
    int n;

    int solve(int i, int amount, vector<int>& coins) {
        // Base Case: If amount becomes 0, we found 1 valid way
        if (amount == 0)
            return 1;
        
        // Base Case: No more coins left to pick
        if (i >= n)
            return 0;

        if (t[i][amount] != -1)
            return t[i][amount];

        if (amount >= coins[i]) {
            // Unbounded Logic: 
            // 1. Take: solve(i, ...) stays at 'i' because we can reuse the same coin
            // 2. Skip: solve(i + 1, ...) moves to the next coin
            return t[i][amount] = solve(i, amount - coins[i], coins) +
                                  solve(i + 1, amount, coins);
        }

        // Current coin is too large, must skip
        return t[i][amount] = solve(i + 1, amount, coins);
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(t, -1, sizeof(t));
        return solve(0, amount, coins);
    }
};
