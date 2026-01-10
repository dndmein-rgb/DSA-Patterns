class Solution {
public:
    // Helper function to count subarrays with at most K distinct integers
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, count = 0;
        unordered_map<int, int> freq;
        
        while (j < n) {
            freq[nums[j]]++;
          
            while (freq.size() > k) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) freq.erase(nums[i]);
                i++;
            }
            
            // The number of subarrays ending at j with at most k distinct elements
            // is exactly the current window size (j - i + 1).
            count += j - i + 1;
            j++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Exactly(K) = AtMost(K) - AtMost(K - 1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
