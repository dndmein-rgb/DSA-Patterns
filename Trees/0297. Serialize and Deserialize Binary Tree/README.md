# 297. Serialize and Deserialize Binary Tree

**Problem Link:** [LeetCode – Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

---

## 🧩 Problem Description

Design an algorithm to **serialize** and **deserialize** a binary tree.

- **Serialization**: Convert a tree to a string.
- **Deserialization**: Convert a string back to the original tree structure.

You can use **preorder traversal** and any marker (like `#`) for null nodes.

---

## 📥 Examples

### Example 1

Input:
    1
   / \
  2   3
     / \
    4   5

Serialization Output:
"1,2,#,#,3,4,#,#,5,#,#,"

---

### Example 2

Input: root = []

Serialization Output:
"#,"

---

## 🧠 Core Idea

- Use **preorder traversal**.
- Encode `null` nodes as `#`.
- During deserialization, recursively rebuild the tree by reading nodes from the string.

---

## 🔍 Approach (DFS Preorder)

1. Serialize:
   - Preorder DFS
   - Append `val,` for nodes, `#,` for nulls
2. Deserialize:
   - Read string index by index
   - If `#`, return null
   - Otherwise, create node
   - Recursively build left and right subtrees
3. Ensure negative numbers are handled correctly

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n)
  - Each node visited once for serialize and deserialize
- Space Complexity: O(n)
  - Output string + recursion stack

---

## 🚨 Common Mistakes

- Forgetting to handle negative numbers
- Using inorder or postorder instead of preorder
- Not incrementing index properly after reading node or `#`
- Ignoring null nodes in serialization

---

## ✅ Final Takeaway

Preorder + null markers = standard approach for tree serialization.  
DFS recursion makes it clean and reversible.
