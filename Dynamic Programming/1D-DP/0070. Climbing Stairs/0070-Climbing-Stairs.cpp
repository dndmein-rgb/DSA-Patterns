/* Pattern: Dynamic Programming (Memoization)
   Time Complexity: O(N) - Each state is computed once.
   Space Complexity: O(N) - Recursion stack and DP array.
*/

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        // Base Case: Only 1 way to stay at the ground (0 steps)
        if (n == 0) return 1;
        // Base Case: Cannot go below ground
        if (n < 0) return 0;
        
        if (dp[n] != -1) return dp[n];

        // To reach step n, you could have come from (n-1) or (n-2)
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int climbStairs(int n) {
        if (n <= 0) return (n == 0) ? 1 : 0;

        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
