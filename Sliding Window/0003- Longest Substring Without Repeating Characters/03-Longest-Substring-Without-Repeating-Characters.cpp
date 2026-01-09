class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        vector<int> last(256, -1);
        
        int i = 0, j = 0;
        while (j < n) {
            if (last[s[j]] >= i) {
                i = last[s[j]] + 1;
            }
            
            last[s[j]] = j;
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        
        return maxLen;
    }
};
