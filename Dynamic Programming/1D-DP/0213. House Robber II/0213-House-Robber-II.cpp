/* Pattern: Dynamic Programming (Circular Arrangement)
   Time Complexity: O(N) - Two linear passes
   Space Complexity: O(N) - Memoization array and recursion stack
*/

class Solution {
public:
    int t[101];
    
    int solve(int i, vector<int>& nums, int n) {
        // Base case: No more houses to rob
        if (i >= n)
            return 0;
            
        if (t[i] != -1)
            return t[i];
            
        // Option 1: Rob current house, skip next house
        int take = nums[i] + solve(i + 2, nums, n);
        
        // Option 2: Skip current house
        int notTake = solve(i + 1, nums, n);
        
        return t[i] = max(take, notTake);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Handle single house edge case
        if (n == 1) return nums[0];
        
        // Scenario 1: Rob houses from index 0 to n-2 (Excluding the last house)
        memset(t, -1, sizeof(t));
        int house1 = solve(0, nums, n - 1);
        
        // Scenario 2: Rob houses from index 1 to n-1 (Excluding the first house)
        memset(t, -1, sizeof(t));
        int house2 = solve(1, nums, n);
        
        // The answer is the maximum loot from either scenario
        return max(house1, house2);
    }
};
