class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        // If both nodes have same root, cycle detected
        if (px == py) return false;

        // Union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        // Initially, each node is its own parent
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto& e : edges) {
            // If union fails, this edge is redundant
            if (!unite(e[0], e[1]))
                return e;
        }

        return {};
    }
};
