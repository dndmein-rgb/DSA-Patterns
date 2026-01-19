# 124. Binary Tree Maximum Path Sum

**Problem Link:** [LeetCode – Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

---

## 🧩 Problem Description

Given a non-empty binary tree, find the **maximum path sum**.

A **path** is any sequence of nodes from some starting node to any node in the tree
along the parent-child connections. The path **must contain at least one node** and
does not need to go through the root.

---

## 📥 Examples

### Example 1

Input:
    1
   / \
  2   3

Output:
6

Explanation:
Max path = 2 → 1 → 3

---

### Example 2

Input:
    -10
     / \
    9  20
       / \
      15  7

Output:
42

Explanation:
Max path = 15 → 20 → 7

---

## 🧠 Core Idea

At each node, the **maximum path sum that passes through** it is:

`node->val + max(0, left) + max(0, right)`

- Take max with 0 to ignore negative contributions
- Update a global `maxSum`
- Return `node->val + max(left, right)` to parent
  (because path cannot branch upwards)

---

## 🔍 Approach (DFS)

1. Initialize `maxSum = INT_MIN`
2. DFS recursively:
   - Compute left and right max path sums
   - Ignore negatives with `max(0, ...)`
   - Update `maxSum` with `node->val + left + right`
   - Return `node->val + max(left, right)`
3. Return `maxSum` after traversal

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n)  
  Each node visited once

- Space Complexity: O(h)  
  Recursion stack, h = tree height. O(n) worst-case skewed

---

## 🚨 Common Mistakes

- Forgetting `max(0, ...)` for negative children
- Returning sum of both children to parent (cannot branch)
- Not initializing `maxSum = INT_MIN`
- Misinterpreting path definition

---

## ✅ Final Takeaway

DFS + tracking global max = textbook solution.

Handles negative values and arbitrary paths efficiently.
