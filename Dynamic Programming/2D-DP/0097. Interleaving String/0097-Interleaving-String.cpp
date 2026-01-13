/* Pattern: Dynamic Programming (Two Strings / Grid Path)
   Time Complexity: O(N * M) - Where N and M are lengths of s1 and s2
   Space Complexity: O(N * M) - For the memoization table
*/

class Solution {
public:
    int t[101][101];
    int n, m;

    bool solve(int i, int j, string& s1, string& s2, string& s3) {
        // Base Case: If both strings are exhausted, we successfully formed s3
        if (i == n && j == m)
            return true;
        
        if (t[i][j] != -1)
            return t[i][j];

        bool result = false;

        // Choice 1: Current character of s3 matches current character of s1
        // (i+j) always gives the current index we are looking for in s3
        if (i < n && s1[i] == s3[i + j]) {
            result |= solve(i + 1, j, s1, s2, s3);
        }

        // Choice 2: Current character of s3 matches current character of s2
        // We use '|=' to return true if EITHER path works
        if (!result && j < m && s2[j] == s3[i + j]) {
            result |= solve(i, j + 1, s1, s2, s3);
        }

        return t[i][j] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n = s1.length();
        m = s2.length();

        // Length check: s3 must be the exact sum of s1 and s2 lengths
        if (n + m != s3.length())
            return false;

        memset(t, -1, sizeof(t));
        return solve(0, 0, s1, s2, s3);
    }
};
