/* Pattern: Graph / Matrix (DFS - Connected Components)
   Time Complexity: O(N * M) - Each cell is visited once
   Space Complexity: O(N * M) - Recursion stack in the worst case
*/



class Solution {
public:
    int n, m;

    int dfs(int i, int j, vector<vector<int>>& grid) {
        // Base Case: Out of bounds or current cell is water (0)
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return 0;

        // Mark current land as water (0) to "sink" it
        // This prevents double counting and infinite loops
        grid[i][j] = 0;

        // Return 1 (for current cell) + area of all 4 neighbors
        return 1 + 
               dfs(i + 1, j, grid) +
               dfs(i - 1, j, grid) +
               dfs(i, j + 1, grid) +
               dfs(i, j - 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If land (1) is found, calculate the full area of that island
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }
};
