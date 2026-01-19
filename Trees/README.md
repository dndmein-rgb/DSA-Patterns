# 🌳 Binary Tree Hierarchy: From Basics to Advanced Patterns

This roadmap represents the skill progression required to master Binary Tree problems.

---

## 🧱 Level 1: Absolute Basics (Mechanical Traversal)

**The Focus**: Understanding tree traversal, depth, and node counting.

* [104. Maximum Depth of Binary Tree](./0104-Maximum-Depth-of-Binary-Tree) – Classic DFS/BFS traversal.
* [226. Invert Binary Tree](./0226-Invert-Binary-Tree) – Swap left/right children, fundamental tree mutation.

---

## 🪟 Level 2: Comparison & Validation

**The Focus**: Comparing nodes and validating structure.

* [98. Validate Binary Search Tree](./0098-Validate-Binary-Search-Tree) – BST property checks with bounds.
* [100. Same Tree](./0100-Same-Tree) – Structural and value equality.
* [110. Balanced Binary Tree](./0110-Balanced-Binary-Tree) – Height balance check using DFS.

---

## 🔁 Level 3: Construction

**The Focus**: Building trees from sequences.

* [105. Construct Binary Tree from Preorder and Inorder Traversal](./0105-Construct-Binary-Tree-from-Preorder-and-Inorder-Traversal) – Recursive building using maps.
* [235. Lowest Common Ancestor of a Binary Search Tree](./0235-Lowest-Common-Ancestor-of-a-Binary-Search-Tree) – Leveraging BST properties.

---

## 🧠 Level 4: Traversals & Views

**The Focus**: BFS/DFS variations and outputting views.

* [102. Binary Tree Level Order Traversal](./0102-Binary-Tree-Level-Order-Traversal) – Classic BFS with queue.
* [199. Binary Tree Right Side View](./0199-Binary-Tree-Right-Side-View) – Track last node at each level.
* [230. Kth Smallest Element in a BST](./0230-Kth-Smallest-Element-in-a-BST) – Inorder traversal for ordered retrieval.

---

## 🧪 Level 5: Path & Diameter Analysis

**The Focus**: Aggregating paths, diameters, and sums.

* [124. Binary Tree Maximum Path Sum](./0124-Binary-Tree-Maximum-Path-Sum) – DFS + max path tracking, handles negative nodes.
* [543. Diameter of Binary Tree](./0543-Diameter-of-Binary-Tree) – Max path length between two nodes.

---

## 🧬 Level 6: Subtree & Good Nodes

**The Focus**: Detecting subtrees, node conditions, and BST properties.

* [572. Subtree of Another Tree](./0572-Subtree-of-Another-Tree) – Structural matching.
* [1448. Count Good Nodes in Binary Tree](./1448-Count-Good-Nodes-in-Binary-Tree) – DFS with running max.
* [98. Validate Binary Search Tree](./0098-Validate-Binary-Search-Tree) – Revisited for BST constraints.

---

## 🔄 Level 7: Serialization & Advanced Operations

**The Focus**: Reconstructing trees and encoding/decoding.

* [297. Serialize and Deserialize Binary Tree](./0297-Serialize-and-Deserialize-Binary-Tree) – Preorder DFS with `#` markers.

---

## 🛠️ Core Templates

### DFS Max Depth / Height

```cpp
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
DFS with Path Tracking (Diameter / Max Path Sum)
int dfs(TreeNode* node, int &global) {
    if (!node) return 0;
    int left = max(0, dfs(node->left, global));
    int right = max(0, dfs(node->right, global));
    global = max(global, node->val + left + right);
    return node->val + max(left, right);
}
BFS Level Order
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front(); q.pop();
            temp.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ans.push_back(temp);
    }
    return ans;
}
🎯 Learning Path Recommendations
Level 1 & 2 – Build mechanical accuracy and BST intuition.

Level 3 – Understand construction from traversals; key for coding interviews.

Level 4 – Master BFS/DFS traversals; right-side view & level order are essential.

Level 5 – Practice paths, diameters, and max sum problems.

Level 6 & 7 – Subtree detection, BST validation, and serialization for advanced operations.

🔥 Common Mistakes to Avoid
Off-by-one in DFS/BFS indexing

Forgetting null checks

Mismanaging global variables in DFS (e.g., diameter or max path sum)

Confusing inorder with preorder/postorder during tree reconstruction

Failing to handle negative values in max path sum

📁 Repository Structure
Binary Tree/
├── 0098-Validate-Binary-Search-Tree/
│   └── 0098-Validate-Binary-Search-Tree.cpp
├── 0100-Same-Tree/
│   └── 0100-Same-Tree.cpp
├── 0102-Binary-Tree-Level-Order-Traversal/
│   └── 0102-Binary-Tree-Level-Order-Traversal.cpp
├── 0104-Maximum-Depth-of-Binary-Tree/
│   └── 0104-Maximum-Depth-of-Binary-Tree.cpp
├── 0105-Construct-Binary-Tree-from-Preorder-and-Inorder-Traversal/
│   └── 0105-Construct-Binary-Tree-from-Preorder-and-Inorder-Traversal.cpp
├── 0110-Balanced-Binary-Tree/
│   └── 0110-Balanced-Binary-Tree.cpp
├── 0124-Binary-Tree-Maximum-Path-Sum/
│   └── 0124-Binary-Tree-Maximum-Path-Sum.cpp
├── 0199-Binary-Tree-Right-Side-View/
│   └── 0199-Binary-Tree-Right-Side-View.cpp
├── 0226-Invert-Binary-Tree/
│   └── 0226-Invert-Binary-Tree.cpp
├── 0230-Kth-Smallest-Element-in-a-BST/
│   └── 0230-Kth-Smallest-Element-in-a-BST.cpp
├── 0235-Lowest-Common-Ancestor-of-a-BST/
│   └── 0235-Lowest-Common-Ancestor-of-a-BST.cpp
├── 0297-Serialize-and-Deserialize-Binary-Tree/
│   └── 0297-Serialize-and-Deserialize-Binary-Tree.cpp
├── 0543-Diameter-of-Binary-Tree/
│   └── 0543-Diameter-of-Binary-Tree.cpp
├── 0572-Subtree-of-Another-Tree/
│   └── 0572-Subtree-of-Another-Tree.cpp
├── 1448-Count-Good-Nodes-in-Binary-Tree/
│   └── 1448-Count-Good-Nodes-in-Binary-Tree.cpp
└── README.md
