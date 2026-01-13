/* Pattern: Dynamic Programming (Two Strings / Subsequences)
   Time Complexity: O(N * M) - Where N is length of s and M is length of t
   Space Complexity: O(N * M) - For the memoization table
*/

class Solution {
public:
    int dp[1001][1001];
    int n, m;

    int solve(int i, int j, string& s, string& t) {
        // Base Case 1: We successfully matched all characters of string t
        if (j == m) return 1;
        // Base Case 2: s is exhausted but t still has characters left
        if (i == n) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, we have two choices:
        if (s[i] == t[j]) {
            /* 1. Take s[i]: Move both pointers (i+1, j+1)
               2. Skip s[i]: Even though it matches, skip it to see if 
                  later occurrences of s[i] can form a valid subsequence (i+1, j)
            */
            return dp[i][j] = solve(i + 1, j + 1, s, t) + solve(i + 1, j, s, t);
        }

        // If characters don't match, we MUST skip current character of s
        return dp[i][j] = solve(i + 1, j, s, t);
    }

    int numDistinct(string s, string t) {
        n = s.length();
        m = t.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, t);
    }
};
