class Solution {
public:
    int m, n;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void bfs(queue<pair<int,int>>& q,
             vector<vector<int>>& ocean,
             vector<vector<int>>& heights) {

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;
                if (ocean[nr][nc])
                    continue;
                if (heights[nr][nc] < heights[r][c])
                    continue;

                ocean[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        queue<pair<int,int>> qPacific, qAtlantic;

        // Pacific borders
        for (int i = 0; i < m; i++) {
            qPacific.push({i, 0});
            pacific[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            qPacific.push({0, j});
            pacific[0][j] = 1;
        }

        // Atlantic borders
        for (int j = 0; j < n; j++) {
            qAtlantic.push({m - 1, j});
            atlantic[m - 1][j] = 1;
        }
        for (int i = 0; i < m; i++) {
            qAtlantic.push({i, n - 1});
            atlantic[i][n - 1] = 1;
        }

        bfs(qPacific, pacific, heights);
        bfs(qAtlantic, atlantic, heights);

        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});

        return result;
    }
};
