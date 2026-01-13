/* Pattern: Dynamic Programming (Grid + DFS / Memoization)
   Time Complexity: O(N * M) - Each cell is computed exactly once
   Space Complexity: O(N * M) - For the memoization table and recursion stack
*/

// --- Approach 1: Explict Direction Variables ---
class Solution1 {
public:
    int t[201][201];
    int n, m;
    
    int solve(int i, int j, vector<vector<int>>& matrix) {
        if (t[i][j] != -1) return t[i][j];
        
        int curr = matrix[i][j];
        int top = 0, bottom = 0, left = 0, right = 0;

        if (i > 0 && curr < matrix[i - 1][j])
            top = 1 + solve(i - 1, j, matrix);
            
        if (i + 1 < n && curr < matrix[i + 1][j])
            bottom = 1 + solve(i + 1, j, matrix);
            
        if (j > 0 && curr < matrix[i][j - 1])
            left = 1 + solve(i, j - 1, matrix);
            
        if (j + 1 < m && curr < matrix[i][j + 1])
            right = 1 + solve(i, j + 1, matrix);
            
        // Final result needs +1 because base case starts at 0
        return t[i][j] = max({left, right, top, bottom});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(); m = matrix[0].size();
        int ans = 0;
        memset(t, -1, sizeof(t));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, matrix));
            }
        }
        return ans + 1; // Add 1 for the starting cell
    }
};

// --- Approach 2: Compact 'Best' Logic (Optimized) ---
class Solution2 {
public:
    int t[201][201];
    int n, m;

    int solve(int i, int j, vector<vector<int>>& matrix) {
        if (t[i][j] != -1) return t[i][j];

        int curr = matrix[i][j];
        int best = 1; // Every cell is a path of length 1 by itself

        if (i > 0 && curr < matrix[i - 1][j])
            best = max(best, 1 + solve(i - 1, j, matrix));

        if (i + 1 < n && curr < matrix[i + 1][j])
            best = max(best, 1 + solve(i + 1, j, matrix));

        if (j > 0 && curr < matrix[i][j - 1])
            best = max(best, 1 + solve(i, j - 1, matrix));

        if (j + 1 < m && curr < matrix[i][j + 1])
            best = max(best, 1 + solve(i, j + 1, matrix));

        return t[i][j] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(); m = matrix[0].size();
        memset(t, -1, sizeof(t));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, matrix));
            }
        }
        return ans;
    }
};
