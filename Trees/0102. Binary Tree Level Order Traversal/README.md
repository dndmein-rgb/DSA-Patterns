# 102. Binary Tree Level Order Traversal

**Problem Link:** [LeetCode – Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

---

## 🧩 Problem Description

Given the root of a binary tree, return the level order traversal
of its nodes' values. (i.e., from left to right, level by level).

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
[
  [3],
  [9,20],
  [15,7]
]

---

### Example 2

Input:
root = []

Output:
[]

---

### Example 3

Input:
root = [1]

Output:
[[1]]

---

## 🧠 Core Idea

Level-order traversal is a **Breadth-First Search (BFS)** problem:

- Traverse nodes level by level
- Collect nodes of each level separately

Queue is the natural data structure for BFS.

---

## 🔍 Approach (BFS)

1. Initialize an empty queue and push the root
2. While the queue is not empty:
   - Determine the number of nodes at the current level
   - Pop each node, store its value
   - Push non-null children into the queue
3. Append the collected values of the level to the answer
4. Repeat until all levels are traversed

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n)
  Each node is visited exactly once.

- Space Complexity: O(n)
  Queue can hold up to the largest level of the tree.

---

## 🚨 Common Mistakes

- Forgetting to push children in the correct order
- Using DFS instead of BFS and returning levels incorrectly
- Not handling empty tree (`root = nullptr`)
- Mixing up level separation

---

## ✅ Final Takeaway

Level-order traversal is literally BFS with bookkeeping per level.

Your code:
- Uses a queue
- Processes each level
- Collects values
- Handles empty trees

It’s clean, optimal, and interview-ready.
