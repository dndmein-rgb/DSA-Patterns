/* Pattern: Dynamic Programming (Two Strings / Levenshtein Distance)
   Time Complexity: O(N * M) - Every pair of indices (i, j) is computed once
   Space Complexity: O(N * M) - For the memoization table
*/

class Solution {
public:
    int t[501][501];
    int n, m;

    int solve(int i, int j, string& word1, string& word2) {
        // Base Case: If word1 is exhausted, we must insert all remaining characters of word2
        if (i == n)
            return m - j;
        // Base Case: If word2 is exhausted, we must delete all remaining characters of word1
        if (j == m)
            return n - i;

        if (t[i][j] != -1)
            return t[i][j];

        // If characters match, no operation is needed for this position
        if (word1[i] == word2[j]) {
            return t[i][j] = solve(i + 1, j + 1, word1, word2);
        }

        /* If characters don't match, we try 3 operations and take the minimum:
           1. Insert: solve(i, j + 1) -> assume we inserted word2[j] before word1[i]
           2. Delete: solve(i + 1, j) -> delete word1[i]
           3. Replace: solve(i + 1, j + 1) -> replace word1[i] with word2[j]
        */
        return t[i][j] = 1 + min({
            solve(i, j + 1, word1, word2),     // Insert
            solve(i + 1, j, word1, word2),     // Delete
            solve(i + 1, j + 1, word1, word2)  // Replace
        });
    }

    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();
        memset(t, -1, sizeof(t));
        return solve(0, 0, word1, word2);
    }
};
