# 110. Balanced Binary Tree

**Problem Link:** [LeetCode – Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

---

## 🧩 Problem Description

Given a binary tree, determine if it is height-balanced.

A height-balanced binary tree is defined as:
For every node in the tree, the height difference between its left
and right subtrees is at most 1.

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
true

---

### Example 2

Input:
    1
   / \
  2   2
 / \
3   3
/ \
4   4

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

A tree is balanced if:
- Both subtrees are balanced
- The difference in their heights is at most 1

Checking balance and height separately is inefficient.

Instead, we compute height while checking balance in **one DFS pass**.

---

## 🔍 Approach (DFS with Early Exit)

We use DFS that returns:
- Height of the subtree if it is balanced
- `-1` if the subtree is not balanced

Steps:
1. Recursively compute left subtree height
   - If unbalanced, propagate `-1`
2. Recursively compute right subtree height
   - If unbalanced, propagate `-1`
3. If height difference > 1, return `-1`
4. Otherwise, return `1 + max(left, right)`

The tree is balanced if the final result is not `-1`.

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n)
  Each node is visited once.

- Space Complexity: O(h)
  Recursion stack where h is the height of the tree.
  Worst case O(n) for a skewed tree.

---

## 🚨 Common Mistakes

- Computing height repeatedly (O(n²) solution)
- Checking balance only at the root
- Forgetting early termination
- Confusing balanced tree with complete tree

---

## ✅ Final Takeaway

This problem is about **efficiency and discipline**.

If you:
- Compute height separately
- Ignore early exits

You fail performance-wise.

Your solution avoids all of that.
It’s optimal, clean, and interview-correct.
