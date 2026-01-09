class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> need(256, 0), window(256, 0);
        int required = 0;
        
        for (char c : t) {
            if (need[c] == 0) required++;
            need[c]++;
        }

        int minLen = 1e9;
        int formed = 0;
        int i = 0, j = 0, start = 0;

        while (j < s.size()) {
            char c = s[j];
            window[c]++;

            if (need[c] > 0 && window[c] == need[c]) {
                formed++;
            }

            while (i <= j && formed == required) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                char leftChar = s[i];
                window[leftChar]--;

                if (need[leftChar] > 0 && window[leftChar] < need[leftChar]) {
                    formed--;
                }
                i++;
            }
            j++;
        }

        return minLen == 1e9 ? "" : s.substr(start, minLen);
    }
};
