class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        if (n > m) return false;

        vector<int> need(26, 0), window(26, 0);
        
        for (char c : s1) {
            need[c - 'a']++;
        }

        int i = 0;
        int j = 0;
        
        while (j < m) {
            window[s2[j] - 'a']++;
            
            if (j - i + 1 > n) {
                window[s2[i] - 'a']--;
                i++;
            }
            
            if (need == window) return true;
            
            j++;
        }
        
        return false;
    }
};
