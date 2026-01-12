/* Pattern: Dynamic Programming (Space Optimized)
   Time Complexity: O(N)
   Space Complexity: O(1) - No array or recursion stack used.
*/

class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        // Since we only need the last two steps to calculate the current one:
        // prev2 is dp[i-2], prev1 is dp[i-1]
        int prev2 = 1; // ways to reach step 1
        int prev1 = 2; // ways to reach step 2
        int current = 0;

        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2;
            // Shift variables forward for the next iteration
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
