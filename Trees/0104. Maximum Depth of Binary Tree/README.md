# 104. Maximum Depth of Binary Tree

**Problem Link:** [LeetCode – Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

---

## 🧩 Problem Description

Given the root of a binary tree, return its maximum depth.

The maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.

---

## 📥 Examples

### Example 1

Input:
    3
   / \
  9  20
     / \
    15  7

Output:
3

---

### Example 2

Input:
    1
     \
      2

Output:
2

---

### Example 3

Input:
root = []

Output:
0

---

## 🧠 Core Idea

The depth of a binary tree is defined recursively.

- An empty tree has depth 0
- A non-empty tree has depth:
  1 + maximum depth of its left or right subtree

This definition maps directly to a DFS solution.

---

## 🔍 Approach (DFS)

1. If the current node is null, return 0
2. Recursively compute depth of left subtree
3. Recursively compute depth of right subtree
4. Return 1 + max(left, right)

Each node contributes exactly once to the depth calculation.

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n)
  Each node is visited once.

- Space Complexity: O(h)
  Where h is the height of the tree due to recursion stack.
  Worst case O(n) for a skewed tree.

---

## 🚨 Common Mistakes

- Returning 1 for a null node
- Forgetting the base case
- Confusing depth with number of edges instead of nodes

---

## ✅ Final Takeaway

This problem tests basic tree recursion.

If this feels difficult, the issue is not binary trees.
It is lack of comfort with recursive definitions.
