class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int total = 0, rotten = 0, minutes = 0;
        queue<pair<int,int>> q;

        // Count total oranges and enqueue all rotten ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) total++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // Multi-source BFS
        while (!q.empty()) {
            int sz = q.size();
            rotten += sz;

            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = r + dx[d];
                    int nc = c + dy[d];

                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    if (grid[nr][nc] != 1) continue;

                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }

            if (!q.empty()) minutes++;
        }

        return (total == rotten) ? minutes : -1;
    }
};
