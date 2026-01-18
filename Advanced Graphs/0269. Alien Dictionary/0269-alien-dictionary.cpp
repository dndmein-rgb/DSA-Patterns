class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // Initialize all characters
        for (auto& w : words)
            for (char c : w)
                indegree[c] = 0;

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            int j = 0;

            while (j < len && w1[j] == w2[j])
                j++;

            // Invalid prefix case
            if (j == len && w1.size() > w2.size())
                return "";

            if (j < len) {
                char u = w1[j];
                char v = w2[j];
                if (!adj[u].count(v)) {
                    adj[u].insert(v);
                    indegree[v]++;
                }
            }
        }

        // Topological sort (Kahn's Algorithm)
        queue<char> q;
        for (auto& [c, deg] : indegree)
            if (deg == 0)
                q.push(c);

        string order;
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            order.push_back(u);

            for (char v : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        // Cycle check
        if (order.size() != indegree.size())
            return "";

        return order;
    }
};
