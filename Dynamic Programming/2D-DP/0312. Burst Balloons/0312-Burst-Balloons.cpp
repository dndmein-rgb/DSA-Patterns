/* Pattern: Matrix Chain Multiplication (MCM) / Interval DP
   Time Complexity: O(N^3) - N^2 states and O(N) loop per state
   Space Complexity: O(N^2) - For the memoization table
*/

class Solution {
public:
    int t[302][302];
    int n;

    int solve(int i, int j, vector<int>& nums) {
        // Base Case: If the interval is invalid
        if (i > j) return 0;

        if (t[i][j] != -1) return t[i][j];

        int maxi = -1e9;

        /* Key Logic: We pick 'ind' as the LAST balloon to burst in the interval [i, j].
           This ensures that the balloons at i-1 and j+1 are still present to be
           multiplied with the balloon at 'ind'.
        */
        for (int ind = i; ind <= j; ind++) {
            int cost = nums[i - 1] * nums[ind] * nums[j + 1] +
                       solve(i, ind - 1, nums) +
                       solve(ind + 1, j, nums);
            maxi = max(maxi, cost);
        }

        return t[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        n = nums.size();
        // Step 1: Add boundary balloons with value 1
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        memset(t, -1, sizeof(t));

        // Step 2: Start solving for the original range [1, n]
        return solve(1, n, nums);
    }
};
