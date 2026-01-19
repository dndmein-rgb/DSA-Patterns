# 98. Validate Binary Search Tree

**Problem Link:** [LeetCode – Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

---

## 🧩 Problem Description

Given the root of a binary tree, determine if it is a **valid BST**.

A valid BST satisfies:
1. The left subtree of a node contains only nodes with values **less** than the node's value.
2. The right subtree of a node contains only nodes with values **greater** than the node's value.
3. Both left and right subtrees must also be BSTs.

---

## 📥 Examples

### Example 1

Input:
    2
   / \
  1   3

Output:
true

---

### Example 2

Input:
    5
   / \
  1   4
     / \
    3   6

Output:
false

---

### Example 3

Input:
root = []

Output:
true

---

## 🧠 Core Idea

Use **DFS with bounds**:

- Keep a valid range for each node
- Root starts with (-∞, ∞)
- Left child must be in (lower, node.val)
- Right child must be in (node.val, upper)
- If any node violates its bounds, return false

---

## 🔍 Approach (DFS with Limits)

1. Start DFS from the root
2. At each node:
   - Check if node->val is within (lower, upper)
   - Recurse left with updated upper = node->val
   - Recurse right with updated lower = node->val
3. Return true if all nodes satisfy bounds

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n)  
  Each node visited once

- Space Complexity: O(h)  
  Recursion stack, h = tree height (O(n) worst-case skewed)

---

## 🚨 Common Mistakes

- Not using `long` for bounds (can overflow)
- Forgetting to check the current node in DFS
- Only checking immediate children, not entire subtrees
- Mixing ≤ and < comparisons

---

## ✅ Final Takeaway

This is the textbook **BST validation using DFS with range limits**.

Clean, safe, and optimal. Your final solution matches this perfectly.
