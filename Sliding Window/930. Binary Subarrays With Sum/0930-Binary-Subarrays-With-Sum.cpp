class Solution {
public:
    // Helper function to count subarrays with sum at most 'goal'
    int atMostK(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int n = nums.size();
        int i = 0, j = 0;
        long long sum = 0;
        int count = 0;
        
        while (j < n) {
            sum += nums[j];
            
            // Shrink window if current sum exceeds the goal
            while (i <= j && sum > goal) {
                sum -= nums[i];
                i++;
            }
            
            // All subarrays ending at j starting from i...j have sum <= goal
            count += j - i + 1;
            j++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Exactly(goal) = AtMost(goal) - AtMost(goal - 1)
        return atMostK(nums, goal) - atMostK(nums, goal - 1);
    }
};
