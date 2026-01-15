/* Pattern: Graph / Matrix (DFS - Connected Components)
   Time Complexity: O(N * M) - Every cell is visited once
   Space Complexity: O(N * M) - Worst case recursion depth (entire grid is land)
*/

class Solution {
public:
    int m, n;
    
    void dfs(int i, int j, vector<vector<char>>& grid) {
        // Base Case: Out of bounds or current cell is water ('0')
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
            return;

        // Mark the current land cell as visited by turning it into water
        // This prevents infinite loops and double counting
        grid[i][j] = '0';

        // Explore all 4 neighbors (Vertical and Horizontal)
        dfs(i + 1, j, grid); // Down
        dfs(i - 1, j, grid); // Up
        dfs(i, j + 1, grid); // Right
        dfs(i, j - 1, grid); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If we find land ('1'), it's a new island
                if (grid[i][j] == '1') {
                    // Sink the entire island using DFS
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};
