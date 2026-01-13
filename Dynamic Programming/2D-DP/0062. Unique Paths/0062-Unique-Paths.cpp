/* Pattern: Dynamic Programming (Grid / Matrix)
   Time Complexity: O(M * N)
   Space Complexity: O(M * N) 
*/

// Approach 1: Top-Down DP (Memoization)
class Solution {
public:
    int t[101][101];
    int M, N;

    int solve(int i, int j) {
        // Base Case: Reached the bottom-right corner
        if (i == M - 1 && j == N - 1) return 1;
        // Base Case: Out of bounds
        if (i >= M || j >= N) return 0;
        
        if (t[i][j] != -1) return t[i][j];

        // Decision: Move Down + Move Right
        return t[i][j] = solve(i + 1, j) + solve(i, j + 1);
    }

    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        memset(t, -1, sizeof(t));
        return solve(0, 0);
    }
};

// Approach 2: Bottom-Up DP (Tabulation)
class SolutionTab {
public:
    int uniquePaths(int m, int n) {
        // Initialize a 2D grid with 1s
        // (The first row and first column only have 1 way to be reached)
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // Number of ways to reach (i, j) is sum of ways from top and left
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
