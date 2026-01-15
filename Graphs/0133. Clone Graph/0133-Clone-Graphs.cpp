/*
Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneDfs(Node* node) {
        if (!node) return NULL;

        // If already cloned, return the clone
        if (mp.count(node)) return mp[node];

        // Create a new node
        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneDfs(neighbor));
        }

        return cloneNode;
    }

    Node* cloneGraph(Node* node) {
        return cloneDfs(node);
    }
};
