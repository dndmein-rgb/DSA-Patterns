# 199. Binary Tree Right Side View

**Problem Link:** [LeetCode – Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)

---

## 🧩 Problem Description

Given the root of a binary tree, imagine yourself standing on the right side
of it. Return the values of the nodes you can see ordered from top to bottom.

---

## 📥 Examples

### Example 1

Input:
    1
   / \
  2   3
   \   \
    5   4

Output:
[1,3,4]

---

### Example 2

Input:
root = [1,null,3]

Output:
[1,3]

---

### Example 3

Input:
root = []

Output:
[]

---

## 🧠 Core Idea

The "right side view" is essentially:
- **The last node at each level** of the tree

This makes BFS (level-order traversal) the natural choice.

---

## 🔍 Approach (BFS)

1. Initialize a queue and push the root
2. While the queue is not empty:
   - Get the number of nodes at the current level
   - Traverse all nodes at this level
   - Record the **last node’s value** into the answer
   - Push non-null children into the queue
3. Continue until all levels are processed

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n)
  Each node is visited exactly once

- Space Complexity: O(n)
  Queue may hold up to the largest level

---

## 🚨 Common Mistakes

- Taking the first node instead of the last
- Using DFS without level tracking
- Forgetting to handle an empty tree
- Mixing left and right order when pushing children

---

## ✅ Final Takeaway

BFS + level bookkeeping = simplest and cleanest solution.

Your code:
- Handles empty trees
- Tracks levels
- Pushes children in correct order
- Collects only rightmost nodes

Optimal and interview-ready.
