/* Approach 1: Top-Down DP (Memoization)
   Time Complexity: O(N^2)
   Space Complexity: O(N^2)
*/
class SolutionDP {
public:
    int n;
    string s;
    int t[1001][1001];

    bool isPal(int i, int j) {
        if (i >= j) return true;
        if (t[i][j] != -1) return t[i][j];

        if (s[i] != s[j])
            return t[i][j] = false;

        return t[i][j] = isPal(i + 1, j - 1);
    }

    string longestPalindrome(string str) {
        s = str;
        n = s.length();
        int maxLen = 1, start = 0;
        memset(t, -1, sizeof(t));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPal(i, j)) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

/* Approach 2: Expand Around Center (Optimized)
   Time Complexity: O(N^2)
   Space Complexity: O(1)
*/
class Solution {
public:
    int start = 0, maxLen = 1;

    void expand(int i, int j, string& s) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            int len = j - i + 1;
            if (len > maxLen) {
                maxLen = len;
                start = i;
            }
            i--;
            j++;
        }
    }

    string longestPalindrome(string s) {
        if (s.length() < 2) return s;
        for (int i = 0; i < s.length(); i++) {
            expand(i, i, s);     // Odd length palindromes (center is i)
            expand(i, i + 1, s); // Even length palindromes (center is i, i+1)
        }
        return s.substr(start, maxLen);
    }
};
