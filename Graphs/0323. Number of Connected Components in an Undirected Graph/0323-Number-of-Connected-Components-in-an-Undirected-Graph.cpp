class Solution {
public:
    // DFS to mark all nodes in the current connected component
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int nei : adj[node]) {
            if (!visited[nei])
                dfs(nei, adj, visited);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        // Build adjacency list for undirected graph
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;

        // Count how many DFS calls are needed
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }

        return components;
    }
};
