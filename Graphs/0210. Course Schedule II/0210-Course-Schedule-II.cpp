class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // indegree[i] = number of prerequisites for course i
        vector<int> indegree(numCourses, 0);

        // adjacency list: b -> a means b must be taken before a
        vector<vector<int>> adj(numCourses);

        // Build graph and indegree array
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;

        // Push all courses with no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        // Kahn's Algorithm (BFS Topological Sort)
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Add course to ordering
            ans.push_back(node);

            // Reduce indegree of dependent courses
            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        // If all courses are processed, return order
        // Otherwise, a cycle exists
        return numCourses == ans.size() ? ans : vector<int>();
    }
};
