class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int currSum = 0;
        int minLen = n + 1;
        int i = 0, j = 0;

        while (j < n) {
            currSum += nums[j];

            while (currSum >= target) {
                minLen = min(minLen, j - i + 1);
                currSum -= nums[i];
                i++;
            }

            j++;
        }

        return minLen == n + 1 ? 0 : minLen;
    }
};
