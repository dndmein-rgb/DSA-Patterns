/* Pattern: Dynamic Programming (0/1 Knapsack Variation)
   Time Complexity: O(N * TotalSum) 
   Space Complexity: O(N * TotalSum)
*/

class Solution {
public:
    // Offset of 1000 is used because the sum can be negative (from -1000 to 1000)
    // and array indices must be non-negative.
    int t[21][2001];
    int n;
    int Target;

    int solve(int i, int curr, vector<int>& nums) {
        // Base Case: If all numbers are used, check if the current sum matches the Target
        if (i == n)
            return curr == Target;
        
        // Memoization check: using +1000 offset to map curr [-1000, 1000] to [0, 2000]
        if (t[i][curr + 1000] != -1)
            return t[i][curr + 1000];

        // Choice 1: Add the current number
        int add = solve(i + 1, curr + nums[i], nums);
        // Choice 2: Subtract the current number
        int sub = solve(i + 1, curr - nums[i], nums);

        // Store result with offset
        return t[i][curr + 1000] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        Target = target;
        // Initialize memo table with -1
        memset(t, -1, sizeof(t));
        return solve(0, 0, nums);
    }
};
