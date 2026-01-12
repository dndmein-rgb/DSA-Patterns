/* Approach 1: Top-Down DP (Memoization)
   Time Complexity: O(N^2)
   Space Complexity: O(N^2)
*/
class Solution {
public:
    int t[2501][2501];
    
    int solve(int i, int prev_idx, vector<int>& nums) {
        if (i == nums.size()) return 0;

        // Using prev_idx + 1 to handle the -1 initial state in the memo table
        if (t[i][prev_idx + 1] != -1) return t[i][prev_idx + 1];

        // Option 1: Skip the current element
        int notTake = solve(i + 1, prev_idx, nums);

        // Option 2: Take the current element (if it's greater than the previous choice)
        int take = 0;
        if (prev_idx == -1 || nums[i] > nums[prev_idx]) {
            take = 1 + solve(i + 1, i, nums);
        }

        return t[i][prev_idx + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(0, -1, nums);
    }
};

/* Approach 2: Bottom-Up DP (Standard O(N^2))
   Time Complexity: O(N^2)
   Space Complexity: O(N)
*/
class SolutionTab {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); // Every element is an LIS of length 1
        int maxLIS = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxLIS = max(maxLIS, dp[i]);
        }
        return maxLIS;
    }
};
