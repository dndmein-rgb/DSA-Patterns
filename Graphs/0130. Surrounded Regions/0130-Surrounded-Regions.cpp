class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;

        // Push all boundary 'O's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) &&
                    board[i][j] == 'O') {
                    board[i][j] = '#';
                    q.push({i, j});
                }
            }
        }

        int delRow[4] = {-1, 1, 0, 0};
        int delCol[4] = {0, 0, -1, 1};

        // BFS to mark all connected boundary regions
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + delRow[k];
                int nc = c + delCol[k];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    board[nr][nc] == 'O') {
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }

        // Flip surrounded regions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};

//dfs
class Solution {
public:
    int n, m;
    int delRow[4] = {-1, 1, 0, 0};
    int delCol[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<char>>& board) {
        board[r][c] = '#';

        for (int k = 0; k < 4; k++) {
            int nr = r + delRow[k];
            int nc = c + delCol[k];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                board[nr][nc] == 'O') {
                dfs(nr, nc, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        // Run DFS from all boundary 'O's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) &&
                    board[i][j] == 'O') {
                    dfs(i, j, board);
                }
            }
        }

        // Flip surrounded regions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};

