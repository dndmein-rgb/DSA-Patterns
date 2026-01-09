class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> need(256, 0), window(256, 0);
        vector<int> ans;
        
        for (char c : p) {
            need[c]++;
        }
        
        int i = 0, j = 0;
        while (j < s.size()) {
            char c = s[j];
            window[c]++;
            
            if (j - i + 1 > p.length()) {
                window[s[i]]--;
                i++;  
            }
            
            if (j - i + 1 == p.length() && need == window) {
                ans.push_back(i);
            }
            j++;
        }
        return ans;
    }
};
