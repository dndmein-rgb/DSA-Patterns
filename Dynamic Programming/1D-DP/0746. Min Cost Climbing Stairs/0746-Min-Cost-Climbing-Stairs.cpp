/* Approach 1: Top-Down DP (Memoization)
   Time Complexity: O(N)
   Space Complexity: O(N) (Recursion stack + memo array)
*/
class Solution {
public:
    int t[1001];
    int solve(vector<int>& cost, int i) {
        int n = cost.size();
        if (i >= n) return 0;
        if (t[i] != -1) return t[i];

        // Decision: From current step, we can jump 1 or 2 steps
        int take1 = cost[i] + solve(cost, i + 1);
        int take2 = cost[i] + solve(cost, i + 2);

        return t[i] = min(take1, take2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(t, -1, sizeof(t));
        // You can start at index 0 or index 1
        return min(solve(cost, 0), solve(cost, 1));
    }
};

/* Approach 2: Space Optimized (Iterative)
   Time Complexity: O(N)
   Space Complexity: O(1)
*/
class SolutionOptimized {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0; // Cost to reach 2 steps back
        int prev1 = 0; // Cost to reach 1 step back

        for (int i = 0; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        // Final answer is the minimum of landing on the last step 
        // or jumping over it to reach the top.
        return min(prev1, prev2);
    }
};
