class Solution {
public:
    // Helper function to count subarrays with at most K odd numbers
    int atMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int n = nums.size();
        int i = 0, j = 0, count = 0;
        int oddCount = 0;
        
        while (j < n) {
            // If current number is odd, increment our window state
            if (nums[j] % 2 == 1) oddCount++;
          
            // If window becomes invalid (more than k odds), shrink from left
            while (oddCount > k) {
                if (nums[i] % 2 == 1) oddCount--;
                i++;
            }
            
            // Number of subarrays ending at j with at most k odd numbers
            count += j - i + 1;
            j++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // Exactly(K) = AtMost(K) - AtMost(K - 1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
