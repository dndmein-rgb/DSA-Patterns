/* Pattern: Dynamic Programming (Two Strings / Subsequences)
   Time Complexity: O(N * M) - Where N and M are lengths of the strings
   Space Complexity: O(N * M) - For the memoization table
*/

class Solution {
public:
    int t[1001][1001];
    int n, m;

    int solve(int i, int j, string& text1, string& text2) {
        // Base Case: If either string is exhausted, no more common characters
        if (i >= n || j >= m) return 0;

        if (t[i][j] != -1) return t[i][j];

        // Case 1: Characters match
        if (text1[i] == text2[j]) {
            // Include this character and move both pointers
            return t[i][j] = 1 + solve(i + 1, j + 1, text1, text2);
        }

        // Case 2: Characters do not match
        // Try skipping one character from text1 OR one from text2 and take the max
        return t[i][j] = max(solve(i + 1, j, text1, text2), 
                             solve(i, j + 1, text1, text2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        n = text1.length();
        m = text2.length();
        memset(t, -1, sizeof(t));
        return solve(0, 0, text1, text2);
    }
};
