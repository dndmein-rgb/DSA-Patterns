/* Approach 1: Top-Down DP (Memoization)
   Time Complexity: O(N)
   Space Complexity: O(N) (Recursion stack + memo array)
*/
class Solution {
public:
    int t[101];
    int solve(int i, vector<int>& nums) {
        int n = nums.size();
        // Base Case: No more houses to rob
        if (i >= n) return 0;
        
        if (t[i] != -1) return t[i];

        // Choice 1: Rob current house, then move to i + 2 (cannot rob adjacent)
        int take = nums[i] + solve(i + 2, nums);
        
        // Choice 2: Skip current house, move to i + 1
        int notTake = solve(i + 1, nums);

        return t[i] = max(take, notTake);
    }

    int rob(vector<int>& nums) {  
        memset(t, -1, sizeof(t));
        return solve(0, nums);
    }
};

/* Approach 2: Space Optimized (Iterative)
   Time Complexity: O(N)
   Space Complexity: O(1)
*/
class SolutionOptimized {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int prev2 = 0; // Represents solve(i+2)
        int prev1 = 0; // Represents solve(i+1)

        for (int i = n - 1; i >= 0; i--) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
