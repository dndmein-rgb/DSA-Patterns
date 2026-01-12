/* Pattern: Dynamic Programming (0/1 Knapsack Variation)
   Time Complexity: O(N * TargetSum)
   Space Complexity: O(N * TargetSum)
*/

class Solution {
public:
    int t[201][10001]; // t[index][current_sum]
    int n;

    bool solve(int i, int target, vector<int>& nums) {
        // Base Case: Target sum reached
        if (target == 0)
            return true;
        // Base Case: Out of elements
        if (i == n)
            return false;

        if (t[i][target] != -1)
            return t[i][target];

        bool take = false;
        // Decision: Take current element if it doesn't exceed target
        if (nums[i] <= target)
            take = solve(i + 1, target - nums[i], nums);

        // Decision: Skip current element
        bool notTake = solve(i + 1, target, nums);

        return t[i][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // If total sum is odd, it's impossible to partition into two equal integers
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        memset(t, -1, sizeof(t));

        return solve(0, target, nums);
    }
};
