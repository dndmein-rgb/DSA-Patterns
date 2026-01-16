class Solution {
public:
    // DFS to check if a path already exists between start and target
    bool dfs(int start, int target, vector<vector<int>>& adj, vector<bool>& visited) {
        // If we reached the target, a path exists
        if (start == target) return true;

        visited[start] = true;

        for (int nei : adj[start]) {
            if (!visited[nei]) {
                if (dfs(nei, target, adj, visited))
                    return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // Adjacency list (1-indexed nodes)
        vector<vector<int>> adj(n + 1);

        // Process edges one by one
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            // Fresh visited array for each DFS check
            vector<bool> visited(n + 1, false);

            // If u and v are already connected, this edge is redundant
            if (dfs(u, v, adj, visited))
                return e;

            // Otherwise, add the edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
