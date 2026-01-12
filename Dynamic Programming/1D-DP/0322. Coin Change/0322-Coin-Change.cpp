/* Pattern: Dynamic Programming (Unbounded Knapsack)
   Time Complexity: O(n * amount)
   Space Complexity: O(n * amount)
*/

class Solution {
public:
    // t[index][remaining_amount]
    int t[13][10001];
    int n;

    int solve(int i, vector<int>& coins, int amount) {
        // Base Case: Amount reached exactly
        if (amount == 0)
            return 0;
        
        // Base Case: Out of coins or amount went negative
        if (i >= n || amount < 0)
            return 1e9; // Represent infinity

        if (t[i][amount] != -1)
            return t[i][amount];

        int take = 1e9;
        if (amount >= coins[i]) {
            // Unbounded: Stay at index 'i' because we can use the same coin again
            take = 1 + solve(i, coins, amount - coins[i]);
        }
        
        // Skip current coin and move to the next
        int notTake = solve(i + 1, coins, amount);

        return t[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        memset(t, -1, sizeof(t));
        int ans = solve(0, coins, amount);
        
        // If ans is still 1e9, it means the amount cannot be formed
        return ans >= 1e9 ? -1 : ans;
    }
};
