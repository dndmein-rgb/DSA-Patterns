class Solution {
public:
    // DFS to detect cycle and ensure connectivity
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        // Mark current node as visited
        visited[node] = true;

        // Traverse all neighbors
        for (int nei : adj[node]) {
            // Skip the edge going back to parent
            if (nei == parent) continue;

            // If already visited and not parent -> cycle detected
            if (visited[nei]) return false;

            // DFS on unvisited neighbor
            if (!dfs(nei, node, adj, visited)) return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // A valid tree must have exactly n - 1 edges
        if (n - 1 != edges.size()) return false;

        // Build undirected adjacency list
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        // Start DFS from node 0
        // If a cycle is detected, return false
        if (!dfs(0, -1, adj, visited))
            return false;

        // Ensure all nodes are connected
        for (bool b : visited) {
            if (!b) return false;
        }

        return true;
    }
};
