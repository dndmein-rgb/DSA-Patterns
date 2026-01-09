class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        int maxFreq = 0;
        unordered_map<char, int> freq;
        
        int i = 0, j = 0;
        while (j < n) {
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);
            
            while ((j - i + 1) - maxFreq > k) {
                freq[s[i]]--;
                i++;
            }
            
            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};
